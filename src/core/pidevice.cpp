#include <stdexcept>
#include <memory>

#include <QString>

#include "pidevice.h"
#include "pidaisychain.h"

#define FUNCNAME(x) # x
#ifdef WITH_HARDWARE
#define CALL_THROW(functionCall) \
    if (!functionCall) { \
        throw std::runtime_error(std::string(FUNCNAME(functionCall)) + std::string(" error")); \
    }
#else
#define CALL_THROW(func)
#endif


PIDevice::PIDevice(QObject *parent) : QObject(parent)
{
}

PIDevice::~PIDevice()
{
    close();
}

void PIDevice::connect(const QString &portName, const int baud)
{
    id = PI_ConnectRS232ByDevName(portName.toStdString().c_str(), baud);

    if (id == -1) {
        throw std::runtime_error("PI_ConnectRS232ByDevName failed");
    }
}

void PIDevice::connectDaisyChain(
    const QString &portName, const int deviceNumber)
{
    id = openDaisyChain(portName, 38400)->connectDevice(deviceNumber);
}

void PIDevice::close()
{
    PI_CloseConnection(id);
    id = -1;
}

bool PIDevice::isConnected()
{
#ifdef WITH_HARDWARE
    return PI_IsConnected(id);
#else
    return id == -1;
#endif
}


void PIDevice::move(const QString &axes, const double pos[])
{
#ifndef WITH_HARDWARE
    Q_UNUSED(axes)
    Q_UNUSED(pos)
#endif
    CALL_THROW(PI_MOV(id, axes.toLatin1(), pos));
}

void PIDevice::setServoEnabled(const QString &axes, const QVector<int> &enable)
{
    if (axes.isEmpty()) {
        return;
    }
#ifndef WITH_HARDWARE
    Q_UNUSED(enable)
#endif
    CALL_THROW(PI_SVO(id, axes.toLatin1(), enable.constData()));
}

void PIDevice::fastMoveToPositiveLimit(const QString &axes)
{
    if (axes.isEmpty()) {
        return;
    }
    CALL_THROW(PI_FPL(id, axes.toLatin1()));
}

void PIDevice::fastMoveToNegativeLimit(const QString &axes)
{
    if (axes.isEmpty()) {
        return;
    }
    CALL_THROW(PI_FNL(id, axes.toLatin1()));
}

void PIDevice::fastMoveToReferenceSwitch(const QString &axes)
{
    if (axes.isEmpty()) {
        return;
    }
    CALL_THROW(PI_FRF(id, axes.toLatin1()));
}

void PIDevice::loadStages(
    const QString &axes, const QStringList &stages)
{
    if (axes.isEmpty() || stages.isEmpty()) {
        return;
    }
    CALL_THROW(PI_CST(id, axes.toLatin1(), stages.join("\n").toLatin1()));
}

QStringList PIDevice::getStages(const QString &axes)
{
#ifndef WITH_HARDWARE
    Q_UNUSED(axes)
#endif
    std::unique_ptr<char[]> buf(new char[1024]);
    CALL_THROW(PI_qCST(id, axes.toLatin1(), buf.get(), 1024));
    QStringList sl = QString(buf.get()).split("\n");
    sl.removeAll(QString(""));
    return sl;
}

QStringList PIDevice::getAvailableStageTypes()
{
    std::unique_ptr<char[]> buf(new char[4096]);
#ifdef WITH_HARDWARE
    CALL_THROW(PI_qVST(id, buf.get(), 4096));
#endif
    QStringList sl = QString(buf.get()).replace(" ", "").split("\n");
    sl.removeAll(QString(""));
    return sl;
}

QString PIDevice::getAxisIdentifiers()
{
    std::unique_ptr<char[]> buf(new char[32]);
    CALL_THROW(PI_qSAI(id, buf.get(), 32));
    return QString(buf.get()).replace("\n", "");
}

QVector<int> PIDevice::getReferencedState(QString axes)
{
    int nOfAxes;
    if (axes.isEmpty()) {
        nOfAxes = getAxisIdentifiers().length();
    }
    else {
        nOfAxes = axes.length();
    }
    QVector<BOOL> vec;
    vec.resize(nOfAxes);
    std::unique_ptr<BOOL[]> buf(new BOOL[static_cast<size_t>(nOfAxes)]);
    CALL_THROW(PI_qFRF(id, "", vec.data()));
    return vec;
}

QString PIDevice::getErrorString()
{
    std::unique_ptr<char[]> buf(new char[1024]);
    PI_TranslateError(PI_GetError(id), buf.get(), 1024);
    return QString(buf.get());
}
