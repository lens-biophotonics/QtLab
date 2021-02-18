#include <qtlab/hw/ni/natinst.h>
#include <qtlab/core/logger.h>

using namespace NI;

static Logger *logger = getLogger("NI");

QStringList NI::getDevicesInSystem()
{
    QStringList list;
#ifdef WITH_HARDWARE
    char buf[2048];
    if (DAQmxFailed(DAQmxGetSysDevNames(buf, 2048))) {
        DAQmxGetExtendedErrorInfo(buf, 2048);
        logger->critical(buf);
        return list;
    }
    list = QString(buf).split(", ");
#endif
    return list;
}

#ifdef WITH_HARDWARE
typedef int32 (*daqmx_f_ptr)(const char*, char*, uInt32);

static QStringList getList(daqmx_f_ptr myfp)
{
    QStringList list;
    char buf[2048];
    QStringList devList = NI::getDevicesInSystem();
    QStringListIterator devIt(devList);
    while (devIt.hasNext()) {
        QString dev = devIt.next();
        if (DAQmxFailed(myfp(dev.toLatin1(), buf, 2048))) {
            DAQmxGetExtendedErrorInfo(buf, 2048);
            logger->critical(buf);
            return list;
        };
        QStringList cl = QString(buf).split(", ");
        list.append(cl);
    }
    return list;
}
#endif

#ifdef WITH_HARDWARE
#define DEF_NI_GET_FUNCTION(funcName, DAQmxFuncName)                        \
    QStringList NI::funcName() {                                            \
        return getList(&DAQmxFuncName);                                     \
    }
#else
#define DEF_NI_GET_FUNCTION(funcName, DAQmxFuncNAme)                        \
    QStringList NI::funcName() {                                            \
        return QStringList();                                               \
    }
extern "C" {
int32 __CFUNC     DAQmxLoadTask (const char taskName[], TaskHandle *taskHandle) {return 0;};
int32 __CFUNC     DAQmxCreateTask (const char taskName[], TaskHandle *taskHandle) {return 0;};
#include "NIDAQmx_dummy.cpp"
}
#endif

DEF_NI_GET_FUNCTION(getAOPhysicalChans, DAQmxGetDevAOPhysicalChans)
DEF_NI_GET_FUNCTION(getAIPhysicalChans, DAQmxGetDevAIPhysicalChans)
DEF_NI_GET_FUNCTION(getCOPhysicalChans, DAQmxGetDevCOPhysicalChans)
DEF_NI_GET_FUNCTION(getCIPhysicalChans, DAQmxGetDevCIPhysicalChans)
DEF_NI_GET_FUNCTION(getDILines, DAQmxGetDevDILines)
DEF_NI_GET_FUNCTION(getDIPorts, DAQmxGetDevDIPorts)
DEF_NI_GET_FUNCTION(getDOLines, DAQmxGetDevDOLines)
DEF_NI_GET_FUNCTION(getDOPorts, DAQmxGetDevDOPorts)
DEF_NI_GET_FUNCTION(getTerminals, DAQmxGetDevTerminals)

/**
 * @brief Transform a PFI terminal to a port/line string.
 * @param term
 * @return
 *
 * Example: /Dev1/PFI15 -> Dev1/port2/line7
 *
 * An null QString is returned in case of errors. The returned string might not be correct for some
 * boards.
 */

QString NI::PFI2Line(QString term)
{
    int idx = term.indexOf("PFI");
    if (idx == -1 || !term.startsWith("/")) return QString();
    bool ok = false;
    int pfi = term.mid(idx + 3).toInt(&ok);
    if (!ok) return QString();
    int port = pfi / 8 + 1;
    int line = pfi % 8;
    term.truncate(idx);
    return term.mid(1).append(QString("port%1/line%2").arg(port).arg(line));
}
