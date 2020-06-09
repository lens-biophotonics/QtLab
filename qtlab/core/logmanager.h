#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <QMap>
#include <QObject>

#include <qtlab/core/logger.h>

/**
 * @brief The LogManager class is a singleton factory for Loggers.
 */

class LogManager : public QObject
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

    void appendMessage(Logger::Message msg);
};

LogManager& logManager();

#endif // LOGMANAGER_H
