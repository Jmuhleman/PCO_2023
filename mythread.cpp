#include "mythread.h"
#include <QCryptographicHash>
#include <QVector>
#include "threadmanager.h"
#include <iostream>



QVector<int> toBaseN(unsigned int value, const QString charset, int nChar) {
    QVector<int> result;
    if (value == 0){
        result.fill(0, nChar);
    }

    --value;
    unsigned int charsetSize = static_cast<unsigned int>(charset.size());

    while (value > charsetSize) {
        unsigned int remainder = value % charsetSize;
        result.push_back(remainder);
        value /= charsetSize;
    }
    result.push_back(value);

    return result;
}




void compute(const QString &charset,
             const QString &salt,
             const QString &hashToBeFound,
             unsigned int nbChar,
             unsigned int startIndex,
             unsigned int endIndex,
             QString *pwd,
             ThreadManager *th){

    QCryptographicHash md5(QCryptographicHash::Md5);
    QString currentHash;
    QVector<int> currentPasswordArray;
    QString currentPasswordString;

    currentPasswordString.fill(charset.at(0), nbChar);

    unsigned int i;
    unsigned int currentIndex = startIndex;

    currentPasswordArray = toBaseN(startIndex, charset, nbChar);


    while (currentIndex < endIndex) {
        md5.reset();
        md5.addData(salt.toLatin1());
        md5.addData(currentPasswordString.toLatin1());
        currentHash = md5.result().toHex();

        if (currentHash == hashToBeFound){
            *pwd = currentPasswordString;
            return;
        }
          if (((endIndex - currentIndex) % 1000) == 0) {

              th->incrementPercentComputed((double)1000/(endIndex - currentIndex));
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


        for (i=0 ; i < nbChar ; i++){
            currentPasswordString[i]  = charset.at(currentPasswordArray.at(i));
        }
        ++currentIndex;

    }


}


