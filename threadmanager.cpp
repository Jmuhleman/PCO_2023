#include <QCryptographicHash>
#include <QVector>

#include "threadmanager.h"
#include "mythread.h"
#include <iostream>

/*
 * std::pow pour les long long unsigned int
 */

long long unsigned int intPow (
        long long unsigned int number,
        long long unsigned int index)
{
    long long unsigned int i;

    if (index == 0)
        return 1;

    long long unsigned int num = number;

    for (i = 1; i < index; i++)
        number *= num;

    return number;
}

ThreadManager::ThreadManager(QObject *parent) :
    QObject(parent)
{}

void ThreadManager::incrementPercentComputed(double percentComputed)
{
    emit sig_incrementPercentComputed(percentComputed);
}

/*
 * Les paramètres sont les suivants:
 *
 * - charset:   QString contenant tous les caractères possibles du mot de passe
 * - salt:      le sel à concaténer au début du mot de passe avant de le hasher
 * - hash:      le hash dont on doit retrouver la préimage
 * - nbChars:   le nombre de caractères du mot de passe à bruteforcer
 * - nbThreads: le nombre de threads à lancer
 *
 * Cette fonction doit retourner le mot de passe correspondant au hash, ou une
 * chaine vide si non trouvé.
 */



QString ThreadManager::startHacking(
        QString charset,
        QString salt,
        QString hash,
        unsigned int nbChars,
        unsigned int nbThreads)
{


    std::vector<std::unique_ptr<PcoThread>> threadList;

    unsigned long long nbToCompute = intPow(charset.length(), nbChars);
    unsigned long long chunkSize = nbToCompute / nbThreads;

    QString pwd = "";
    unsigned int startIndex = 0;
    unsigned int endIndex = chunkSize;

    for (size_t k = 0 ; k <= nbThreads ; ++k){



        PcoThread* currentThread = new PcoThread(compute,
                                                  charset,
                                                  salt,
                                                  hash,
                                                  nbChars,
                                                  startIndex,
                                                  endIndex,
                                                  &pwd,
                                                  this);
        threadList.push_back(std::unique_ptr<PcoThread>(currentThread));

        startIndex = (k == 0) ? 0 : k * chunkSize + 1;
        endIndex = (k == nbThreads - 1) ? nbToCompute : (k+1) * chunkSize;



    }


    for (size_t k = 0 ; k < nbThreads ; ++k){
        threadList[k]->join();
    }

    threadList.clear();
    return pwd;

}
