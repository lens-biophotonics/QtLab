#ifndef AA_AOTFWIDGET_H
#define AA_AOTFWIDGET_H

#include <qtlab/hw/serial/AA_MPDSnCxx.h>

#include <QWidget>

class AA_AOTFWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AA_AOTFWidget(AA_MPDSnCxx *aotf = nullptr, int lines = 8, QWidget *parent = nullptr);

private:
    void setupUi(int lines);

    AA_MPDSnCxx *aotf = nullptr;
};

#endif // AA_AOTFWIDGET_H
