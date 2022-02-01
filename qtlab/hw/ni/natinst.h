#ifndef NATINST_H
#define NATINST_H

#include <QStringList>

namespace NI {
#include <NIDAQmx.h>

QString PFI2Line(QString term);
QString getVersion();

#include "NIDAQmx_ni_wrapper_methods.h"
} // namespace NI

#endif // NATINST_H
