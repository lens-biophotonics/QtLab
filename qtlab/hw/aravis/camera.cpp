#include <QStateMachine>

#include <qtlab/hw/aravis/aravis.h>
#include <qtlab/hw/aravis/camera.h>

#include <qtlab/core/logger.h>

using namespace Aravis;

static Logger *logger = getLogger("Aravis::Camera");

Camera::Camera(QObject *parent) : QObject(parent)
{
    camera = nullptr;
    stream = nullptr;
    dd = nullptr;
    streamcb = nullptr;
    setupStateMachine();
    setStreamCb(this->cb);
}

Camera::~Camera()
{
    stopAcquisition();
    close();
    if (dd)
        delete dd;
    g_clear_object(&stream);
    g_clear_object(&camera);
}

void Camera::setupStateMachine()
{
    idleState = new QState();
    closedState = new QState();
    capturingState = new QState();

    idleState->addTransition(this, &Camera::closed, closedState);
    idleState->addTransition(this, &Camera::captureStarted, capturingState);

    capturingState->addTransition(this, &Camera::stopped, idleState);

    closedState->addTransition(this, &Camera::opened, idleState);

    QStateMachine *sm = new QStateMachine();

    sm->addState(idleState);
    sm->addState(closedState);
    sm->addState(capturingState);

    sm->setInitialState(closedState);
    sm->start();
}

void Camera::setLastBuffer(const char *data, size_t bufSize)
{
    lastBuffer.data = data;
    lastBuffer.size = bufSize;
}

bool Camera::open(const QString devID)
{
    auto dds = getDeviceDescriptors();
    foreach (const DeviceDescriptor * dd, dds) {
        if (dd->ID.compare(devID) == 0)
            return open(dd);
    }
    return false;
}

bool Camera::open(int n)
{
    auto dds = getDeviceDescriptors();
    if (dds.size() <= n)
        return false;
    const DeviceDescriptor *dd = dds.at(n);
    return open(dd);
}

bool Camera::open(const DeviceDescriptor *dd)
{
    if (_isOpen) {
        return true;
    }
    GError *error = nullptr;
    const QString devID = dd->ID;
    const QString prova(devID.toStdString().c_str());
    camera = arv_camera_new(devID.toStdString().c_str(), &error);

    if (error) {
        logger->error(QString("Cannot open %1").arg(devID));
        return false;
    }

    if (!ARV_IS_CAMERA(camera)) {
        return false;
    }

    logger->info(QString("Opened %1 %2 %3").arg(devID, dd->model, dd->vendor));

    this->dd = new DeviceDescriptor(*dd);

    emit opened();
    _isOpen = true;
    return true;
}

void Camera::close()
{
    g_clear_object(&camera);
    if (!_isOpen) {
        return;
    }
    camera = nullptr;
    _isOpen = false;
    logger->info(QString("Closed %1 %2 %3").arg(dd->ID, dd->model, dd->vendor));
    delete dd;
    dd = nullptr;
}

void Camera::startAcquisition()
{
    arv_camera_set_pixel_format_from_string(
        camera, pixelFormat.toStdString().c_str(), nullptr);
    arv_camera_set_frame_rate(camera, frameRate, nullptr);
    stream = arv_camera_create_stream(camera, streamcb, this, nullptr);
    auto payload = arv_camera_get_payload(camera, nullptr);
    lastBuffer.size = payload;
    for (int i = 0; i < 5; i++)
        arv_stream_push_buffer(stream, arv_buffer_new(payload, nullptr));
    arv_camera_start_acquisition(camera, nullptr);
    emit captureStarted();
}

void Camera::cb(void *user_data, ArvStreamCallbackType type, ArvBuffer *buffer)
{
    Camera *camera = static_cast<Camera*>(user_data);
    if (!ARV_IS_STREAM(camera->stream))
        return;
    ArvBuffer *abuf;
    const char *data;
    size_t bufSize;
    switch (type) {
    case ARV_STREAM_CALLBACK_TYPE_BUFFER_DONE:
        abuf = arv_stream_pop_buffer(camera->stream);

        data = (const char *)arv_buffer_get_data(buffer, &bufSize);
        camera->setLastBuffer(data, bufSize);

        arv_stream_push_buffer(camera->stream, abuf);
        break;
    default:
        break;
    }
}

void Camera::stopAcquisition()
{
    if (!ARV_IS_CAMERA(camera))
        return;
    arv_camera_stop_acquisition(camera, nullptr);
    emit stopped();
    g_clear_object(&stream);
}

const Aravis::Camera::Buffer *Camera::getLastBuffer() const
{
    return &lastBuffer;
}

double Camera::getFrameRate() const
{
    return frameRate;
}

void Camera::setFrameRate(double Hz)
{
    frameRate = Hz;
}

QString Camera::getPixelFormat() const
{
    return pixelFormat;
}

void Camera::setPixelFormat(const QString &value)
{
    pixelFormat = value;
}

void Camera::setStreamCb(const ArvStreamCallback &value)
{
    streamcb = value;
}

const DeviceDescriptor *Camera::deviceDescriptor() const
{
    return dd;
}

const QStringList Camera::supportedPixelFormats() const
{
    guint n;
    QStringList sl;
    const char **p =
        arv_camera_dup_available_pixel_formats_as_strings(camera, &n, nullptr);
    for (guint i = 0; i < n; ++i) {
        sl << QString(p[i]);
    }
    return sl;
}

QSize Camera::pictureSize() const
{
    gint w, h;
    arv_camera_get_width_bounds(camera, nullptr, &w, nullptr);
    arv_camera_get_height_bounds(camera, nullptr, &h, nullptr);
    return QSize(w, h);
}
