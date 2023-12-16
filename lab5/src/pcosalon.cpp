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

PcoSalon::PcoSalon(GraphicSalonInterface *interface, unsigned int capacity)
    : _interface(interface), capacity(capacity),
      ncClientInSalon(0),
      barberIsWorking(false)
{
    // TODO
}

/********************************************
 * Méthodes de l'interface pour les clients *
 *******************************************/
bool PcoSalon::accessSalon(unsigned clientId)
{
    _mutex.lock();

    if (ncClientInSalon  + 1 <= capacity+1){
        ++ncClientInSalon;

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
    _interface->consoleAppendTextClient(clientId, "je peux rentrer");

    while (barberIsWorking){

        //si le barber est en train de travailler
        //si on arrive la c'est que la capacité du salon le permet
        _interface->consoleAppendTextClient(clientId, "je dois aller attendre sur une chaise");
        if (ncClientInSalon > 0){
            for (int k = 0 ; k < 2 ; ++k){
                if (waitingChairsBusy[k] == false){
                    waitingChairsBusy[k] = true;
                    animationClientSitOnChair(clientId, k);
                    break;
                }
            }
            condition.wait(&_mutex);
        }

    }
    //si le barbier ne fait rien, alors donc on peut aller direct
    //sur le siège sans attendre
    barberIsWorking = true;
    workingChairBusy = true;
    ++ncClientInSalon;

    animationWakeUpBarber();
    condition.notifyAll();

    animationClientSitOnWorkChair(clientId);
    hasSitOnChair = true;
    condition.notifyAll();


    --ncClientInSalon;


    while (!hasFinishedHaircut)
    {
        _interface->consoleAppendTextClient(clientId, "attente coupe de chveu finit");
        condition.wait(&_mutex);
    }
    hasFinishedHaircut = false;
    _interface->consoleAppendTextClient(clientId, "attente coupe de chveu terminé!!!!");


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
    hasGoneHome = true;
    condition.notifyAll();
    --ncClientInSalon;
    _mutex.unlock();
}


/********************************************
 * Méthodes de l'interface pour le barbier  *
 *******************************************/
unsigned int PcoSalon::getNbClient()
{
    return ncClientInSalon;
    // TODO
}

void PcoSalon::goToSleep()
{
    _mutex.lock();
    while (ncClientInSalon == 0){
        animationBarberGoToSleep();
        condition.wait(&_mutex);
    }

    _mutex.unlock();
    // TODO
}


void PcoSalon::pickNextClient()
{
    _mutex.lock();
    condition.notifyAll();
    // TODO
    _mutex.unlock();
}


void PcoSalon::waitClientAtChair()
{
    _mutex.lock();
    while (!hasSitOnChair){
        _interface->consoleAppendTextBarber("invitation du client");
        condition.wait(&_mutex);
    }
    hasSitOnChair = false;
    _interface->consoleAppendTextBarber("fin invitation client");

    _mutex.unlock();
    // TODO
}


void PcoSalon::beautifyClient()
{
    _mutex.lock();
    _interface->consoleAppendTextBarber("start coupe de cheveux");

    animationBarberCuttingHair();
    hasFinishedHaircut = true;
    condition.notifyAll();

    _interface->consoleAppendTextBarber("start attente client rentre");

    while (!hasGoneHome){
        condition.wait(&_mutex);
    }
    //quand le client est parti le barbier ne travaille plus
    //et la chaise est libre
    workingChairBusy = false;
    barberIsWorking = false;
    hasGoneHome = false;
    // TODO
    _mutex.unlock();
}

/********************************************
 *    Méthodes générales de l'interface     *
 *******************************************/
bool PcoSalon::isInService()
{
    return requestCloseService;
    // TODO
}


void PcoSalon::endService()
{
    _mutex.lock();
    requestCloseService = true;
    // TODO
    _mutex.unlock();
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
