#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <pcosynchro/pcothread.h>
#include <QString>
#include <QString>
#include "threadmanager.h"

int compute(const QString &charset,
             const QString &salt,
             const QString &hashToBeFound,
             unsigned long nbChar,
             unsigned long startIndex,
             unsigned long endIndex,
             QString *pwd,
             ThreadManager *th);





#endif // MYTHREAD_H
