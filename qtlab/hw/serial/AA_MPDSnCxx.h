#ifndef AA_MPDSnCXX_H
#define AA_MPDSnCXX_H

#include <QObject>
#include <QVector>

class SerialPort;

class AA_MPDSnCxx : public QObject
{
    Q_OBJECT

    struct LineStatus {
        int id;
        double freq;
        double power_dBm;
        bool outputEnabled;
        bool externalMode;
    };

public:
    AA_MPDSnCxx(QObject *parent = nullptr);
    virtual ~AA_MPDSnCxx();

    SerialPort *getSerialPort() const;

    QString getProductID();
    QVector<LineStatus *> getStatus();
    QVector<LineStatus *> getLineStatus();

    int getSelectedChannel();
    void selectChannel(int n);
    double setFrequency(double freq);
    int setPower(int p);
    double setPower_dBm(double dBm);
    double setPowerFineAdjustment(int line, int p);

    int getNChannels() const;

    void setExternalModeEnabled(bool enable);

    void setBlanking(bool enableOutput, bool enableExternal, bool store = false);


public slots:
    void open();
    void close();
    void reset();

    void storeParams();

    void switchOn();
    void switchOff();

    void setVMode5V();
    void setVMode10V();

    double stepFrequencyUp();
    double stepFrequencyDown();

    int stepPowerUp();
    int stepPowerDown();

    int stepProfileUp();
    int stepProfileDown();

signals:
    void connected();
    void disconnected();
private:
    SerialPort *serial = nullptr;
    int nChannels;
    int selectedChannel;

    QStringList _getStatus();
    QVector<LineStatus *> status;
    void parseStatusLine(const QString &s);
    double _stepFrequency(bool up);
    int _stepPower(bool up);
    int _stepProfile(bool up);
};

#endif // AA_MPDSnCXX_H
