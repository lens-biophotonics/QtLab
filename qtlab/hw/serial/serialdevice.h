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

    SerialPort *serialPort() const;

public slots:
    void connect();
    void disconnect();

signals:
    void connected();
    void disconnected();

protected:
    virtual void postConnect_impl();
    SerialPort *serial = nullptr;
};

#endif // SERIALDEVICE_H
