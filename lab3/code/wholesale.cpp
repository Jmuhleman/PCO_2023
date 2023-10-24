#include "wholesale.h"
#include "factory.h"
#include "costs.h"
#include <iostream>
#include <pcosynchro/pcothread.h>
#include <algorithm>

WindowInterface* Wholesale::interface = nullptr;

Wholesale::Wholesale(int uniqueId, int fund)
    : Seller(fund, uniqueId)
{
    interface->updateFund(uniqueId, fund);
    interface->consoleAppendText(uniqueId, "Wholesaler Created");

}

void Wholesale::setSellers(std::vector<Seller*> sellers) {
    this->sellers = sellers;

    for(Seller* seller: sellers){
        interface->setLink(uniqueId, seller->getUniqueId());
    }
}

void Wholesale::buyResources() {
    auto s = Seller::chooseRandomSeller(sellers);
    auto m = s->getItemsForSale();
    auto i = Seller::chooseRandomItem(m);

    if (i == ItemType::Nothing) {
        /* Nothing to buy... */
        return;
    }

    int qty = rand() % 5 + 1;
    int price = qty * getCostPerUnit(i);

    interface->consoleAppendText(uniqueId, QString("I would like to buy %1 of ").arg(qty) %
                                 getItemName(i) % QString(" which would cost me %1").arg(price));
    /* TODO */

    if (money < price){
        //Si on est trop pauvre pour acheter => retour dans la boucle
        //On attend que quelqu'un nous achète quelque-chose pour avoir
        //des fonds.
        return;
    }
    //On place un ordre d'achat chez le seller choisi.
    if (s->trade(i, qty)){
        //Si l'achat se conclut, on met à jour les stocks.
        money -= price;
        stocks[i] += qty;
    }

}

void Wholesale::run() {

    if (sellers.empty()) {
        std::cerr << "You have to give factories and mines to a wholeseler before launching is routine" << std::endl;
        return;
    }

    interface->consoleAppendText(uniqueId, "[START] Wholesaler routine");
    while (!PcoThread::thisThread()->stopRequested()) {
        buyResources();
        interface->updateFund(uniqueId, money);
        interface->updateStock(uniqueId, &stocks);
        //Temps de pause pour espacer les demandes de ressources
        PcoThread::usleep((rand() % 10 + 1) * 100000);
    }
    interface->consoleAppendText(uniqueId, "[STOP] Wholesaler routine");


}

std::map<ItemType, int> Wholesale::getItemsForSale() {
    return stocks;
}

int Wholesale::trade(ItemType it, int qty) {

    // TODO
    //Vérification des paramètres
    if (std::find_if(stocks.begin(), stocks.end(),
                     [=](const std::pair<ItemType, int>& k)->bool
                                     {return k.first == it;}) == stocks.end()
                                                    || qty <= 0 || stocks[it] < qty){
        return 0;
    }
    //MAJ des stocks du vendeur.
    stocks[it] -= qty;
    money += getCostPerUnit(it) * qty;
    return getCostPerUnit(it) * qty;

}

void Wholesale::setInterface(WindowInterface *windowInterface) {
    interface = windowInterface;
}
