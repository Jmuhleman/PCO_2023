#include "mythread.h"
#include <QCryptographicHash>
#include <QVector>
#include "threadmanager.h"
#include <iostream>


//Fonction de convertion de chaque valeur en décimale sur une base N déterminé
//Selon la taille du charset passé en paramètres.
QVector<int> toBaseN(unsigned long value, const QString charset, int nChar) {
    QVector<int> result;
    //Pour convertir la valeur 0 il faut garder le nChar
    if (value == 0){
        result.fill(0, nChar);
        return result;
    }
    //Passer le nombre de valeurs possibles à la dernière valeur Ex: 1024 valeurs de 0-1023
    --value;
    unsigned int charsetSize = static_cast<unsigned int>(charset.length());

    while (value >= charsetSize) {
        unsigned int remainder = value % charsetSize;
        result.push_back(remainder);
        value /= charsetSize;
    }
    result.push_back(value);

    //Padding en 0 si < nChar
    int delta = nChar - result.size();
    for(int k = 0 ; k < delta ; ++k){
        result.push_back(0);
    }


    return result;
}



int compute(const QString &charset,
             const QString &salt,
             const QString &hashToBeFound,
             long long unsigned int nbChar,
             long long unsigned int startIndex,
             long long unsigned int endIndex,
             QString *pwd,
             ThreadManager *th,
             long long unsigned int nbToCompute){


    QCryptographicHash md5(QCryptographicHash::Md5);
    QString currentHash;
    QVector<int> currentPasswordArray;
    QString currentPasswordString;

    unsigned int i;

    //initialisation du de l'index à traiter au startIndex du thread.
    long long unsigned int currentIndex = startIndex;

    //Initialisation du mot de passse à calculer
    if (nbChar > 1){
        currentPasswordString.fill(charset.at(0), nbChar);
    }

    //Convertion de l'index de départ en base 66. Qui est la taille du charset à utiliser.
    currentPasswordArray = toBaseN(startIndex, charset, nbChar);
    if (endIndex - startIndex <= 0){
        ++endIndex;
    }
    //Nous testons deja le premier index avant de rentrer dans la boucle
    md5.reset();
    md5.addData(salt.toLatin1());
    md5.addData(currentPasswordString.toLatin1());
    currentHash = md5.result().toHex();

    if (currentHash == hashToBeFound){
        *pwd = currentPasswordString;
        return 0;
    }
    while (currentIndex <= endIndex && *pwd == "") {

        for (i=0 ; i < nbChar ; i++){
            currentPasswordString[i]  = charset.at(currentPasswordArray.at(i));
        }


        md5.reset();
        md5.addData(salt.toLatin1());
        md5.addData(currentPasswordString.toLatin1());
        currentHash = md5.result().toHex();

        if (currentHash == hashToBeFound){
            *pwd = currentPasswordString;
            return 0;
        }


        if (((endIndex - currentIndex) % 1000) == 0) {

              th->incrementPercentComputed((double)1000/(nbToCompute));
        }

        i = 0;

        while (i < (unsigned int)currentPasswordArray.size()) {
            currentPasswordArray[i]++;

            if (currentPasswordArray[i] >= charset.length()) {
                currentPasswordArray[i] = 0;
                i++;
            }

            else
                break;
        }
        ++currentIndex;

    }

return 0;
}


