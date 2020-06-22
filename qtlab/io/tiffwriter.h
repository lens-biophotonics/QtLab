#ifndef TIFFWRITER_H
#define TIFFWRITER_H

#include <QObject>
#include <tiffio.h>

class TIFFWriter : public QObject
{
    Q_OBJECT
public:
    explicit TIFFWriter(QString filename, bool multiPage,
                        const char *mode = "w", QObject *parent = nullptr);
    ~TIFFWriter();

    void write(const qint8* buffer, size_t width, size_t height, size_t samplesPerPixel);
    void write(const quint8* buffer, size_t width, size_t height, size_t samplesPerPixel);
    void write(const qint16 *buffer, size_t width, size_t height, size_t samplesPerPixel);
    void write(const quint16 *buffer, size_t width, size_t height, size_t samplesPerPixel);
    void write(const float *buffer, size_t width, size_t height, size_t samplesPerPixel);
    void write(const char *buffer, size_t width, size_t height,
               size_t samplesPerPixel, size_t sizeOfType);

private:
    TIFF* tiff;
    bool multiPage;
    unsigned int page;
};

#endif // TIFFWRITER_H
