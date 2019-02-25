#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QSerialPort>

class SerialPort : public QSerialPort
{
    Q_OBJECT
public:
    SerialPort(QObject *parent = nullptr);
    void sendMsg(QString msg);
    void close();

    static QSerialPortInfo findPortFromSerialNumber(const QString &sn);

    QString transceive(QString command);
    bool open(OpenMode mode = QIODevice::ReadWrite);

    float getFloat(const QString &cmd);
    int getInt(const QString &cmd);

    void setSerialNumber(const QString &serialNumber);
    void setTimeout(int ms);
    void setLineEndTermination(const QString &termination);
    void setLoggingEnabled(bool enable);


private slots:
    QString receiveMsg();

signals:
    void opened();
    void closed();

protected:
    virtual bool open_impl();

private:
    QString _serialNumber;
    QString lineEndTermination;
    bool loggingEnabled = false;
    int _transceiveTimeout;
};

#endif // SERIALPORT_H