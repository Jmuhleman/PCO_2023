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

    //priorité pour la sortie de gare
    loco.priority = 1;
    while(true){
            if (PcoThread::thisThread()->stopRequested()){
                loco.arreter();
                return;
            }
            attendre_contact(parcours.at(0));
            sharedSection->stopAtStation(loco);

            attendre_contact(parcours.at(1));
            sharedSection->access(loco);

            attendre_contact(parcours.at(2));
            //puisque le numéro de la loco correspond à l'inverse de sa direction hehe ;)
            diriger_aiguillage(8, !loco.numero(), 0);

            attendre_contact(parcours.at(3));
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
