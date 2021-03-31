#ifndef AA_MPDSnCXX_H
#define AA_MPDSnCXX_H

#include <QObject>
#include <QVector>

#include <qtlab/hw/serial/serialdevice.h>

class AA_MPDSnCxx : public SerialDevice
{
    Q_OBJECT

public:

    struct LineStatus {
        friend class AA_MPDSnCxx;
public:
        int getId() const {return id;}
        double getFreq() const {return freq;}
        double getPower_dBm() const {return power_dBm;}
        bool isOutputEnabled() const {return outputEnabled;}
        bool isExternalModeEnabled() const {return externalMode;}

private:
        int id;
        double freq;
        double power_dBm;
        bool outputEnabled;
        bool externalMode;
    };

    AA_MPDSnCxx(QObject *parent = nullptr);

    QString getProductID();
    QVector<LineStatus *> getStatus();
    QVector<LineStatus *> getLineStatus();
    LineStatus *selectedChanelStatus();

    int getSelectedChannel();
    int getNChannels() const;

    bool isVMode10V() const;
    bool isBlankingEnabled() const;
    bool isBlankingExternal() const;

public slots:
    void refresh();
    void reset();

    void storeParams();

    void setOutputEnabled(bool enable);
    void setOutputEnabled(int line, bool enable);

    void setExternalModeEnabled(bool enable);
    void setExternalModeEnabled(int line, bool enable);

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
    int selectedProfile;
    bool VMode10V;
    bool blankingEnabled;
    bool blankingExternal;

    QStringList _getStatus();
    QVector<LineStatus *> status;
    void parseStatusLine(const QString &s);
    void parseLResponse(const QString &s);
    void parseHelp();
    double _stepFrequency(bool up);
    int _stepPower(bool up);
    int _stepProfile(bool up);
};

#endif // AA_MPDSnCXX_H
