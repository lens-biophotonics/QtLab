#ifndef SERIALDEVICE_H
#define SERIALDEVICE_H

#include <QObject>

#include <qtlab/hw/serial/serialport.h>

/**
 * @brief The SerialDevice class represents a device with a serial port.
 */

class SerialDevice : public QObject
{
    Q_OBJECT
public:
    explicit SerialDevice(QObject *parent = nullptr);
    virtual ~SerialDevice();

    SerialPort *getSerialPort() const;

public slots:
    void connect();
    void disconnect();

signals:
    void connected();
    void disconnected();

protected:
    virtual void postConnect_impl();
    SerialPort *serialPort = nullptr;
};

#endif // SERIALDEVICE_H
