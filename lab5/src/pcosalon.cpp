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

#include <algorithm>

PcoSalon::PcoSalon(GraphicSalonInterface *interface, unsigned int capacity)
	: _interface(interface), capacity(capacity),
	  requestCloseService(false),
	  waitingChairIndex(0) {
}

/********************************************
 * Méthodes de l'interface pour les clients *
 *******************************************/
bool PcoSalon::accessSalon(unsigned clientId) {

	_mutex.lock();
	if (customerQueue.size() > capacity) {
		_mutex.unlock();
		_interface->consoleAppendTextClient(clientId, "je peux pas entrer");
		return false;
	}
	customerQueue.push(clientId);
	animationClientAccessEntrance(clientId);
	conditionBarber.notifyOne();

	if (customerQueue.front() != clientId) {
		_interface->consoleAppendTextClient(clientId, "je vais attendre");
		animationClientSitOnChair(clientId, waitingChairIndex++);
		if (waitingChairIndex >= capacity)
			waitingChairIndex = 0;
	}
	_mutex.unlock();
	return true;
}


void PcoSalon::goForHairCut(unsigned clientId) {
	_mutex.lock();
	while (customerQueue.front() != clientId) {
		condWaitingChair.wait(&_mutex);
	}
	_interface->consoleAppendTextClient(clientId, "je vais à la chaise");

	//_interface->consoleAppendTextClient(clientId, "je vais sur la chaise ");
	animationClientSitOnWorkChair(clientId);
	//Dire au barbier qu'on est sur la chaise...
	condHasSit.notifyOne();
	//On attend que le barbier ait fini son travail
	conditionClient.wait(&_mutex);
	_mutex.unlock();
}

void PcoSalon::waitingForHairToGrow(unsigned clientId) {
	_mutex.lock();
	animationClientWaitForHairToGrow(clientId);
	_mutex.unlock();
}


void PcoSalon::walkAround(unsigned clientId) {
	_mutex.lock();
	animationClientWalkAround(clientId);
	_mutex.unlock();
}


void PcoSalon::goHome(unsigned clientId) {
	//_interface->consoleAppendTextClient(clientId, "je suis rentré à la maison");
	_mutex.lock();
	animationClientGoHome(clientId);
	_mutex.unlock();
}


/********************************************
 * Méthodes de l'interface pour le barbier  *
 *******************************************/
unsigned int PcoSalon::getNbClient() {
	_mutex.lock();
	const size_t ret = customerQueue.size();
	_mutex.unlock();
	return ret;
}

void PcoSalon::goToSleep() {
	_mutex.lock();
	//Le barbier part dormir et attend un client
	animationBarberGoToSleep();
	conditionBarber.wait(&_mutex);
	//Le barbier se fait réveiller mettre à jour son état
	animationWakeUpBarber();
	_mutex.unlock();
}


void PcoSalon::pickNextClient() {
	_interface->consoleAppendTextBarber("je prend le prochain client");
	_mutex.lock();
	//Inviter le prochain client prioritaire
	condWaitingChair.notifyAll();
	_mutex.unlock();
}


void PcoSalon::waitClientAtChair() {
	_mutex.lock();
	//_interface->consoleAppendTextBarber("attente du client à la chaise");
	condHasSit.wait(&_mutex);
	_mutex.unlock();
}


void PcoSalon::beautifyClient() {
	_mutex.lock();
	//_interface->consoleAppendTextBarber("start coupe de cheveu");
	animationBarberCuttingHair();

	conditionClient.notifyOne();
	customerQueue.pop();

	_mutex.unlock();
	//_interface->consoleAppendTextBarber("fin coupe de cheveu");

}

/********************************************
 *    Méthodes générales de l'interface     *
 *******************************************/
bool PcoSalon::isInService() {
	_mutex.lock();
	const bool ret = !requestCloseService;
	_mutex.unlock();
	return ret;
}


void PcoSalon::endService() {
	_mutex.lock();
	requestCloseService = true;
	conditionBarber.notifyOne();
	_mutex.unlock();
	_interface->consoleAppendTextBarber("FIN DU SERVICE DEMANDEE");
}

/********************************************
 *   Méthodes privées pour les animations   *
 *******************************************/
void PcoSalon::animationClientAccessEntrance(unsigned clientId) {
	_mutex.unlock();
	_interface->clientAccessEntrance(clientId);
	_mutex.lock();
}

void PcoSalon::animationClientSitOnChair(unsigned clientId, unsigned clientSitNb) {
	_mutex.unlock();
	_interface->clientSitOnChair(clientId, clientSitNb);
	_mutex.lock();
}

void PcoSalon::animationClientSitOnWorkChair(unsigned clientId) {
	_mutex.unlock();
	_interface->clientSitOnWorkChair(clientId);
	_mutex.lock();
}

void PcoSalon::animationClientWaitForHairToGrow(unsigned clientId) {
	_mutex.unlock();
	_interface->clientWaitHairToGrow(clientId, true);
	_mutex.lock();
}

void PcoSalon::animationClientWalkAround(unsigned clientId) {
	_mutex.unlock();
	_interface->clientWalkAround(clientId);
	_mutex.lock();
}

void PcoSalon::animationBarberGoToSleep() {
	_mutex.unlock();
	_interface->barberGoToSleep();
	_mutex.lock();
}

void PcoSalon::animationWakeUpBarber() {
	_mutex.unlock();
	_interface->clientWakeUpBarber();
	_mutex.lock();
}

void PcoSalon::animationBarberCuttingHair() {
	_mutex.unlock();
	_interface->barberCuttingHair();
	_mutex.lock();
}

void PcoSalon::animationClientGoHome(unsigned clientId) {
	_mutex.unlock();
	_interface->clientWaitHairToGrow(clientId, false);
	_mutex.lock();
}
