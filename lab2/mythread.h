#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <pcosynchro/pcothread.h>
#include <QString>
#include <QString>
#include "threadmanager.h"

int compute(const QString &charset,
             const QString &salt,
             const QString &hashToBeFound,
             long long unsigned int nbChar,
             long long unsigned int startIndex,
             long long unsigned intendIndex,
             QString *pwd,
             ThreadManager *th,
             long long unsigned int nbTocompute);





#endif // MYTHREAD_H
