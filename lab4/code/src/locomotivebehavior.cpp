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


        while (locoActuel == 1){ //loco bleue
            if (PcoThread::thisThread()->stopRequested()){
                loco.arreter();
                return;
            }
            attendre_contact(25);
            sharedSection->access(loco);

            attendre_contact(16);
            afficher_message(qPrintable(QString("APRES CONTACT 16 %1 .").arg(loco.numero())));

            diriger_aiguillage(8, !devie, 0);

            attendre_contact(15);
            sharedSection->leave(loco);

            sharedSection->stopAtStation(this->loco);


        }
        while (locoActuel == 0) {
            if (PcoThread::thisThread()->stopRequested()){
                loco.arreter();
                return;
            }

            attendre_contact(22);
            sharedSection->access(loco);


            attendre_contact(16);
            afficher_message(qPrintable(QString("APRES CONTACT 16 %1 .").arg(loco.numero())));

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
