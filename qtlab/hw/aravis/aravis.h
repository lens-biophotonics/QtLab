#ifndef ARAVIS_H
#define ARAVIS_H

#include <QObject>

namespace Aravis {

struct DeviceDescriptor {
    QString ID;
    QString physicalID;
    QString model;
    QString serialNo;
    QString vendor;
    QString address;
    QString protocol;
};

QList<DeviceDescriptor*> getDeviceDescriptors();
QStringList getInterfaces();
void enableInterface(QString interface);
void disableInterface(QString interface);
void shutdown();

} // namespace Aravis

#endif // ARAVIS_H
