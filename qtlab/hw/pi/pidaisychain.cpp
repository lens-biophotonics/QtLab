#include <stdexcept>
#include <memory>

#include <QMap>

#ifdef WIN32
#include <windows.h>
#endif

#include <PI_GCS2_DLL.h>

#include <qtlab/hw/pi/pidaisychain.h>


static QMap<QString, PIDaisyChain *> dcMap;


PIDaisyChain::PIDaisyChain(QObject *parent) : QObject(parent), id(-1)
{
}

PIDaisyChain::~PIDaisyChain()
{
    close();
}

void PIDaisyChain::open(const QString &serialPortName, const int baud)
{
    std::unique_ptr<char[]> buf(new char[1024]);
#ifdef Q_OS_UNIX
    id = PI_OpenRS232DaisyChainByDevName(serialPortName.toStdString().c_str(),
                                         baud, &_nOfDevices, buf.get(), 1024);
#endif
#ifdef Q_OS_WIN
    bool ok;
    int portNumber = serialPortName.split("COM").at(1).toInt(&ok);
    if (!ok) {
        throw std::runtime_error("Invalid serialPortName");
    }
    id = PI_OpenRS232DaisyChain(portNumber, baud, &_nOfDevices, buf.get(), 1024);
#endif

    if (id == -1) {
        throw std::runtime_error("PI_OpenRS232DaisyChainByDevName failed");
    }
}

int PIDaisyChain::connectDevice(const int deviceNumber)
{
    if (deviceNumber < 1 || deviceNumber > _nOfDevices) {
        throw std::runtime_error("Invalid device number");
    }
    int devid = PI_ConnectDaisyChainDevice(id, deviceNumber);
    if (devid == -1) {
        throw std::runtime_error("PI_ConnectDaisyChainDevice failed");
    }
    return devid;
}

void PIDaisyChain::close()
{
    PI_CloseDaisyChain(id);
    id = -1;
}

bool PIDaisyChain::isOpen()
{
    return id != -1;
}

int PIDaisyChain::nOfDevices() const
{
    return _nOfDevices;
}

PIDaisyChain *openDaisyChain(const QString &portName, const int baud)
{
    PIDaisyChain *dc;
    auto it = dcMap.find(portName);
    if (it == dcMap.end()) {
        dc = new PIDaisyChain();
        dc->open(portName, baud);
        dcMap[portName] = dc;
    }
    else {
        dc = it.value();
    }
    return dc;
}

void closeDaisyChain(const QString &portName)
{
    auto it = dcMap.find(portName);
    if (it != dcMap.end()) {
        it.value()->close();
    }
}

void closeAllDaisyChains()
{
    qDeleteAll(dcMap);
    dcMap.clear();
}
