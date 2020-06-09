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
    QList<Logger::Message> list = QList<Logger::Message>(messageList);
    messageList.clear();
    signalEmitted = false;
    return list;
}

void LogManager::appendMessage(Logger::Message msg) {
    messageList.append(msg);
    if(signalEmitted)
        return;
    signalEmitted = true;
    emit newLogMessages();
}

LogManager &logManager()
{
    static auto instance = std::make_unique<LogManager>();
    return *instance;
}
