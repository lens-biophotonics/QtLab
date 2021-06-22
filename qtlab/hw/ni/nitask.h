/** @file */

/**
 * \defgroup NationalInstruments National Instruments
 * @brief National Instruments related classes.
 * \ingroup Hardware
 */

#ifndef NITASK_H
#define NITASK_H

#include <stdexcept>

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
        int ret = functionCall;                                             \
        if (DAQmxFailed(ret)) {                                             \
            logger->critical(QString("Error %1").arg(ret));                    \
            onError();                                                      \
        }                                                                   \
        if (!task) {                                                        \
            throw std::runtime_error("Task not initialized");               \
        }                                                                   \
}
#else
#define DAQmxErrChk
#endif

#include <QObject>

#include "qtlab-hw-ni_export.h"
#include <qtlab/hw/ni/natinst.h>

using namespace NI;

/**
 * @brief The NIAbstractTask class is an abstract wrapper for a DAQmx Task.
 *
 * \ingroup NationalInstruments
 */

class QTLAB_HW_NI_EXPORT NITask : public QObject
{
    Q_OBJECT
public:
    enum StartTrigDelayUnits {
        StartTrigDelayUnits_SampClkPeriods = DAQmx_Val_SampClkPeriods,
        StartTrigDelayUnits_Seconds = DAQmx_Val_Seconds,
        StartTrigDelayUnits_Ticks = DAQmx_Val_Ticks,
    };

    enum VoltageUnits {
        VoltUnits_Volts = DAQmx_Val_Volts,
        VoltUnits_FromCustomScale = DAQmx_Val_FromCustomScale,
    };

    enum FreqUnits {
        FreqUnits_Hz = DAQmx_Val_Hz,
        FreqUnits_Ticks = DAQmx_Val_Ticks,
        FreqUnits_FromCustomScale = DAQmx_Val_FromCustomScale,
    };

    enum TerminalConfig {
        TermConf_Default = DAQmx_Val_Cfg_Default,
        TermConf_RSE = DAQmx_Val_RSE,
        TermConf_NRSE = DAQmx_Val_NRSE,
        TermConf_Diff = DAQmx_Val_Diff,
        TermConf_PseudoDiff = DAQmx_Val_PseudoDiff,
    };

    enum Edge {
        Edge_Rising = DAQmx_Val_Rising,
        Edge_Falling = DAQmx_Val_Falling,
    };

    enum SampleMode {
        SampMode_FiniteSamps = DAQmx_Val_FiniteSamps,
        SampMode_ContSamps = DAQmx_Val_ContSamps,
        SampMode_HWTimedSinglePoint = DAQmx_Val_HWTimedSinglePoint,
    };

    enum LineGrouping {
        LineGrp_ChanPerLine = DAQmx_Val_ChanPerLine,
        LineGrp_ChanForAllLines = DAQmx_Val_ChanForAllLines,
    };

    enum DataLayout {
        DataLayout_GroupByChannel = DAQmx_Val_GroupByChannel,
        DataLayout_GroupByScanNumber = DAQmx_Val_GroupByScanNumber,
    };

    enum IdleState {
        IdleState_High = DAQmx_Val_High,
        IdleState_Low = DAQmx_Val_Low,
    };

    explicit NITask(QObject *parent = nullptr);
    virtual ~NITask();

    void createTask(QString taskName = QString());
    bool isInitialized();

    QStringList getPhysicalChannels() const;
    void setPhysicalChannels(const QStringList &value);
    int nOfChannels();

    double getSampleRate() const;
    void setSampleRate(double value);

    uInt64 getNSamples() const;
    void setNSamples(const uInt64 &value);

    QString getTriggerTerm() const;
    void setTriggerTerm(const QString &value);

    QString getSampClkTimingSource() const;
    void setSampClkTimingSource(const QString &value);

    uInt64 getSampsPerChan() const;
    void setSampsPerChan(const uInt64 &value);

    void setTaskName(const QString &value);

#include "NIDAQmx_task_wrapper_methods.h"

public slots:
    void initializeTask();
    void configureChannels();
    void configureTiming();
    void configureTriggering();

signals:
    void started();
    void stopped();

protected:
    [[ noreturn ]] void onError() const;
    virtual void initializeTask_impl();
    virtual void configureChannels_impl() {};
    virtual void configureTiming_impl() {};
    virtual void configureTriggering_impl() {};

    TaskHandle task = nullptr;
    QStringList physicalChannels;
    double sampleRate;
    uInt64 sampsPerChan;
    QString triggerTerm;
    QString sampClkTimingSource;
    QString taskName;

private:
    char *errBuff;
};

#endif // NITASK_H
