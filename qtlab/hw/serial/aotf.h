#ifndef AOTF_H
#define AOTF_H

#define AOTF_SWITCH_TIME 1
#define AOTF_SERIAL_BAUD_RATE 57600

#include <QObject>

class SerialPort;

class AcoustoOpticFilter : public QObject
{
    Q_OBJECT

public:
    AcoustoOpticFilter(QObject *parent = nullptr);
    virtual ~AcoustoOpticFilter();

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


//    int getPosition();
//    int getPositionCount();
//    int getPositionNumber() const;
    int getMotionTime() const;
//    QStringList getFilterListName() const;
//    QString getFilterName(int n);
//    void setPositionNumber(const int count);

    QString getVerboseName() const;
    void setVerboseName(const QString &value);

public slots:
    void open();
    void close();
    void reset();

    //void restoreDefaultSettings();
    void saveSettings();
    //QString setPosition(int n);
    //void setPositionCount(int n);

signals:
    void connected();
    void disconnected();
    //QStringList getFilterListName() const;
    //QString getFilterName(int n);
    //void setPositionNumber(const int count);
private:
    SerialPort *serial = nullptr;
    QString verboseName;
    int positionNumber;
    int motionTime; // ms

    void setMotionTime(const int timewait);
    QString transceiveChkOK(QString cmd);
    QString transceiveChkSyntaxError(QString cmd);
    void removeEcho(QString cmd);
    QString removeTrailingWhitespace(const QString& str);
    int castStringToIntChkError(QString str);
    float castStringToFloatChkError(QString str);
};

#endif // AOTF_H
