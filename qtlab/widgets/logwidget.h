#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QTextEdit>
#include <QWidget>

class LogWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LogWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
    QTextEdit *textEdit;

private slots:
    void logMessages();
};

#endif // LOGWIDGET_H
