// avoid conflict with Qt's signal keyword
#undef signals
#include <aravis-0.8/arv.h>
#define signals Q_SIGNALS

#include <qtlab/hw/aravis/aravis.h>

using namespace Aravis;

static QList<DeviceDescriptor*> devList;

QList<DeviceDescriptor*> Aravis::getDeviceDescriptors()
{
    devList.clear();
    arv_update_device_list();

    uint n = arv_get_n_devices();

    devList.reserve(n);
    for (uint i = 0; i < n; ++i) {
        struct DeviceDescriptor *dd = new DeviceDescriptor({
            .ID = arv_get_device_id(i),
            .physicalID = arv_get_device_physical_id(i),
            .model = arv_get_device_model(i),
            .serialNo = arv_get_device_serial_nbr(i),
            .vendor = arv_get_device_vendor(i),
            .address = arv_get_device_address(i),
            .protocol = arv_get_device_protocol(i),
        });
        devList.push_back(dd);
    }

    return devList;
}

QStringList Aravis::getInterfaces()
{
    uint n = arv_get_n_interfaces();

    QStringList sl;
    sl.reserve(n);
    for (uint i = 0; i < n; ++i) {
       sl.push_back(arv_get_interface_id(i));
    }
    return sl;
}

void Aravis::enableInterface(QString interface)
{
    arv_enable_interface(interface.toStdString().c_str());
}

void Aravis::disableInterface(QString interface)
{
    arv_disable_interface(interface.toStdString().c_str());
}

void Aravis::shutdown()
{
    arv_shutdown();
}
