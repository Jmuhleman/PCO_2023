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
    PcoSemaphore *waiting;
    PcoSemaphore *mutexA;
    PcoSemaphore *mutexL;

    bool section_busy;
    bool in_queue;

public:

    /**
     * @brief Synchro Constructeur de la classe qui représente la section partagée.
     * Initialisez vos éventuels attributs ici, sémaphores etc.
     */
    Synchro() {
        // TODO
        waiting = new PcoSemaphore{0};
        mutexA = new PcoSemaphore {1};
        mutexL = new PcoSemaphore {1};

        section_busy = false;
        in_queue = false;
    }

    ~Synchro(){
        delete waiting;
        delete mutexA;
        delete mutexL;

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
        afficher_message(qPrintable(QString("ENTREE ACESS: %1 .").arg(loco.numero())));

        mutexA->acquire();
        if (!section_busy){//si c'est libre
            section_busy = true;
            mutexA->release();
        }
        else {//si c'est occupé
            loco.arreter();
            in_queue = true;
            afficher_message(qPrintable(QString("AVANT BLOQUE  %1 .").arg(loco.numero())));

            waiting->acquire();

            mutexA->release();
            loco.demarrer();
        }

        // Exemple de message dans la console globale
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

        mutexL->acquire();

        section_busy = false;

        if (in_queue){ //Si une loco attend

            waiting->release();
            in_queue = false;

        }
        afficher_message(qPrintable(QString("SORTIE ACESS: %1 .").arg(loco.numero())));

        mutexL->release();
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

        // contact 29 pour loco0 et 33 pour loco1

        while (loco.numero()){



        }




        // Exemple de message dans la console globale
        afficher_message(qPrintable(QString("The engine no. %1 arrives at the station.").arg(loco.numero())));
    }


};


#endif // SYNCHRO_H
