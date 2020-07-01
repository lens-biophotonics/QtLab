#ifndef LOGGER_H
#define LOGGER_H

#include <QEvent>
#include <QString>
#include <QObject>

/**
 * @brief Type of log message.
 */

class Logger : public QObject
{
    Q_OBJECT
public:
    struct Message {
        QtMsgType type;
        QString msg;
    };

    Logger(QString name = "");

public slots:
    void _msg(QString str, QtMsgType type = QtInfoMsg) const;
    void debug(QString msg) const;
    void info(QString msg) const;
    void warning(QString msg) const;
    void critical(QString msg) const;
    void fatal(QString msg) const;

private:
    QString name;
};

Logger *getLogger(QString name);

#endif // LOGGER_H
