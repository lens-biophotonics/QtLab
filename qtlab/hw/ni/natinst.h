#ifndef NATINST_H
#define NATINST_H

#include <QStringList>

namespace NI {
#include <NIDAQmx.h>

QStringList getDevicesInSystem();
QString PFI2Line(QString term);

#include "NIDAQmx_ni_wrapper_methods.h"
}

#endif // NATINST_H
