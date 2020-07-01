#include <qtlab/core/logger.h>
#include <qtlab/core/logmanager.h>


Logger::Logger(QString name) : QObject(nullptr), name(name)
{
}

void Logger::_msg(QString str, QtMsgType type) const
{
    str.prepend(QString("[%1] ").arg(name));
    struct Message m = {
        .type = type,
        .msg = str,
    };
    logManager().appendMessage(m);
}

void Logger::debug(QString msg) const
{
    _msg(msg, QtMsgType::QtDebugMsg);
}

void Logger::info(QString msg) const
{
    this->_msg(msg);
}

void Logger::warning(QString msg) const
{
    _msg(msg, QtMsgType::QtWarningMsg);
}

void Logger::critical(QString msg) const
{
    _msg(msg, QtMsgType::QtCriticalMsg);
}

void Logger::fatal(QString msg) const
{
    _msg(msg, QtMsgType::QtFatalMsg);
}

Logger *getLogger(QString name)
{
    return logManager().getLogger(name);
}
