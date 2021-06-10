#include <qtlab/hw/ni/nitask.h>
#include <qtlab/core/logger.h>

using namespace NI;

static Logger *logger = getLogger("NI");

#define ERRBUF_SIZE 2048

NITask::NITask(QObject *parent) : QObject(parent)
{
    errBuff = new char[ERRBUF_SIZE];
}

NITask::~NITask()
{
    if (isInitialized())
        clearTask();
    delete[] errBuff;
}

void NITask::createTask(QString taskName)
{
    this->taskName = taskName;
    DAQmxErrChk(DAQmxCreateTask(this->taskName.toLatin1(), &task));
}

bool NITask::isInitialized()
{
    return task != nullptr;
}

/**
 * @brief Recovers the string description of the last occurred error and throws
 * a std::runtime_error exception.
 */

void NITask::onError() const
{
#ifdef WITH_HARDWARE
    DAQmxGetExtendedErrorInfo(errBuff, ERRBUF_SIZE);
#endif
    logger->critical(errBuff);
    throw std::runtime_error(errBuff);
}

uInt64 NITask::getSampsPerChan() const
{
    return sampsPerChan;
}

void NITask::setSampsPerChan(const uInt64 &value)
{
    sampsPerChan = value;
}

QString NITask::getSampClkTimingSource() const
{
    return sampClkTimingSource;
}

void NITask::setSampClkTimingSource(const QString &value)
{
    sampClkTimingSource = value;
}

QString NITask::getTriggerTerm() const
{
    return triggerTerm;
}

void NITask::setTriggerTerm(const QString &value)
{
    triggerTerm = value;
}

void NITask::initializeTask()
{
    initializeTask_impl();
}

void NITask::configureChannels()
{
    configureChannels_impl();
}

void NITask::configureTiming()
{
    configureTiming_impl();
}

void NITask::configureTriggering()
{
    configureTriggering_impl();
}

void NITask::initializeTask_impl()
{
    if (isInitialized()) {
        clearTask();
    }
    createTask();
    configureChannels();
    configureTiming();
    configureTriggering();
}

void NITask::setTaskName(const QString &value)
{
    taskName = value;
}

double NITask::getSampleRate() const
{
    return sampleRate;
}

void NITask::setSampleRate(double value)
{
    sampleRate = value;
}

QStringList NITask::getPhysicalChannels() const
{
    return physicalChannels;
}

void NITask::setPhysicalChannels(const QStringList &value)
{
    physicalChannels = value;
}

int NITask::nOfChannels()
{
    return physicalChannels.count();
}

#include "NIDAQmx_wrapper_methods.cpp"
