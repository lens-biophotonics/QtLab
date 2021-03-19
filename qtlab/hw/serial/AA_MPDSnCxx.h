#ifndef AA_MPDSnCXX_H
#define AA_MPDSnCXX_H

#include <QObject>
#include <QVector>

#include <qtlab/hw/serial/serialdevice.h>

class AA_MPDSnCxx : public SerialDevice
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

    QString getProductID();
    QVector<LineStatus *> getStatus();
    QVector<LineStatus *> getLineStatus();

    int getSelectedChannel();
    int getNChannels() const;


public slots:
    void reset();

    void storeParams();

    void switchOn();
    void switchOff();

    void setExternalModeEnabled(bool enable);

    void selectChannel(int n);
    double setFrequency(double freq);
    int setPower(int p);
    double setPower_dBm(double dBm);
    double setPowerFineAdjustment(int line, int p);

    void setBlanking(bool enableOutput, bool enableExternal, bool store = false);

    void setVMode5V();
    void setVMode10V();

    double stepFrequencyUp();
    double stepFrequencyDown();

    int stepPowerUp();
    int stepPowerDown();

    int stepProfileUp();
    int stepProfileDown();

protected:
    virtual void postConnect_impl() override;

private:
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
