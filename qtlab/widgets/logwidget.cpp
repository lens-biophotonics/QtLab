#include "logwidget.h"

#include <qtlab/core/logmanager.h>

#include <QRegularExpression>
#include <QTime>
#include <QVBoxLayout>

LogWidget::LogWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();

    textEdit = new QTextEdit();
    textEdit->setReadOnly(true);
    layout->addWidget(textEdit);
    setLayout(layout);

    connect(&logManager(), &LogManager::newLogMessages, this, &LogWidget::logMessages);
}

void LogWidget::logMessages()
{
    for (Logger::Message message : logManager().getMessages()) {
        QString msg = message.msg;
        if (msg.isEmpty())
            return;
        QString timeString = QString("[%1]").arg(QTime::currentTime().toString());

        QRegularExpression re("<");
        if (msg.contains(re)) {
            msg.replace(re, "&lt;");
        }

        re.setPattern(">");
        if (msg.contains(re)) {
            msg.replace(re, "&gt;");
        }

        re.setPattern("\n*$");
        if (msg.contains(re)) {
            msg.replace(re, "");
        }

        re.setPattern("\n");
        if (msg.contains(re)) {
            msg.replace(re, QString("<br>").append(timeString));
        }

        re.setPattern("\r");
        if (msg.contains(re)) {
            msg.replace(re, "");
        }

        msg.prepend(timeString);
        switch (message.type) {
        case QtMsgType::QtCriticalMsg:
        case QtMsgType::QtFatalMsg:
            msg.prepend("<span style='background-color:#ef9a9a'>");
            msg.append("</span>");
            break;

        case QtMsgType::QtWarningMsg:
            msg.prepend("<span style='background-color:#ffe082'>");
            msg.append("</span>");
            break;

        case QtDebugMsg:
            msg.prepend("<span style='color:blue'>");
            msg.append("</span>");
            break;

        case QtInfoMsg:
        default:
            break;
        }

        msg.append("<br>");

        msg.prepend("<pre style=\"margin-bottom: 0px;\">");
        msg.append("</pre>");

        textEdit->insertHtml(msg);
    }

    textEdit->ensureCursorVisible();
}
