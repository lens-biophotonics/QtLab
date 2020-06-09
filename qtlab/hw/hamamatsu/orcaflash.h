#ifndef ORCAFLASH_H
#define ORCAFLASH_H

#include <stdexcept>

#include <QObject>
#include <QMutex>
#include <QState>

#include <qtlab/hw/hamamatsu/dcamutils.h>

#define CLASSNAME(x) # x

#define EXCEPTION_CLASS(name)                                               \
    class name : public std::runtime_error {                                \
public:                                                                     \
        name();                                                             \
    };

class OrcaFlash : public QObject
{
    Q_OBJECT

public:
    EXCEPTION_CLASS(OrcaBusyException)
    EXCEPTION_CLASS(OrcaNotReadyException)
    EXCEPTION_CLASS(OrcaNotStableException)
    EXCEPTION_CLASS(OrcaUnstableException)
    EXCEPTION_CLASS(OrcaNotBusyException)

    enum ORCA_TRIGGER_MODE {
        TRIGMODE_PIV = DCAM::DCAMPROP_TRIGGER_MODE__PIV,
        TRIGMODE_START = DCAM::DCAMPROP_TRIGGER_MODE__START,
        TRIGMODE_NORMAL = DCAM::DCAMPROP_TRIGGER_MODE__NORMAL,
        TRIGMODE_MULTIGATE = DCAM::DCAMPROP_TRIGGER_MODE__MULTIGATE,
        TRIGMODE_MULTIFRAME = DCAM::DCAMPROP_TRIGGER_MODE__MULTIFRAME,
    };

    enum ORCA_TRIGGERSOURCE {
        TRIGGERSOURCE_INTERNAL = DCAM::DCAMPROP_TRIGGERSOURCE__INTERNAL,
        TRIGGERSOURCE_EXTERNAL = DCAM::DCAMPROP_TRIGGERSOURCE__EXTERNAL,
        TRIGGERSOURCE_SOFTWARE = DCAM::DCAMPROP_TRIGGERSOURCE__SOFTWARE,
        TRIGGERSOURCE_MASTERPULSE = DCAM::DCAMPROP_TRIGGERSOURCE__MASTERPULSE,
    };

    enum ORCA_OUTPUT_TRIGGER_SOURCE {
        OUTPUT_TRIGGER_SOURCE_EXPOSURE = DCAM::DCAMPROP_OUTPUTTRIGGER_SOURCE__EXPOSURE,
        OUTPUT_TRIGGER_SOURCE_READOUTEND = DCAM::DCAMPROP_OUTPUTTRIGGER_SOURCE__READOUTEND,
        OUTPUT_TRIGGER_SOURCE_VSYNC = DCAM::DCAMPROP_OUTPUTTRIGGER_SOURCE__VSYNC,
        OUTPUT_TRIGGER_SOURCE_HSYNC = DCAM::DCAMPROP_OUTPUTTRIGGER_SOURCE__HSYNC,
        OUTPUT_TRIGGER_SOURCE_TRIGGER = DCAM::DCAMPROP_OUTPUTTRIGGER_SOURCE__TRIGGER,
    };

    enum ORCA_OUTPUT_TRIGGER_KIND {
        OUTPUT_TRIGGER_KIND_LOW = DCAM::DCAMPROP_OUTPUTTRIGGER_KIND__LOW,
        OUTPUT_TRIGGER_KIND_EXPOSURE = DCAM::DCAMPROP_OUTPUTTRIGGER_KIND__EXPOSURE,
        OUTPUT_TRIGGER_KIND_PROGRAMMABLE = DCAM::DCAMPROP_OUTPUTTRIGGER_KIND__PROGRAMABLE,
        OUTPUT_TRIGGER_KIND_TRIGGERREADY = DCAM::DCAMPROP_OUTPUTTRIGGER_KIND__TRIGGERREADY,
        OUTPUT_TRIGGER_KIND_HIGH = DCAM::DCAMPROP_OUTPUTTRIGGER_KIND__HIGH,
    };

    enum ORCA_TRIGGER_POLARITY {
#if DCAM_VERSION == 400
        POL_NEGATIVE = DCAM::DCAMPROP_TRIGGERPOLARITY__NEGATIVE,
        POL_POSITIVE = DCAM::DCAMPROP_TRIGGERPOLARITY__POSITIVE,
#else
        POL_NEGATIVE = DCAM::DCAM_TRIGPOL_NEGATIVE,
        POL_POSITIVE = DCAM::DCAM_TRIGPOL_POSITIVE,
#endif
    };

