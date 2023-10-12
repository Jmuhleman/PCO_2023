#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <pcosynchro/pcothread.h>
#include <QString>
#include <QString>
#include "threadmanager.h"

void compute(const QString &charset,
             const QString &salt,
             const QString &hashToBeFound,
             unsigned int nbChar,
             unsigned int startIndex,
             unsigned int endIndex,
             QString *pwd,
             ThreadManager *th);





#endif // MYTHREAD_H
