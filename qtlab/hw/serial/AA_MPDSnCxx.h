#ifndef AA_MPDSnCXX_H
#define AA_MPDSnCXX_H

#define AOTF_SWITCH_TIME 1
#define AOTF_SERIAL_BAUD_RATE 57600

#include <QObject>

class SerialPort;

class AA_MPDSnCxx : public QObject
{
    Q_OBJECT

public:
    AA_MPDSnCxx(QObject *parent = nullptr);
    virtual ~AA_MPDSnCxx();

    SerialPort *getSerialPort() const;

    QString getID();
    QStringList getStatus();
    QString getChannelInfo();
    QString getDeviceInfo();

    int getChannel();
    void setChannel(int n);
    float getFrequency();
    void setFrequency(float freq);
    int getPower();
    void setPower(int amp);
    float getPowerDBm();
    void setPowerDBm(float dBm);

public slots:
    void open();
    void close();
    void reset();

    void saveSettings();

signals:
    void connected();
    void disconnected();
private:
    SerialPort *serial = nullptr;

    QString transceiveChkOK(QString cmd);
    QString transceiveChkSyntaxError(QString cmd);
    int castStringToIntChkError(QString str);
    float castStringToFloatChkError(QString str);
};

#endif // AA_MPDSnCXX_H
