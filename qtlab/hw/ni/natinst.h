#ifndef NATINST_H
#define NATINST_H

#include <QStringList>

namespace NI {

#include <NIDAQmx.h>

QStringList getDevicesInSystem();
QStringList getAOPhysicalChans();
QStringList getAIPhysicalChans();
QStringList getCOPhysicalChans();
QStringList getCIPhysicalChans();
QStringList getDILines();
QStringList getDIPorts();
QStringList getDOLines();
QStringList getDOPorts();
QStringList getTerminals();
}

#endif // NATINST_H
