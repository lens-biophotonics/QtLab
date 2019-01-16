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
 * If an error has occurred during the function call, the
 * NIAbstractTask::onError() slot is called.
 *
 * \param functionCall The function to be called
 */
#define DAQmxErrChk(functionCall) { \
        if (DAQmxFailed(functionCall)) { \
            onError(); \
        } \
}

/**
 * \brief As DAQmxErrChk, but make the function that refers to this macro
 * return false
 */
#define DAQmxErrChkRetFalse(functionCall) { \
        if (DAQmxFailed(functionCall)) { \
            onError(); \
            return false; \
        } \
}

#include <QObject>

#include "natinst.h"

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

signals:
    void error();

public slots:
    bool start();
    bool stop();
    bool clear();

protected slots:
    void onError();

protected:
#ifdef NIDAQMX_HEADERS
    NI::TaskHandle task;
#endif

private:
    virtual bool initializeTask() = 0;
    char *errBuff;
};

#endif // NIABSTRACTTASK_H
