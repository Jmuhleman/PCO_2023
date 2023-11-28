/*  _____   _____ ____    ___   ___ ___  ____
 * |  __ \ / ____/ __ \  |__ \ / _ \__ \|___ \
 * | |__) | |   | |  | |    ) | | | | ) | __) |
 * |  ___/| |   | |  | |   / /| | | |/ / |__ <
 * | |    | |___| |__| |  / /_| |_| / /_ ___) |
 * |_|     \_____\____/  |____|\___/____|____/
 */


#ifndef SYNCHRO_H
#define SYNCHRO_H

#include <QDebug>

#include <pcosynchro/pcosemaphore.h>
#include <pcosynchro/pcothread.h>

#include "locomotive.h"
#include "ctrain_handler.h"
#include "synchrointerface.h"

/**
 * @brief La classe Synchro implémente l'interface SynchroInterface qui
 * propose les méthodes liées à la section partagée.
 */
class Synchro final : public SynchroInterface
{
    /* A vous d'ajouter ce qu'il vous faut */

private:
    // Méthodes privées ...

    // Attribut privés ...
    PcoSemaphore *waitingSecCritique;
    PcoSemaphore *mutexA;
    PcoSemaphore *waitingGare;
    PcoSemaphore *mutexG;
    bool section_busy;
    bool in_queue;
    bool locoIsWaitingInStation;

public:

    /**
     * @brief Synchro Constructeur de la classe qui représente la section partagée.
     * Initialisez vos éventuels attributs ici, sémaphores etc.
     */
    Synchro() {
        // TODO
        waitingSecCritique = new PcoSemaphore{0}; //pour attente en section critique
        waitingGare = new PcoSemaphore{0}; //pour attente en gare
        mutexG = new PcoSemaphore{1}; // protection des données dans stopAtStation
        mutexA = new PcoSemaphore {1}; //protection des données dans access
        locoIsWaitingInStation = false;
        section_busy = false;
        in_queue = false;

    }

    ~Synchro(){
        delete waitingSecCritique;
        delete mutexA;
        delete mutexG;
        delete waitingGare;
    }
    /**
     * @brief access Méthode à appeler pour accéder à la section partagée
     *
     * Elle doit arrêter la locomotive et mettre son thread en attente si nécessaire.
     *
     * @param loco La locomotive qui essaie accéder à la section partagée
     */
    void access(Locomotive &loco) override {
        // TODO
        mutexA->acquire();
        if (!section_busy && loco.priority){
            //si c'est libre et que l'on a le droit d'accéder
            section_busy = true;
            mutexA->release();
        }
        else {//si c'est occupé on attend à l'entrée
            loco.arreter();
            in_queue = true;
            mutexA->release();

            waitingSecCritique->acquire();
            //attente de 2 à 6" avant redémarrage => ne pas faire vomir les passagers
            PcoThread::usleep((rand() % 5 + 2) * 100000);
            loco.demarrer();
        }
    }

    /**
     * @brief leave Méthode à appeler pour indiquer que la locomotive est sortie de la section partagée
     *
     * Réveille les threads des locomotives potentiellement en attente.
     *
     * @param loco La locomotive qui quitte la section partagée
     */
    void leave(Locomotive& loco) override {
        // TODO
        mutexA->acquire();
        section_busy = false;
        if (in_queue){ //Si une loco attend on la laisse entrer
            waitingSecCritique->release();
            in_queue = false;
        }
        mutexA->release();
    }

    /**
     * @brief stopAtStation Méthode à appeler quand la locomotive doit attendre à la gare
     *
     * Implémentez toute la logique que vous avez besoin pour que les locomotives
     * s'attendent correctement.
     *
     * @param loco La locomotive qui doit attendre à la gare
     */
    void stopAtStation(Locomotive& loco) override {
        // TODO
        if (!locoIsWaitingInStation){
            mutexG->acquire();
            locoIsWaitingInStation = true;
            mutexG->release();

            loco.arreter();
            //si on est la première loco à arriver en gare => on attend
            waitingGare->acquire();

            mutexG->acquire();
            locoIsWaitingInStation = false;
            mutexG->release();
            //comme on est premier alors on sera pas prioritaire sur la section critique
            loco.priority = 0;
            loco.demarrer();
        }else{
            //on s'arrête pour laisser le temps au passagers
            loco.arreter();
            PcoThread::usleep(5000000);
            loco.demarrer();

            //débloquer l'autre après 5"
            waitingGare->release();
            //on a la priorité puisque on est deuxième
            loco.priority = 1;
        }
    }


};


#endif // SYNCHRO_H
