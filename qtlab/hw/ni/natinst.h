#ifndef NATINST_H
#define NATINST_H

#include <QStringList>

namespace NI {

#include <NIDAQmx.h>

QStringList getDevicesInSystem();
QStringList getDOLines();
QStringList getAOPhysicalChans();
QStringList getCOPhysicalChans();
QStringList getTerminals();
}

#endif // NATINST_H