    enum ORCA_CAPSTATUS {
        CAPSTATUS_ERROR = DCAM::DCAMCAP_STATUS_ERROR,
        CAPSTATUS_BUSY = DCAM::DCAMCAP_STATUS_BUSY,
        CAPSTATUS_READY = DCAM::DCAMCAP_STATUS_READY,
        CAPSTATUS_STABLE = DCAM::DCAMCAP_STATUS_STABLE,
        CAPSTATUS_UNSTABLE = DCAM::DCAMCAP_STATUS_UNSTABLE,
    };

    enum ORCA_SENSOR_MODE {
        SENSOR_MODE_AREA = DCAM::DCAMPROP_SENSORMODE__AREA,
        SENSOR_MODE_SLIT= DCAM::DCAMPROP_SENSORMODE__SLIT,
        SENSOR_MODE_LINE= DCAM::DCAMPROP_SENSORMODE__LINE,
        SENSOR_MODE_TDI= DCAM::DCAMPROP_SENSORMODE__TDI,
        SENSOR_MODE_FRAMING= DCAM::DCAMPROP_SENSORMODE__FRAMING,
        SENSOR_MODE_PARTIAL_AREA = DCAM::DCAMPROP_SENSORMODE__PARTIALAREA,
        SENSOR_MODE_SLIT_LINE = DCAM::DCAMPROP_SENSORMODE__SLITLINE,
        SENSOR_MODE_TDI_EXTENDED = DCAM::DCAMPROP_SENSORMODE__TDI_EXTENDED,
        SENSOR_MODE_PANORAMIC = DCAM::DCAMPROP_SENSORMODE__PANORAMIC,
        SENSOR_MODE_PROGRESSIVE = DCAM::DCAMPROP_SENSORMODE__PROGRESSIVE,
        SENSOR_MODE_SPLIT_VIEW = DCAM::DCAMPROP_SENSORMODE__SPLITVIEW,
        SENSOR_MODE_DUAL_LIGHTSHEET = DCAM::DCAMPROP_SENSORMODE__DUALLIGHTSHEET,
    };

    explicit OrcaFlash(QObject *parent = nullptr);
    virtual ~OrcaFlash();
    void open(const int index);
    void open(const QString &idStr);
    bool isOpen() const;
    void close();
    const DCAM::ModelInfo *modelInfo();

    void setNFramesInBuffer(const int32_t count);
    int32_t nFramesInBuffer() const;

    void startCapture();
    void stop();

    void copyFrame(void * const buf, const size_t n, const int32_t frame,
                   int32_t *frameStamp = nullptr,
                   DCAM::DCAM_TIMESTAMP *timestamp = nullptr);
    void lockFrame(const int32_t frame, void **buf,
                   int32_t *frameStamp = nullptr,
                   DCAM::DCAM_TIMESTAMP *timestamp = nullptr);
    void lockFrame(DCAM::DCAMBUF_FRAME *dcambufFrame);
    void copyLastFrame(void * const buf, const size_t n);
    DCAM::int32 wait(const DCAM::int32 timeout_ms, const DCAM::int32 eventMask);

    void buf_release();
    void buf_alloc(const int32_t nFrames);
    void cap_start();
    void cap_stop();

    double getExposureTime();
    double setGetExposureTime(const double sec);
    void setExposureTime(const double sec);

    ORCA_TRIGGER_MODE getTriggerMode();
    void setTriggerMode(const ORCA_TRIGGER_MODE mode);
    void setTriggerSource(const ORCA_TRIGGERSOURCE source);

    ORCA_TRIGGER_POLARITY getTriggerPolarity();
    void setTriggerPolarity(const ORCA_TRIGGER_POLARITY polarity);

    ORCA_CAPSTATUS getStatus();
    QString getStatusString();
    static QString statusString(const ORCA_CAPSTATUS status);
    void logStatusString();

    double setGetPropertyValue(DCAM::_DCAMIDPROP property, const double value);
    double getPropertyValue(DCAM::_DCAMIDPROP property);
    void setPropertyValue(DCAM::_DCAMIDPROP property, const double value);
    double getLineInterval();
    void setOutputTrigger(const ORCA_OUTPUT_TRIGGER_KIND kind,
                          const ORCA_OUTPUT_TRIGGER_SOURCE source,
                          const double polarity, const double period);
    void setSensorMode(const ORCA_SENSOR_MODE mode);
    int nOfLines() const;

    int32_t getImageWidth();
    int32_t getImageHeight();

    QState *getIdleState() const;
    QState *getClosedState() const;
    QState *getCapturingState() const;

    int getCameraIndex() const;

signals:
    void opened();
    void closed();
    void captureStarted();
    void stopped();

public slots:

private:
    DCAM::HDCAM h;
    int cameraIndex;
    double exposureTime;

    QMutex mutex;
    int32_t _nFramesInBuffer;
    bool _isOpen;

    QState *idleState;
    QState *closedState;
    QState *capturingState;

    void setupStateMachine();

    void throw400(const DCAM::DCAMERR err);
};

#endif // ORCAFLASH_H
