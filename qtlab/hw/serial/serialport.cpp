#include <stdexcept>

#include <QSerialPortInfo>
#include <QStateMachine>

#include <qtlab/core/logger.h>

#include <qtlab/hw/serial/serialport.h>

#define RUNTIME_ERROR(what) {                                               \
        logger->critical(what);                                             \
        throw std::runtime_error(what);                                     \
}                                                                           \

static Logger *logger = getLogger("SerialPort");

SerialPort::SerialPort(QObject *parent)
    : QSerialPort(parent)
{
    setupStateMachine();

    setBaudRate(Baud115200);
    setFlowControl(NoFlowControl);
    setParity(NoParity);
    setDataBits(Data8);
    setStopBits(OneStop);
    setTimeout(500);
}

bool SerialPort::open(OpenMode mode)
{
    bool ret = QSerialPort::open(mode);
    if (!ret) {
        return false;
    }

    logger->info(QString("Connected on port ").append(portName()));
    ret = open_impl();
    if (ret)
        emit opened();
    return ret;
}

bool SerialPort::open_impl()
{
    return true;
}

QState *SerialPort::getDisconnectedState() const
{
    return disconnectedState;
}

QState *SerialPort::getConnectedState() const
{
    return connectedState;
}

void SerialPort::setupStateMachine()
{
    connectedState = new QState();
    disconnectedState = new QState();

    connectedState->addTransition(this, &SerialPort::closed, disconnectedState);

    disconnectedState->addTransition(this, &SerialPort::opened, connectedState);

    QStateMachine *sm = new QStateMachine();

    sm->addState(connectedState);
    sm->addState(disconnectedState);

    sm->setInitialState(disconnectedState);
    sm->start();
}

QString SerialPort::receiveMsg()
{
    QString msg = readAll();

    if (loggingEnabled) {
        logger->info("<<< " + msg);
    }
    return msg.replace(rxLineEndTermination, "");
}

void SerialPort::sendMsg(QString msg)
{
    msg.append(txLineEndTermination);
    if (!isOpen()) {
        RUNTIME_ERROR("Device not open")
    }
    qint64 ret = write(msg.toLatin1());
    if (ret < 0) {
        RUNTIME_ERROR("QSerialPort::write");
    }
    if (loggingEnabled) {
        logger->info(">>> " + msg);
    }
}

QString SerialPort::receive(QString until)
{
    QString receivedLines;
    while (true) {
        waitForReadyRead(_serialTimeout);

        QString msg = receiveMsg();
        receivedLines.append(msg);

        if (bytesAvailable() <= 0) {
            if (!until.isNull()) {
                if (!receivedLines.endsWith(until)) {
                    continue;
                }
            }

            break;
        }
    }

    return receivedLines;
}

QString SerialPort::transceive(QString command, QString until)
{
    sendMsg(command);
    return receive(until);
}

void SerialPort::close()
{
    QSerialPort::close();
    if (!isOpen()) {
        emit closed();
        logger->info(QString("Disconnected port ").append(portName()));
    }
}

QSerialPortInfo SerialPort::findPortFromSerialNumber(const QString &sn)
{
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts()) {
        if (info.serialNumber() == sn) {
            return info;
        }
    }
    return QSerialPortInfo();
}

/**
 * @brief Convenience function to retrieve a float.
 * @param cmd The command to be sent.
 * @return The retrieved float.
 */

double SerialPort::getDouble(const QString &cmd)
{
    QString str = transceive(cmd);
    bool ok;
    double f = str.toDouble(&ok);
    if (!ok) {
        throw std::runtime_error(QString("Cannot convert string to double: " + str).toLatin1());
    }
    return f;
}

/**
 * @brief Convenience function to retrieve an int.
 * @param cmd The command to be sent.
 * @return The retrieved int.
 */

int SerialPort::getInt(const QString &cmd)
{
    QString str = transceive(cmd);
    bool ok;
    int integer = str.toInt(&ok);
    if (!ok) {
        throw std::runtime_error(QString("Cannot convert string to int: " + str).toLatin1());
    }
    return integer;
}

void SerialPort::setTimeout(int ms)
{
    _serialTimeout = ms;
}

QSerialPortInfo SerialPort::portInfo() const
{
    return QSerialPortInfo(*this);
}

void SerialPort::setPortBySerialNumber(const QString &serialNumber)
{
    QSerialPortInfo pi = findPortFromSerialNumber(serialNumber);
    if (pi.isNull()) {
        logger->warning("Cannot find serial port for serial number" + serialNumber);
        return;
    }
    setPort(pi);
    logger->info(QString("Found serial number %1 on %2")
                 .arg(portInfo().serialNumber()).arg(portInfo().portName()));
}

QStringList SerialPort::getLineEndTermination()
{
    QStringList sl;
    sl << txLineEndTermination << rxLineEndTermination;
    return sl;
}

void SerialPort::setLineEndTermination(const QString &tx, const QString &rx)
{
    txLineEndTermination = tx;
    rxLineEndTermination = rx;
}

QString SerialPort::getTxLineEndTermination()
{
    return txLineEndTermination;
}

QString SerialPort::getRxLineEndTermination()
{
    return rxLineEndTermination;
}

void SerialPort::setLoggingEnabled(bool enable)
{
    loggingEnabled = enable;
}
