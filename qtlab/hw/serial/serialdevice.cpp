#include "serialdevice.h"

#include <stdexcept>

SerialDevice::SerialDevice(QObject *parent)
    : QObject(parent)
{
    serial = new SerialPort(this);
}

SerialDevice::~SerialDevice()
{
    disconnect();
    delete serial;
}

void SerialDevice::connect()
{
    if (serial->isOpen()) {
        return;
    }
    bool ret = serial->open();
    if (!ret) {
        QString msg("Cannot connect to Device on serial port %1");
        msg = msg.arg(serial->portName());
        throw std::runtime_error(msg.toLatin1());
    } else {
        serial->readAll(); // empty input buffer
        postConnect_impl();
        emit connected();
    }
}

void SerialDevice::disconnect()
{
    if (!serial->isOpen()) {
        return;
    }
    serial->close();
    emit disconnected();
}

SerialPort *SerialDevice::serialPort() const
{
    return serial;
}

/**
 * @brief Executed after successful connection, but before the connect() signal is
 * emitted.
 *
 * The default implementation does nothing.
 */

void SerialDevice::postConnect_impl() {}
