#ifndef AOTFWIDGET_H
#define AOTFWIDGET_H

#include <QWidget>

#include <qtlab/hw/serial/AA_MPDSnCxx.h>


class AA_AOTFWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AA_AOTFWidget(AA_MPDSnCxx *aotf = nullptr, int lines = 8, QWidget *parent = nullptr);

private:
    void setupUi(int lines);

    AA_MPDSnCxx *aotf = nullptr;
};

#endif // AOTFWIDGET_H
