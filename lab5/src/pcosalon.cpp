/*  _____   _____ ____    ___   ___ ___  ____
 * |  __ \ / ____/ __ \  |__ \ / _ \__ \|___ \
 * | |__) | |   | |  | |    ) | | | | ) | __) |
 * |  ___/| |   | |  | |   / /| | | |/ / |__ <
 * | |    | |___| |__| |  / /_| |_| / /_ ___) |
 * |_|     \_____\____/  |____|\___/____|____/
 */
// Modifications à faire dans le fichier

#include "pcosalon.h"

#include <pcosynchro/pcothread.h>

#include <iostream>
#include <algorithm>

PcoSalon::PcoSalon(GraphicSalonInterface *interface, unsigned int capacity)
    : _interface(interface), capacity(capacity),
      nbClientInSalon(0),
      barberIsSleeping(true),
      workingChairBusy(false),
      requestCloseService(false)
{
    for (auto w : waitingChairsBusy){
        w = false;
    }
    listCustomersInQueue = {};
    // TODO
}

/********************************************
 * Méthodes de l'interface pour les clients *
 *******************************************/
bool PcoSalon::accessSalon(unsigned clientId)
{
    _mutex.lock();
    //Le client essaie d'entrer
    if (nbClientInSalon + 1 <= capacity + 1){
        ++nbClientInSalon;                      
        //si le client entre, on le met dans la queue
        listCustomersInQueue.push_back(clientId);
        animationClientAccessEntrance(clientId);
        _mutex.unlock();
        return true;
    }
    _mutex.unlock();
    return false;
    // TODO
}


void PcoSalon::goForHairCut(unsigned clientId)
{
    _mutex.lock();
    int noWaitingChair = 0;
    while (workingChairBusy || listCustomersInQueue.at(0) != clientId){
    //Si on est PAS le prochain sur la liste ou que la place est occupée
    //alors on attend son tour
    //_interface->consoleAppendTextClient(clientId, "je vais attendre");

        for (; noWaitingChair < NB_SIEGES ; ++noWaitingChair){
        //on cherche une chaise libre pour attendre
            if (waitingChairsBusy[noWaitingChair] == false){
                waitingChairsBusy[noWaitingChair] = true;
                animationClientSitOnChair(clientId, noWaitingChair);
                break;
            }
        }
        conditionClient.wait(&_mutex);
        //Si on se lève, on libère la chaise.
        waitingChairsBusy[noWaitingChair] = false;
    }
    //_interface->consoleAppendTextClient(clientId, "je vais sur la chaise ");
    //Si c'est notre tour alors on occupe la chaise de travail
    //et on se retire de la file d'attente.
    workingChairBusy = true;
    listCustomersInQueue.erase(listCustomersInQueue.begin());

    //Si le barber dort, on le réveille
    if (barberIsSleeping){
        conditionBarbder.notifyOne();
    }
    animationClientSitOnWorkChair(clientId);

    //Dire au barbier qu'on est sur la chaise...
    //et prêt à avoir le crâne taillé...
    conditionBarbder.notifyOne();

    //On attend que le barbier ait fini son travail
    conditionClient.wait(&_mutex);
    _mutex.unlock();
    // TODO
}

void PcoSalon::waitingForHairToGrow(unsigned clientId)
{
    _mutex.lock();
    animationClientWaitForHairToGrow(clientId);
    _mutex.unlock();
    // TODO
}


void PcoSalon::walkAround(unsigned clientId)
{
    _mutex.lock();
    animationClientWalkAround(clientId);
    _mutex.unlock();
    // TODO
}


void PcoSalon::goHome(unsigned clientId){
    // TODO
    _mutex.lock();
    animationClientGoHome(clientId);
    //Si on quitte le salon on met à jour le nombre de clients dans le salon
    --nbClientInSalon;
    //Avertir le barbier qu'on est parti
    conditionBarbder.notifyOne();////////////////////////////////////
    //_interface->consoleAppendTextClient(clientId, "je rentre à la maison");
    _mutex.unlock();
}


