#include <QStateMachine>
#include <QMutexLocker>

#include <qtlab/hw/hamamatsu/orcaflash.h>
#include <qtlab/core/logger.h>

#define FUNCNAME(x) # x
#ifdef WITH_HARDWARE

#define CALL_THROW_400(functionCall)                                        \
    {                                                                       \
        DCAM::DCAMERR err;                                                  \
        {                                                                   \
            QMutexLocker ml(&mutex);                                        \
            err = functionCall;                                             \
        }                                                                   \
        throw400(err);                                                      \
    }
#else
#define CALL_THROW_400(func)
#endif

static Logger *logger = getLogger("OrcaFlash");

using namespace DCAM;

#define EXCEPTION_CONSTRUCTOR(name)                                         \
    OrcaFlash::name::name() : std::runtime_error(FUNCNAME(name)) {}

EXCEPTION_CONSTRUCTOR(OrcaBusyException)
EXCEPTION_CONSTRUCTOR(OrcaNotReadyException)
EXCEPTION_CONSTRUCTOR(OrcaNotStableException)
EXCEPTION_CONSTRUCTOR(OrcaUnstableException)
EXCEPTION_CONSTRUCTOR(OrcaNotBusyException)


OrcaFlash::OrcaFlash(QObject *parent) : QObject(parent)
{
    _isOpen = false;
    setNFramesInBuffer(10);
    setupStateMachine();
}

OrcaFlash::~OrcaFlash()
{
    close();
}

void OrcaFlash::setupStateMachine()
{
    idleState = new QState();
    closedState = new QState();
    capturingState = new QState();

    idleState->addTransition(this, &OrcaFlash::closed, closedState);
    idleState->addTransition(this, &OrcaFlash::captureStarted, capturingState);

    capturingState->addTransition(this, &OrcaFlash::stopped, idleState);

    closedState->addTransition(this, &OrcaFlash::opened, idleState);

    QStateMachine *sm = new QStateMachine();

    sm->addState(idleState);
    sm->addState(closedState);
    sm->addState(capturingState);

    sm->setInitialState(closedState);
    sm->start();
}

void OrcaFlash::throw400(const DCAMERR err)
{
    switch (err) {
    case DCAMERR_SUCCESS:
        return;
    case DCAMERR_BUSY:
        throw OrcaBusyException();
    case DCAMERR_NOTREADY:
        throw OrcaNotReadyException();
    case DCAMERR_NOTSTABLE:
        throw OrcaNotStableException();
    case DCAMERR_UNSTABLE:
        throw OrcaUnstableException();
    case DCAMERR_NOTBUSY:
        throw OrcaNotBusyException();
    default:
        throw std::runtime_error(DCAM::getDevString(h, err).toStdString());
    }
}

QState *OrcaFlash::getIdleState() const
{
    return idleState;
}

QState *OrcaFlash::getClosedState() const
{
    return closedState;
}

QState *OrcaFlash::getCapturingState() const
{
    return capturingState;
}

int OrcaFlash::getCameraIndex() const
{
    return cameraIndex;
}

void OrcaFlash::open(const int index)
{
    if (_isOpen) {
        return;
    }

    DCAMDEV_OPEN param;
    memset (&param, 0, sizeof(param));

    param.index = index;
    param.size = sizeof(param);
    CALL_THROW_400(dcamdev_open(&param));
    h = param.hdcam;

    logger->info(QString("Camera %1 opened").arg(index));
    _isOpen = true;
    cameraIndex = index;
    emit opened();
}

void OrcaFlash::open(const QString &idStr)
{
    open(DCAM::getCameraIndex(idStr));
}

bool OrcaFlash::isOpen() const
{
    return _isOpen;
}

void OrcaFlash::close()
{
    if (!_isOpen) {
        return;
    }
    CALL_THROW_400(dcamdev_close(h))
    _isOpen = false;
    emit closed();
}

const ModelInfo *OrcaFlash::modelInfo()
{
    return getModelInfo(cameraIndex);
}

void OrcaFlash::setNFramesInBuffer(const int32_t count)
{
    _nFramesInBuffer = count;
}

int32_t OrcaFlash::nFramesInBuffer() const
{
    return _nFramesInBuffer;
}

double OrcaFlash::setGetPropertyValue(const _DCAMIDPROP property, const double value)
{
#ifndef WITH_HARDWARE
    Q_UNUSED(property)
#endif
    double temp = value;
    CALL_THROW_400(dcamprop_setgetvalue(h, static_cast<int32>(property), &temp));
    return temp;
}

