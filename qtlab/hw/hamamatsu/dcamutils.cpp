#include <stdexcept>

#include <qtlab/core/logger.h>
#include <qtlab/hw/hamamatsu/dcamutils.h>

#include <QMap>

using namespace DCAM;

static Logger *logger = getLogger("DCAM");
static QMap<size_t, ModelInfo *> map;
static QMap<QString, size_t> mapByIDStr;

namespace DCAM {

/**
 * @brief Get string or error from device.
 * @param iString
 * @param index
 * @return
 */

QString getDevString(const HDCAM h, const int32_t iString)
{
    char buf[128];
    DCAMDEV_STRING devString;
    devString.size = sizeof(DCAMDEV_STRING);
    devString.iString = iString;
    devString.text = buf;
    devString.textbytes = 128;

#ifdef QTLAB_DCAM_DEMO
    Q_UNUSED(h)
    Q_UNUSED(iString)
#else
    // can be called without handle from dcamdev_open, using device index instead
    dcamdev_getstring(h, &devString);
#endif
    return QString(buf);
}

ModelInfo *getModelInfo(const size_t index)
{
    if (!map.contains(index)) {
        return nullptr;
    }
    return map[index];
}

size_t getCameraIndex(const QString idStr)
{
    if (!mapByIDStr.contains(idStr)) {
        return -1;
    }
    return mapByIDStr[idStr];
}

/**
 * @brief Return the error code as a hex formatted string
 * @param err
 * @return
 */

QString errString(DCAMERR err)
{
#ifdef QTLAB_DCAM_DEMO
    Q_UNREACHABLE();
    return QString("Error 0x%1").arg((uint) err, 0, 16);
#else
    return getDevString(0, err);
#endif
}

int init_dcam()
{
#ifdef QTLAB_DCAM_DEMO
    return 8;
#endif

    int nCamera;
    bool ok = false;
    DCAMAPI_INIT param;
    memset(&param, 0, sizeof(param));

    param.size = sizeof(param);
    DCAMERR ret = dcamapi_init(&param);
    ok = ret == DCAMERR_SUCCESS;

    if (!ok) {
        QString errMsg("Cannot initialize dcam. ");
        logger->critical(errMsg + errString(ret));
        throw std::runtime_error(errMsg.toStdString());
    }

    nCamera = param.iDeviceCount;

    if (nCamera == 0) {
        QString errMsg = "No cameras found";
        logger->critical(errMsg);
        throw std::runtime_error(errMsg.toStdString());
    }
    logger->info(QString("Found %1 cameras").arg(nCamera));
    for (int64_t i = 0; i < nCamera; ++i) {
        ModelInfo *mi = new ModelInfo();
        HDCAM h = (HDCAM) i;
        mi->vendor = getDevString(h, DCAM_IDSTR_VENDOR);
        mi->model = getDevString(h, DCAM_IDSTR_MODEL);
        mi->bus = getDevString(h, DCAM_IDSTR_BUS);
        mi->cameraID = getDevString(h, DCAM_IDSTR_CAMERAID);
        mi->cameraVersion = getDevString(h, DCAM_IDSTR_CAMERAVERSION);
        mi->driverVersion = getDevString(h, DCAM_IDSTR_DRIVERVERSION);
        logger->info(QString("Camera #%1 ").arg(i) + mi->vendor + " " + mi->model + " "
                     + mi->cameraID + " " + mi->cameraVersion);
        map.insert(i, mi);
        mapByIDStr.insert(mi->cameraID, i);
    }
    return nCamera;
}

void uninit_dcam()
{
#ifndef QTLAB_DCAM_DEMO
    if (dcamapi_uninit() != DCAMERR_SUCCESS)
#else
    if (false)
#endif
    {
        QString errMsg = "Cannot uninitialize dcam";
        logger->critical(errMsg);
        throw std::runtime_error(errMsg.toStdString());
    }
    qDeleteAll(map);
    map.clear();
    mapByIDStr.clear();
}
} // namespace DCAM