/********************************************
 * Méthodes de l'interface pour le barbier  *
 *******************************************/
unsigned int PcoSalon::getNbClient()
{
    return nbClientInSalon;
    // TODO
}

void PcoSalon::goToSleep()
{
    _mutex.lock();
    //Le barbier part dormir et attend un client
    barberIsSleeping = true;
    animationBarberGoToSleep();
    conditionBarbder.wait(&_mutex);
    //Le barbier se fait réveiller mettre à jour son état
    barberIsSleeping = false;
    animationWakeUpBarber();

    _mutex.unlock();
    // TODO
}


void PcoSalon::pickNextClient()
{
    _mutex.lock();
    //_interface->consoleAppendTextBarber("je prend le prochain client");
    //Inviter le prochain client prioritaire
    conditionClient.notifyAll();
    _mutex.unlock();
}


void PcoSalon::waitClientAtChair()
{
    _mutex.lock();
    //_interface->consoleAppendTextBarber("attente du client à la chaise");
    conditionBarbder.wait(&_mutex);
    _mutex.unlock();
    // TODO
}


void PcoSalon::beautifyClient()
{
    _mutex.lock();
    //_interface->consoleAppendTextBarber("start coupe de cheveu");
    animationBarberCuttingHair();
    //Avertir le client que le travail est fini
    conditionClient.notifyAll();
    //Attendre que le client quitte le salon
    conditionBarbder.wait(&_mutex);
    //_interface->consoleAppendTextBarber("chaise libre");
    workingChairBusy = false;
    // TODO
    _mutex.unlock();
}

/********************************************
 *    Méthodes générales de l'interface     *
 *******************************************/
bool PcoSalon::isInService()
{
    return !requestCloseService;
    // TODO
}


void PcoSalon::endService()
{
    _mutex.lock();
    requestCloseService = true;
    if (barberIsSleeping)
        conditionBarbder.notifyOne();
    _mutex.unlock();
    //_interface->consoleAppendTextBarber("FIN DU SERVICE DEMANDEE");
    // TOD
}

/********************************************
 *   Méthodes privées pour les animations   *
 *******************************************/
void PcoSalon::animationClientAccessEntrance(unsigned clientId)
{
    _mutex.unlock();
    _interface->clientAccessEntrance(clientId);
    _mutex.lock();
}

void PcoSalon::animationClientSitOnChair(unsigned clientId, unsigned clientSitNb)
{
    _mutex.unlock();
    _interface->clientSitOnChair(clientId, clientSitNb);
    _mutex.lock();
}

void PcoSalon::animationClientSitOnWorkChair(unsigned clientId)
{
    _mutex.unlock();
    _interface->clientSitOnWorkChair(clientId);
    _mutex.lock();
}

void PcoSalon::animationClientWaitForHairToGrow(unsigned clientId)
{
    _mutex.unlock();
    _interface->clientWaitHairToGrow(clientId, true);
    _mutex.lock();
}

void PcoSalon::animationClientWalkAround(unsigned clientId)
{
    _mutex.unlock();
    _interface->clientWalkAround(clientId);
    _mutex.lock();
}

void PcoSalon::animationBarberGoToSleep()
{
    _mutex.unlock();
    _interface->barberGoToSleep();
    _mutex.lock();
}

void PcoSalon::animationWakeUpBarber()
{
    _mutex.unlock();
    _interface->clientWakeUpBarber();
    _mutex.lock();
}

void PcoSalon::animationBarberCuttingHair()
{
    _mutex.unlock();
    _interface->barberCuttingHair();
    _mutex.lock();
}

void PcoSalon::animationClientGoHome(unsigned clientId){
    _mutex.unlock();
    _interface->clientWaitHairToGrow(clientId, false);
    _mutex.lock();
}
