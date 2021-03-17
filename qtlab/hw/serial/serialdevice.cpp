#include "serialdevice.h"

SerialDevice::SerialDevice(QObject *parent) : QObject(parent)
{
    serialPort = new SerialPort();
}

SerialDevice::~SerialDevice()
{
    disconnect();
    delete serialPort;
}

void SerialDevice::connect()
{
    if (serialPort->isOpen()) {
        return;
    }
    bool ret = serialPort->open();
    if (!ret) {
        QString msg("Cannot connect to Device on serial port %1");
        msg = msg.arg(serialPort->portName());
        throw std::runtime_error(msg.toLatin1());
    } else {
        serialPort->readAll();  // empty input buffer
        postConnect_impl();
        emit connected();
    }
}

void SerialDevice::disconnect()
{
    if (!serialPort->isOpen()) {
        return;
    }
    serialPort->close();
    emit disconnected();
}

SerialPort *SerialDevice::getSerialPort() const
{
    return serialPort;
}

/**
 * @brief Executed after successful connection, but before the connect() signal is
 * emitted.
 *
 * The default implementation does nothing.
 */

void SerialDevice::postConnect_impl()
{
}
