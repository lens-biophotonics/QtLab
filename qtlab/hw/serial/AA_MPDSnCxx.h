#ifndef AA_MPDSnCXX_H
#define AA_MPDSnCXX_H

#include <qtlab/hw/serial/serialdevice.h>

#include <QObject>
#include <QVector>

class AA_MPDSnCxx : public SerialDevice
{
    Q_OBJECT

public:
    struct LineStatus
    {
        friend class AA_MPDSnCxx;

    public:
        int getId() const { return id; }
        double getFreq() const { return freq; }
        double getPower_dBm() const { return power_dBm; }
        bool isOutputEnabled() const { return outputEnabled; }
        bool isExternalModeEnabled() const { return externalMode; }

    private:
        int id;
        double freq;
        double power_dBm;
        bool outputEnabled;
        bool externalMode = true;
    };

    /**
     * @brief The MPDS_VERSION enum handles different hardware versions.
     *
     * In our lab we have two devices which report the following with the help (?) command:
     *
     * MDS  V4.21  // 25/06/12
     * MPDS V8.24  // 13/11/2017
     *
     * These two devices have significant differences in the way they respond. For example, the
     * device with V4 sends a lot of null ('\0') bytes. For lack of better documentation about these
     * two devices, we use this enum to differentiate between the two.
     */
    enum MPDS_VERSION {
        MPDS_VERSION_UNKNOWN = 0,
        MPDS_VERSION_4 = 4,
        MPDS_VERSION_8 = 8,
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

    bool hasBlanking() const;

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
    bool _hasBlanking;
    bool blankingEnabled;
    bool blankingExternal;
    QVector<LineStatus *> status;
    enum MPDS_VERSION mpdsVersion;
    QString altTerminator; /**< alternative line terminator */

    QStringList _getStatus();
    void parseStatusLine(const QString &s);
    void parseLResponse(const QString &s);
    void parseHelp();
    double _stepFrequency(bool up);
    int _stepPower(bool up);
    int _stepProfile(bool up);
    QString _transceive(QString msg, QString until);
};

#endif // AA_MPDSnCXX_H
