#include <stdexcept>

#include <QSerialPortInfo>
#include <QStateMachine>
#include <QTime>

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

int SerialPort::getTransceiveTimeout() const
{
    return transceiveTimeout;
}

void SerialPort::setTransceiveTimeout(int ms)
{
    transceiveTimeout = ms;
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

qint64 SerialPort::sendMsg(QByteArray msg)
{
    msg.append(txLineEndTermination.toUtf8());
    if (!isOpen()) {
        RUNTIME_ERROR("Device not open")
    }
    qint64 ret = write(msg);
    if (ret < 0) {
        RUNTIME_ERROR("QSerialPort::write");
    }
    if (loggingEnabled) {
        logger->info(">>> " + msg);
    }

    return ret;
}

void SerialPort::sendMsg(QString msg)
{
    sendMsg(msg.toUtf8());
}

QString SerialPort::receive(QString until)
{
    return receiveBytes(until.toUtf8());
}

QByteArray SerialPort::receiveBytes(QByteArray until)
{
    QByteArray receivedLines;
    QTime time;
    time.start();

    QByteArray rxLineEndTermination_b = rxLineEndTermination.toUtf8();

    while (true) {
        waitForReadyRead(_serialTimeout);

        QByteArray msg = readAll();

        if (loggingEnabled) {
            logger->info("<<< " + msg);
        }

        receivedLines.append(msg);

        if (!until.isEmpty()) {
            if (receivedLines.endsWith(until)) {
                break;
            }
        }

        if (transceiveTimeout >= 0) {
            if (time.elapsed() > transceiveTimeout) {
                logger->warning("Transceive timeout");
                break;
            }
        } else if (bytesAvailable() <= 0) {
            break;
        }
    }

    if (receivedLines.endsWith(rxLineEndTermination_b)) {
        receivedLines = receivedLines.left(receivedLines.size() - rxLineEndTermination_b.size());
    }

    return receivedLines;
}

QByteArray SerialPort::readNBytes(int n)
{
    QByteArray receivedLines;
    QTime time;
    time.start();

    while (receivedLines.length() < n) {
        waitForReadyRead(_serialTimeout);

        QByteArray msg = readAll();

        if (loggingEnabled) {
            logger->info("<<< " + msg);
        }

        receivedLines.append(msg);
    }

    return receivedLines;
}

QByteArray SerialPort::transceiveBytes(QByteArray command, QByteArray until)
{
    sendMsg(command);
    return receiveBytes(until);
}

QString SerialPort::transceive(QString command, QString until)
{
    QMutexLocker locker(&transceiveMutex);
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
    QString str = transceive(cmd, rxLineEndTermination);
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
    QString str = transceive(cmd, rxLineEndTermination);
    bool ok;
    int integer = str.toInt(&ok);
    if (!ok) {
        throw std::runtime_error(QString("Cannot convert string to int: " + str).toLatin1());
    }
    return integer;
}

/**
 * @brief Convenience function to retrieve an uint.
 * @param cmd The command to be sent.
 * @return The retrieved int.
 */

int SerialPort::getUInt(const QString &cmd)
{
    QString str = transceive(cmd, rxLineEndTermination);
    bool ok;
    int integer = str.toUInt(&ok);
    if (!ok) {
        throw std::runtime_error(QString("Cannot convert string to uint: " + str).toLatin1());
    }
    return integer;
}

void SerialPort::setTimeout(int ms)
{
    _serialTimeout = ms;
}

int SerialPort::getTimeout() const
{
    return _serialTimeout;
}

QSerialPortInfo SerialPort::portInfo() const
{
    return QSerialPortInfo(*this);
}

void SerialPort::setPortBySerialNumber(const QString &serialNumber)
{
    QSerialPortInfo pi = findPortFromSerialNumber(serialNumber);
    if (pi.isNull()) {
        logger->warning("Cannot find serial port for serial number " + serialNumber);
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
