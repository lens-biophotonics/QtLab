#ifndef ASPECTRATIOWIDGET_H
#define ASPECTRATIOWIDGET_H

#include <QWidget>
#include <QHBoxLayout>

#include <qwt_plot.h>


class AspectRatioWidget : public QWidget
{
    Q_OBJECT
public:
    AspectRatioWidget(QWidget *widget, double ratio,
                      int paddingW = 0, int paddingH = 0,
                      QWidget *parent = nullptr);

public slots:
    void setAspectRatio(double ratio);
    void invertRatio();

    void readjust();

protected:
    virtual void resizeEvent(QResizeEvent *event);

private:
    QWidget *wdg;
    QBoxLayout *layout;
    double ratio;
    bool _invertRatio = false;
    int paddingW;
    int paddingH;
};

#endif // ASPECTRATIOWIDGET_H
