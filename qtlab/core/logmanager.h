#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <QMap>
#include <QObject>
#include <QMutex>

#include <qtlab/core/logger.h>
#include "qtlab-core_export.h"

/**
 * @brief The LogManager class is a singleton factory for Loggers.
 */

class QTLAB_CORE_EXPORT LogManager : public QObject
{
    Q_OBJECT
public:
    friend class Logger;

    LogManager();
    ~LogManager();

    Logger *getLogger(QString name);
    QList<Logger::Message> getMessages();

signals:
    void newLogMessages();

private:
    QMap<QString, Logger *> logMap;
    QList<Logger::Message> messageList;
    bool signalEmitted;
    QMutex mutex;

    void appendMessage(Logger::Message msg);
};

LogManager& logManager();

#endif // LOGMANAGER_H
