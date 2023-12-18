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
      nbClientInSalon(0)
{
    // TODO
}

/********************************************
 * Méthodes de l'interface pour les clients *
 *******************************************/
bool PcoSalon::accessSalon(unsigned clientId)
{
    _mutex.lock();
    if (nbClientInSalon + 1 <= capacity + 1){
        ++nbClientInSalon;

        listCustomers.push_back(clientId);
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

    while (workingChairBusy || listCustomers.at(0) != clientId){

        _interface->consoleAppendTextClient(clientId, "je vais attendre");

        for (; noWaitingChair < 2 ; ++noWaitingChair){
            if (waitingChairsBusy[noWaitingChair] == false){

                waitingChairsBusy[noWaitingChair] = true;
                animationClientSitOnChair(clientId, noWaitingChair);
                break;
            }
        }
        conditionClient.wait(&_mutex);
        waitingChairsBusy[noWaitingChair] = false;
    }

    listCustomers.erase(listCustomers.begin());
    _interface->consoleAppendTextClient(clientId, "je vais sur la chaise ");
    workingChairBusy = true;

    if (barberIsSleeping){
        //si le barbier dort on le réveille
        animationWakeUpBarber();
        conditionBarbder.notifyOne();////////////////////////////////////////
    }

    animationClientSitOnWorkChair(clientId);
    conditionBarbder.notifyOne();/////////////////////
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
    --nbClientInSalon;
    conditionBarbder.notifyOne();////////////////////////////////////
    _interface->consoleAppendTextClient(clientId, "je rentre à la maison");

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
    barberIsSleeping = true;
    animationBarberGoToSleep();
    conditionBarbder.wait(&_mutex);
    barberIsSleeping = false;

    _mutex.unlock();
    // TODO
}


void PcoSalon::pickNextClient()
{
    _mutex.lock();
    _interface->consoleAppendTextBarber("je prend le prochain client");
    conditionClient.notifyAll();/////////////le prochain prioritaire///////////////
    // TODO
    _mutex.unlock();
}


void PcoSalon::waitClientAtChair()
{
    _mutex.lock();
    _interface->consoleAppendTextBarber("attente du client à la chaise");
    conditionBarbder.wait(&_mutex);

    _mutex.unlock();
    // TODO
}


void PcoSalon::beautifyClient()
{
    _mutex.lock();
    _interface->consoleAppendTextBarber("start coupe de cheveu");
    animationBarberCuttingHair();
    conditionClient.notifyAll();///////////////////////////////////
    conditionBarbder.wait(&_mutex);
    _interface->consoleAppendTextBarber("chaise libre");
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
    _mutex.unlock();
    _interface->consoleAppendTextBarber("FIN DU SERVICE DEMANDEE");
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
