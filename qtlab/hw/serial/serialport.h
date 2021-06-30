#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QSerialPort>
#include <QState>

class SerialPort : public QSerialPort
{
    Q_OBJECT
public:
    SerialPort(QObject *parent = nullptr);
    bool open(OpenMode mode = QIODevice::ReadWrite);
    void close();

    void sendMsg(QString msg);
    QString receive(QString until = QString());
    virtual QString transceive(QString command, QString until = QString());
    double getDouble(const QString &cmd);
    int getInt(const QString &cmd);
    int getUInt(const QString &cmd);
    QSerialPortInfo portInfo() const;

    static QSerialPortInfo findPortFromSerialNumber(const QString &sn);

    void setPortBySerialNumber(const QString &serialNumber);
    void setTimeout(int ms);

    QStringList getLineEndTermination();
    void setLineEndTermination(const QString &tx, const QString &rx = QString());

    QString getTxLineEndTermination();
    QString getRxLineEndTermination();

    void setLoggingEnabled(bool enable);

    QState *getConnectedState() const;
    QState *getDisconnectedState() const;

    int getTransceiveTimeout() const;
    void setTransceiveTimeout(int ms);

signals:
    void opened();
    void closed();

protected:
    virtual bool open_impl();

private:
    QString txLineEndTermination;
    QString rxLineEndTermination;
    bool loggingEnabled = false;
    int _serialTimeout;
    int transceiveTimeout = -1;

    QState *connectedState;
    QState *disconnectedState;

    void setupStateMachine();
};

#endif // SERIALPORT_H
