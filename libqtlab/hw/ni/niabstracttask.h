/** @file */

/**
 * \defgroup NationalInstruments National Instruments
 * @brief National Instruments related classes.
 * \ingroup Hardware
 */

#ifndef NIABSTRACTTASK_H
#define NIABSTRACTTASK_H

/**
 * \brief Wraps the call to the given function around some logic for error
 * checking
 *
 * If an error has occurred during the function call, NIAbstractTask::onError()
 * is called.
 *
 * \param functionCall The function to be called
 */

#ifdef WITH_HARDWARE
#define DAQmxErrChk(functionCall) {                                         \
        if (!task) {                                                        \
            throw std::runtime_error("Task not initialized");               \
        }                                                                   \
        int ret = functionCall;                                             \
        if (DAQmxFailed(ret)) {                                             \
            logger->error(QString("Error %1").arg(ret));                    \
            onError();                                                      \
        }                                                                   \
}
#else
#define DAQmxErrChk(functionCall) {}
#endif

#include <QObject>

#include <libqtlab/hw/ni/natinst.h>

using namespace NI;

/**
 * @brief The NIAbstractTask class is an abstract wrapper for a DAQmx Task.
 *
 * \ingroup NationalInstruments
 */

class NIAbstractTask : public QObject
{
    Q_OBJECT
public:
    explicit NIAbstractTask(QObject *parent = nullptr);
    virtual ~NIAbstractTask();

    bool isInitialized();
    bool isTaskDone();

    QString getTaskName() const;
    void setTaskName(const QString &value);

    void appendToTaskName(const QString &suffix);
    void configureSampleClockTiming(const QString &source,
                                    int32 activeEdge,
                                    int32 sampleMode);

    double getSampleRate() const;
    void setSampleRate(double value);

    uInt64 getNSamples() const;
    void setNSamples(const uInt64 &value);

    QStringList getPhysicalChannels() const;
    QString getPhysicalChannel(const int number) const;
    void setPhysicalChannels(const QStringList &channels);

    QString getTriggerTerm() const;
    void setTriggerTerm(const QString &value);

    virtual void configureTriggering();

    int32 getTriggerEdge() const;
    void setTriggerEdge(const int32 &value);

    void exportSignal(const int32 signalID, const QString &terminals);
    void exportSignal(const int32 signalID, const QStringList &terminals);

signals:
    void error();
    void started();
    void stopped();

public slots:
    void initializeTask();
    void start();
    void stop();
    void clear();

protected:
    [[ noreturn ]] void onError() const;
    virtual void setPhysicalChannels_impl() {}

    TaskHandle task = nullptr;
    uInt64 nSamples;
    QStringList physicalChannels;
    QString triggerTerm;
    int32 triggerEdge = DAQmx_Val_Rising;

private:
    virtual void initializeTask_impl() = 0;

    char *errBuff;
    QString taskName;
    double sampleRate;
};

#endif // NIABSTRACTTASK_H
