#include "tiffwriter.h"

// see https://schneide.blog/2015/11/16/multi-page-tiffs-with-cpp/

TIFFWriter::TIFFWriter(QString filename, bool multiPage, const char *mode, QObject *parent)
    : QObject(parent)
    , multiPage(multiPage)
    , page(0)
{
    tiff = TIFFOpen(filename.toLatin1(), mode);
}

void TIFFWriter::write(const qint8 *buffer, size_t width, size_t height, size_t samplesPerPixel)
{
    TIFFSetField(tiff, TIFFTAG_SAMPLEFORMAT, SAMPLEFORMAT_INT);
    write((const char *) (buffer), width, height, samplesPerPixel, sizeof(qint8));
}

void TIFFWriter::write(const quint8 *buffer, size_t width, size_t height, size_t samplesPerPixel)
{
    TIFFSetField(tiff, TIFFTAG_SAMPLEFORMAT, SAMPLEFORMAT_UINT);
    write((const char *) (buffer), width, height, samplesPerPixel, sizeof(quint8));
}

void TIFFWriter::write(const qint16 *buffer, size_t width, size_t height, size_t samplesPerPixel)
{
    TIFFSetField(tiff, TIFFTAG_SAMPLEFORMAT, SAMPLEFORMAT_INT);
    write((const char *) (buffer), width, height, samplesPerPixel, sizeof(qint16));
}

void TIFFWriter::write(const quint16 *buffer, size_t width, size_t height, size_t samplesPerPixel)
{
    TIFFSetField(tiff, TIFFTAG_SAMPLEFORMAT, SAMPLEFORMAT_UINT);
    write((const char *) (buffer), width, height, samplesPerPixel, sizeof(quint16));
}

void TIFFWriter::write(const float *buffer, size_t width, size_t height, size_t samplesPerPixel)
{
    TIFFSetField(tiff, TIFFTAG_SAMPLEFORMAT, SAMPLEFORMAT_IEEEFP);
    write((const char *) (buffer), width, height, samplesPerPixel, 4);
}

void TIFFWriter::write(
    const char *buffer, size_t width, size_t height, size_t samplesPerPixel, size_t sizeOfType)
{
    if (multiPage) {
        TIFFSetField(tiff, TIFFTAG_PAGENUMBER, page, page);
        TIFFSetField(tiff, TIFFTAG_SUBFILETYPE, FILETYPE_PAGE);
    }
    TIFFSetField(tiff, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
    TIFFSetField(tiff, TIFFTAG_IMAGEWIDTH, width);
    TIFFSetField(tiff, TIFFTAG_IMAGELENGTH, height);
    TIFFSetField(tiff, TIFFTAG_ROWSPERSTRIP, TIFFDefaultStripSize(tiff, (unsigned int) -1));

    size_t bitsPerSample = 8 * sizeOfType;
    TIFFSetField(tiff, TIFFTAG_BITSPERSAMPLE, bitsPerSample);
    TIFFSetField(tiff, TIFFTAG_SAMPLESPERPIXEL, samplesPerPixel);

    size_t stride = width * samplesPerPixel * sizeOfType;
    for (size_t y = 0; y < height; ++y) {
        TIFFWriteScanline(tiff, (void *) (buffer + y * stride), y, 0);
    }

    TIFFWriteDirectory(tiff);
    page++;
}

TIFFWriter::~TIFFWriter()
{
    TIFFClose(tiff);
}
