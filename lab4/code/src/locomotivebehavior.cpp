/*  _____   _____ ____    ___   ___ ___  ____
 * |  __ \ / ____/ __ \  |__ \ / _ \__ \|___ \
 * | |__) | |   | |  | |    ) | | | | ) | __) |
 * |  ___/| |   | |  | |   / /| | | |/ / |__ <
 * | |    | |___| |__| |  / /_| |_| / /_ ___) |
 * |_|     \_____\____/  |____|\___/____|____/
 */

#include "locomotivebehavior.h"
#include "ctrain_handler.h"

void LocomotiveBehavior::run()
{
    //Initialisation de la locomotive
    loco.allumerPhares();
    loco.demarrer();
    loco.afficherMessage("Ready!");

    /* A vous de jouer ! */

    // Vous pouvez appeler les méthodes de la section partagée comme ceci :
    //sharedSection->access(loco);
    //sharedSection->leave(loco);
    //sharedSection->stopAtStation(loco);
    bool devie = true;
    int locoActuel = loco.numero();


    loco.priority = 1;

        while (locoActuel == 1){ //loco bleue
            if (PcoThread::thisThread()->stopRequested()){
                loco.arreter();
                return;
            }
            attendre_contact(34);
            sharedSection->stopAtStation(loco);

            attendre_contact(32);
            sharedSection->access(loco);

            attendre_contact(16);
            diriger_aiguillage(8, !devie, 0);

            attendre_contact(15);
            sharedSection->leave(loco);

        }
        while (locoActuel == 0) {
            if (PcoThread::thisThread()->stopRequested()){
                loco.arreter();
                return;
            }
            attendre_contact(30);
            sharedSection->stopAtStation(loco);

            attendre_contact(28);
            sharedSection->access(loco);


            attendre_contact(16);
            diriger_aiguillage(8, devie, 0);

            attendre_contact(15);
            sharedSection->leave(loco);


        }
}

void LocomotiveBehavior::stopRequest(){
    thread->requestStop();
}


void LocomotiveBehavior::printStartMessage()
{
    qDebug() << "[START] Thread de la loco" << loco.numero() << "lancé";
    loco.afficherMessage("Je suis lancée !");
}

void LocomotiveBehavior::printCompletionMessage()
{
    qDebug() << "[STOP] Thread de la loco" << loco.numero() << "a terminé correctement";
    loco.afficherMessage("J'ai terminé");
}
