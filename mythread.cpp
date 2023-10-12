#include "mythread.h"
#include <QCryptographicHash>
#include <QVector>
#include "threadmanager.h"
#include <iostream>



QVector<int> toBaseN(unsigned long value, const QString charset, int nChar) {
    QVector<int> result;
    if (value == 0){
        result.fill(0, nChar);
        return result;
    }
    --value;
    unsigned int charsetSize = static_cast<unsigned int>(charset.length());

    while (value >= charsetSize) {
        unsigned int remainder = value % charsetSize;
        result.push_back(remainder);
        value /= charsetSize;
    }
    result.push_back(value);


    int delta = nChar - result.size();
    for(int k = 0 ; k < delta ; ++k){
        result.push_back(0);
    }


    return result;
}




int compute(const QString &charset,
             const QString &salt,
             const QString &hashToBeFound,
             unsigned long nbChar,
             unsigned long startIndex,
             unsigned long endIndex,
             QString *pwd,
             ThreadManager *th){

    QCryptographicHash md5(QCryptographicHash::Md5);
    QString currentHash;
    QVector<int> currentPasswordArray;
    QString currentPasswordString;

    unsigned int i;
    unsigned int currentIndex = startIndex;
    if (nbChar > 1){
        currentPasswordString.fill(charset.at(0), nbChar);
    }
    currentPasswordArray = toBaseN(startIndex, charset, nbChar);
    if (endIndex - startIndex <= 0){
        ++endIndex;
    }

    while (currentIndex <= endIndex) {
        md5.reset();
        md5.addData(salt.toLatin1());
        md5.addData(currentPasswordString.toLatin1());
        currentHash = md5.result().toHex();


        for (i=0 ; i < nbChar ; i++){
            currentPasswordString[i]  = charset.at(currentPasswordArray.at(i));
        }



        if (currentHash == hashToBeFound){
            *pwd = currentPasswordString;
            return 0;
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
        ++currentIndex;

    }

return -1;
}


