#ifndef CAMERA_H
#define CAMERA_H

// avoid conflict with Qt's signal keyword
#undef signals
#include <aravis-0.8/arv.h>
#define signals Q_SIGNALS

#include <QObject>
#include <QState>
#include <QSize>

namespace Aravis {
struct DeviceDescriptor;

class Camera : public QObject
{
    Q_OBJECT
public:
    typedef struct {
        const void *data = nullptr;
        size_t size;
    } Buffer;

    explicit Camera(QObject *parent = nullptr);
    virtual ~Camera();

    bool open(const QString devID);
    bool open(int n);
    bool open(const DeviceDescriptor *dd);

    void close();

    const DeviceDescriptor *deviceDescriptor() const;
    const QStringList supportedPixelFormats() const;
    QSize pictureSize() const;

    void setStreamCb(const ArvStreamCallback &value);

    QString getPixelFormat() const;
    void setPixelFormat(const QString &value);

    double getFrameRate() const;
    void setFrameRate(double Hz);

    const Buffer *getLastBuffer() const;

signals:
    void opened();
    void closed();
    void stopped();
    void captureStarted();

public slots:
    void startAcquisition();
    void stopAcquisition();

private:
    ArvCamera *camera;
    ArvStream *stream;
    ArvStreamCallback streamcb;
    DeviceDescriptor *dd;
    QString pixelFormat;

    QState *idleState;
    QState *closedState;
    QState *capturingState;

    bool _isOpen = false;
    double frameRate = 25;
    Buffer lastBuffer;

    void setupStateMachine();
    void setLastBuffer(const char *data, size_t bufSize);
    static void cb(void *user_data, ArvStreamCallbackType type,
                   ArvBuffer *buffer);
};
} // namespace Aravis


#endif // CAMERA_H