double OrcaFlash::getPropertyValue(const _DCAMIDPROP property)
{
#ifndef WITH_HARDWARE
    Q_UNUSED(property)
#endif
    double ret = 0;
    CALL_THROW_400(dcamprop_getvalue(h, static_cast<int32>(property), &ret));
    return ret;
}

void OrcaFlash::setPropertyValue(const _DCAMIDPROP property, const double value)
{
    CALL_THROW_400(dcamprop_setvalue(h, static_cast<int32>(property), value));
#ifndef WITH_HARDWARE
    Q_UNUSED(property)
    Q_UNUSED(value)
#endif
}

double OrcaFlash::getLineInterval()
{
#ifdef WITH_HARDWARE
    return getPropertyValue(DCAM_IDPROP_INTERNAL_LINEINTERVAL);
#else
    return 0.01;
#endif
}

void OrcaFlash::setOutputTrigger(
    const OrcaFlash::ORCA_OUTPUT_TRIGGER_KIND kind,
    const OrcaFlash::ORCA_OUTPUT_TRIGGER_SOURCE source,
    const double polarity, const double period)
{
    setPropertyValue(DCAM_IDPROP_OUTPUTTRIGGER_KIND, kind);
    setPropertyValue(DCAM_IDPROP_OUTPUTTRIGGER_SOURCE, source);
    setPropertyValue(DCAM_IDPROP_OUTPUTTRIGGER_POLARITY, polarity);
    setPropertyValue(DCAM_IDPROP_OUTPUTTRIGGER_PERIOD, period);
}

void OrcaFlash::setSensorMode(const OrcaFlash::ORCA_SENSOR_MODE mode)
{
    setPropertyValue(DCAM_IDPROP_SENSORMODE, mode);
}

int OrcaFlash::nOfLines() const
{
    return 2048;
}

int32_t OrcaFlash::getImageWidth()
{
    return static_cast<int32_t>(getPropertyValue(DCAM_IDPROP_IMAGE_WIDTH));
}

int32_t OrcaFlash::getImageHeight()
{
    return static_cast<int32_t>(getPropertyValue(DCAM_IDPROP_IMAGE_HEIGHT));
}

void OrcaFlash::startCapture()
{
    buf_release();
    buf_alloc(_nFramesInBuffer);
    cap_start();
    emit captureStarted();
}

void OrcaFlash::copyFrame(void * const buf, const size_t n,
                          const int32_t frame, int32_t *frameStamp,
                          DCAM_TIMESTAMP *timestamp)
{
#ifndef WITH_HARDWARE
    Q_UNUSED(frame)
    Q_UNUSED(frameStamp)
    Q_UNUSED(timestamp)
    int k = n / (sizeof (int) * 64);

    char *p = (char *)buf;

    size_t b = n / k;
    size_t tot = 0;

    for (int i = 0; i < k; ++i) {
        memset(p, rand(), b);
        p += b;
        tot += b;
    }
    memset(p, rand(), n - tot);
    return;
#else
    DCAMBUF_FRAME dcamframe;

    memset(&dcamframe, 0, sizeof(dcamframe));
    dcamframe.size = sizeof(dcamframe);
    dcamframe.iFrame = frame;

    dcamframe.buf = buf;
    dcamframe.width = getImageWidth();
    dcamframe.height = getImageHeight();
    dcamframe.rowbytes = static_cast<int32_t>(
        getPropertyValue(DCAM_IDPROP_IMAGE_ROWBYTES));
    dcamframe.left = 0;
    dcamframe.top = 0;

    CALL_THROW_400(dcambuf_copyframe(h, &dcamframe));

    if (frameStamp != nullptr) {
        *frameStamp = dcamframe.framestamp;
    }

    if (timestamp != nullptr) {
        *timestamp = dcamframe.timestamp;
    }
#endif
}

void OrcaFlash::lockFrame(const int32_t frame, void **buf, int32_t *frameStamp,
                          DCAM_TIMESTAMP *timestamp)
{
    DCAMBUF_FRAME dcamframe;

    memset(&dcamframe, 0, sizeof(dcamframe));
    dcamframe.size = sizeof(dcamframe);
    dcamframe.iFrame = frame;

    dcamframe.width = getImageWidth();
    dcamframe.height = getImageHeight();
    dcamframe.rowbytes = static_cast<int32_t>(
        getPropertyValue(DCAM_IDPROP_IMAGE_ROWBYTES));
    dcamframe.left = 0;
    dcamframe.top = 0;

    lockFrame(&dcamframe);

    *buf = dcamframe.buf;
    if (frameStamp != nullptr) {
#ifdef WITH_HARDWARE
        *frameStamp = dcamframe.framestamp;
#else
        *frameStamp = frame;
#endif
    }
    if (timestamp != nullptr) {
        *timestamp = dcamframe.timestamp;
    }
}

