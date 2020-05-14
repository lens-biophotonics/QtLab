#ifndef TIMEPLOT_H
#define TIMEPLOT_H

#include <QMenu>
#include <QDialog>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_scale_draw.h>

/**
 * @brief The APDPlot class implements the plot used to display APD counts.
 *
 * \ingroup Widgets
 */

class TimePlot : public QwtPlot
{
    Q_OBJECT
public:
    explicit TimePlot(QWidget *parent = 0);
    ~TimePlot();

signals:

public slots:
    void appendPoint(ulong y);
    void clear();
    void setSamplingRate(double Hz);
    void setBufSize(size_t nResSamples);
    void setSwipeXEnabled(bool enable);

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *e) override;

private:
    size_t sampCounter, nResSamples;
    QwtPlotCurve *curve;
    QVector<double> *xData, *yData;
    QAction *swipeXAction;
    QwtTextLabel *countsLabel;
    QwtText *countsLabelText;
    QwtScaleDraw *scaleDraw;

    QDialog *dialog;

    void setupUi();
};

#endif // TIMEPLOT_H
