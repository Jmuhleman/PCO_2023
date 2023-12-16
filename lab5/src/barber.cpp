/*  _____   _____ ____    ___   ___ ___  ____
 * |  __ \ / ____/ __ \  |__ \ / _ \__ \|___ \
 * | |__) | |   | |  | |    ) | | | | ) | __) |
 * |  ___/| |   | |  | |   / /| | | |/ / |__ <
 * | |    | |___| |__| |  / /_| |_| / /_ ___) |
 * |_|     \_____\____/  |____|\___/____|____/
 */
// Modifications à faire dans le fichier

#include "barber.h"
#include <unistd.h>

#include <iostream>

Barber::Barber(GraphicSalonInterface *interface, std::shared_ptr<SalonBarberInterface> salon)
    : _interface(interface), _salon(salon)
{
    _interface->consoleAppendTextBarber("Salut, prêt à travailler !" + QString(_salon->getNbClient()));
}

void Barber::run()
{
    // TODO
    while(true){

        if (_salon->getNbClient() > 0){

            _salon->pickNextClient();
            _salon->waitClientAtChair();
            _salon->beautifyClient();

        }else{
            //aller dormir
            _salon->goToSleep();
        }


    }

    _interface->consoleAppendTextBarber("La journée est terminée, à demain !");
}