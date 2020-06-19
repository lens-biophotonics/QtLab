#include <memory>

#include <qtlab/core/logmanager.h>

LogManager::LogManager()
{
    signalEmitted = false;
    qRegisterMetaType<MsgType>("MsgType");
}

LogManager::~LogManager()
{
    qDeleteAll(logMap);
}

/**
 * @brief Re-emit newLogMessages() so that the receiving slot can grab messages.
 *
 * You need to call this function to grab messages that were logged before the receiving slot was
 * connected.
 */

void LogManager::flushMessages()
{
    emit newLogMessages();
}

Logger *LogManager::getLogger(QString name)
{
    Logger *logger;
    QMap<QString, Logger *>::iterator it = logMap.find(name);
    if (it == logMap.end()) {
        logger = new Logger(name);
        logMap[name] = logger;
    }
    else {
        logger = it.value();
    }
    return logger;
}

QList<Logger::Message> LogManager::getMessages()
{
    mutex.lock();
    QList<Logger::Message> list = QList<Logger::Message>(messageList);
    messageList.clear();
    mutex.unlock();
    signalEmitted = false;
    return list;
}

void LogManager::appendMessage(Logger::Message msg)
{
    mutex.lock();
    messageList.append(msg);
    mutex.unlock();
    if (signalEmitted)
        return;
    signalEmitted = true;
    flushMessages();
}

LogManager &logManager()
{
    static auto instance = std::make_unique<LogManager>();
    return *instance;
}
