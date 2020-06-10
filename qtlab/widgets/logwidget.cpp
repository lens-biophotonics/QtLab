#include <QVBoxLayout>
#include <QTime>

#include <qtlab/core/logmanager.h>
#include "logwidget.h"

LogWidget::LogWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();

    textEdit = new QTextEdit();
    textEdit->setReadOnly(true);
    layout->addWidget(textEdit);
    setLayout(layout);

    connect(&logManager(), &LogManager::newLogMessages,
            this, &LogWidget::logMessages);
}

void LogWidget::logMessages()
{
    for (Logger::Message message : logManager().getMessages()) {
        QString msg = message.msg;
        if (msg.isEmpty())
            return;
        QString timeString = QString("[%1]").arg(QTime::currentTime().toString());
        if (msg.contains(QRegExp("<")))
            msg.replace(QRegExp("<"), "&lt;");
        if (msg.contains(QRegExp(">")))
            msg.replace(QRegExp(">"), "&gt;");
        if (msg.contains(QRegExp("\n*$")))
            msg.replace(QRegExp("\n*$"), "");
        if (msg.contains(QRegExp("\n")))
            msg.replace(QRegExp("\n"), QString("<br>").append(timeString));
        if (msg.contains(QRegExp("\r")))
            msg.replace(QRegExp("\r"), "");

        msg.prepend(timeString);
        if (message.type == MSG_ERROR) {
            msg.prepend("<span style='color:red'>");
            msg.append("</span>");
        }
        else if (message.type == MSG_WARNING) {
            msg.prepend("<span style='color:orange'>");
            msg.append("</span>");
        }

        msg.append("<br>");

        msg.prepend("<pre style=\"margin-bottom: 0px;\">");
        msg.append("</pre>");

        textEdit->insertHtml(msg);
    }

    textEdit->ensureCursorVisible();
}
