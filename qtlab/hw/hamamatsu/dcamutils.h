#ifndef DCAMUTILS_H
#define DCAMUTILS_H

#include <QString>

#ifndef DCAM_VERSION
#define DCAM_VERSION 400
#endif

namespace DCAM {
#include <dcamapi4.h>
#include <dcamprop.h>

struct ModelInfo {
    QString vendor;
    QString model;
    QString bus;
    QString cameraID;
    QString cameraVersion;
    QString driverVersion;
};

int init_dcam();
void uninit_dcam();

QString errString(uint err);

ModelInfo *getModelInfo(const size_t index);
size_t getCameraIndex(const QString idStr);
}

#endif // DCAMUTILS_H