void OrcaFlash::lockFrame(DCAMBUF_FRAME *dcambufFrame)
{
#ifndef WITH_HARDWARE
    Q_UNUSED(dcambufFrame)
#endif
    CALL_THROW_400(dcambuf_lockframe(h, dcambufFrame));
}

void OrcaFlash::copyLastFrame(void * const buf, const size_t n)
{
    copyFrame(buf, n, -1, nullptr, nullptr);
}

int32 OrcaFlash::wait(const int32 timeout_ms, const int32 eventMask)
{
    DCAMWAIT_OPEN dwOpen;
    dwOpen.size = sizeof(DCAMWAIT_OPEN);
    dwOpen.hdcam = h;

    CALL_THROW_400(dcamwait_open(&dwOpen));

    DCAMWAIT_START dwStart;
    dwStart.size = sizeof(DCAMWAIT_START);
    dwStart.eventmask = eventMask;
    dwStart.timeout = timeout_ms;

    CALL_THROW_400(dcamwait_start(dwOpen.hwait, &dwStart));

    CALL_THROW_400(dcamwait_close(dwOpen.hwait));

    return dwStart.eventhappened;
}

void OrcaFlash::buf_release()
{
    CALL_THROW_400(dcambuf_release(h));
}

void OrcaFlash::buf_alloc(const int32_t nFrames)
{
    setNFramesInBuffer(nFrames);
    CALL_THROW_400(dcambuf_alloc(h, nFrames));
}

void OrcaFlash::cap_start()
{
    CALL_THROW_400(dcamcap_start(h, DCAMCAP_START_SEQUENCE));
    emit captureStarted();
}

void OrcaFlash::cap_stop()
{
    CALL_THROW_400(dcamcap_stop(h));
    emit stopped();
}

double OrcaFlash::getExposureTime()
{
#ifndef WITH_HARDWARE
    exposureTime = 0.1;
#endif
    exposureTime = getPropertyValue(DCAM_IDPROP_EXPOSURETIME);
    return exposureTime;
}

double OrcaFlash::setGetExposureTime(const double sec)
{
    return setGetPropertyValue(DCAM_IDPROP_EXPOSURETIME, sec);
}

void OrcaFlash::setExposureTime(const double sec)
{
    setPropertyValue(DCAM_IDPROP_EXPOSURETIME, sec);
}

OrcaFlash::ORCA_TRIGGER_MODE OrcaFlash::getTriggerMode()
{
    return static_cast<ORCA_TRIGGER_MODE>(
        getPropertyValue(DCAM_IDPROP_TRIGGER_MODE));
}

void OrcaFlash::setTriggerMode(const ORCA_TRIGGER_MODE mode)
{
    setPropertyValue(DCAM_IDPROP_TRIGGER_MODE, mode);
}

void OrcaFlash::setTriggerSource(const OrcaFlash::ORCA_TRIGGERSOURCE source)
{
    setPropertyValue(DCAM_IDPROP_TRIGGERSOURCE, source);
}

OrcaFlash::ORCA_TRIGGER_POLARITY OrcaFlash::getTriggerPolarity()
{
    return static_cast<ORCA_TRIGGER_POLARITY>(
        getPropertyValue(DCAM_IDPROP_TRIGGERPOLARITY));
}

void OrcaFlash::setTriggerPolarity(
    const OrcaFlash::ORCA_TRIGGER_POLARITY polarity)
{
    setPropertyValue(DCAM_IDPROP_TRIGGERPOLARITY, polarity);
}

OrcaFlash::ORCA_CAPSTATUS OrcaFlash::getStatus()
{
    int32 status = 0;
    CALL_THROW_400(dcamcap_status(h, &status))
    return static_cast<ORCA_CAPSTATUS>(status);
}

QString OrcaFlash::getStatusString()
{
    return statusString(getStatus());
}

QString OrcaFlash::statusString(const OrcaFlash::ORCA_CAPSTATUS status)
{
    switch (status) {
    case OrcaFlash::CAPSTATUS_BUSY:
        return "busy";
    case OrcaFlash::CAPSTATUS_ERROR:
        return "error";
    case OrcaFlash::CAPSTATUS_READY:
        return "ready";
    case OrcaFlash::CAPSTATUS_STABLE:
        return "stable";
    case OrcaFlash::CAPSTATUS_UNSTABLE:
        return "unstable";
    }
    throw std::runtime_error("Invalid CAPSTATUS");
}

void OrcaFlash::logStatusString()
{
    logger->info(QString("Camera status: %1").arg(getStatusString()));
}
