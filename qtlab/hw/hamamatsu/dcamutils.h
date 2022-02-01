#ifndef DCAMUTILS_H
#define DCAMUTILS_H

#include <QString>

namespace DCAM {
#include <dcamapi4.h>
#include <dcamprop.h>

struct ModelInfo
{
    QString vendor;
    QString model;
    QString bus;
    QString cameraID;
    QString cameraVersion;
    QString driverVersion;
};

int init_dcam();
void uninit_dcam();

QString errString(DCAMERR err);

QString getDevString(const HDCAM index, const int32_t iString);
ModelInfo *getModelInfo(const size_t index);

size_t getCameraIndex(const QString idStr);
} // namespace DCAM

#endif // DCAMUTILS_H
