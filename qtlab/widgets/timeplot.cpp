#include <QApplication>
#include <QMouseEvent>
#include <QGridLayout>

#include <qwt_text_label.h>
#include <qwt_scale_widget.h>
#include <qwt_slider.h>
#include <qwt_plot_layout.h>

#include "timeplot.h"
#include "customspinbox.h"


// maybe replace with QwtDateScaleDraw
class TimeScaleDraw : public QwtScaleDraw
{
    friend class TimePlot;
public:
    TimeScaleDraw(double samplingRate) : QwtScaleDraw(), rate(samplingRate) {}
    virtual QwtText label(double value) const override
    {
        if (value == hiddenMajTick) {
            return QwtText();
        }
        double v = value / rate;
        uint h = v / 3600;
        uint m = v / 60; m = m % 60;
        uint s = v - h * 3600 - m * 60;
        return QwtText(QString("%1:%2:%3")
                       .arg(h, 2, 10, QChar('0'))
                       .arg(m, 2, 10, QChar('0'))
                       .arg(s, 2, 10, QChar('0')));
    }

private:
    double rate;
    double hiddenMajTick = std::numeric_limits<double>::max();
};



TimePlot::TimePlot(QWidget *parent) :
    QwtPlot(parent)
{
    setupUi();
    setSamplingRate(1);
    setBufSize(10.0);
    clear();
}

void TimePlot::setupUi()
{
    plotLayout()->setCanvasMargin(10, xBottom);
    scaleDraw = new TimeScaleDraw(1);
    setAxisScaleDraw(xBottom, scaleDraw);

    QPair<double, double> *currentRange = new QPair<double, double>(0, 1000);

    dialog = new QDialog(this);
    dialog->setWindowTitle("Set range");

    QwtSlider *minSlider = new QwtSlider(Qt::Horizontal, dialog);
    QwtSlider *maxSlider = new QwtSlider(Qt::Horizontal, dialog);

    minSlider->setScalePosition(QwtSlider::NoScale);
    minSlider->setLowerBound(0);
    minSlider->setUpperBound(100000);
    minSlider->setValue(currentRange->first);
    minSlider->setMinimumWidth(300);

    maxSlider->setScalePosition(QwtSlider::NoScale);
    maxSlider->setLowerBound(0);
    maxSlider->setUpperBound(100000);
    maxSlider->setValue(currentRange->second);

    DoubleSpinBox *minSpinBox = new DoubleSpinBox();
    minSpinBox->setRange(minSlider->minimum(), minSlider->maximum());
    minSpinBox->setDecimals(0);

    DoubleSpinBox *maxSpinBox = new DoubleSpinBox();
    maxSpinBox->setRange(maxSlider->minimum(), maxSlider->maximum());
    maxSpinBox->setDecimals(0);
    maxSpinBox->setValue(maxSlider->maximum());

    QGridLayout *grid = new QGridLayout();
    int row = 0;
    int col = 0;
    grid->addWidget(minSlider, row, col++);
    grid->addWidget(minSpinBox, row++, col++);
    col = 0;
    grid->addWidget(maxSlider, row, col++);
    grid->addWidget(maxSpinBox, row++, col++);

    dialog->setLayout(grid);

    std::function<void(void)> updatePlotRange = [ = ](){
        setAxisScale(xBottom, currentRange->first, currentRange->second);
        replot();
    };

    connect(minSlider, &QwtSlider::valueChanged, this, [ = ](double value){
        currentRange->first = value;
        minSpinBox->setValue(value);
        updatePlotRange();
    });

    connect(maxSlider, &QwtSlider::valueChanged, this, [ = ](double value){
        currentRange->second = value;
        maxSpinBox->setValue(value);
        updatePlotRange();
    });

    connect(minSpinBox, &DoubleSpinBox::returnPressed, this, [ = ](double value){
        currentRange->first = value;
        minSlider->setValue(value);
        updatePlotRange();
    });

    connect(maxSpinBox, &DoubleSpinBox::returnPressed, this, [ = ](double value){
        currentRange->second = value;
        maxSlider->setValue(value);
        updatePlotRange();
    });

    setCanvasBackground(QBrush(Qt::black));
    curve = new QwtPlotCurve();
    curve->setPen(Qt::white, 1),
    curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);
    curve->attach(this);
    xData = new QVector<double>();
    yData = new QVector<double>();
    setAxisAutoScale(yLeft);

    setContextMenuPolicy(Qt::ActionsContextMenu);

    QFont *labelFont = new QFont();
    labelFont->setPointSize(48);
    countsLabel = new QwtTextLabel(canvas());
    countsLabelText = new QwtText();
    countsLabelText->setColor(Qt::white);
    countsLabelText->setFont(*labelFont);
    countsLabel->setText(*countsLabelText);
    countsLabel->resize(350, 100);

    auto triggered = &QAction::triggered;

    QAction *clearHistoryAction = new QAction(this);
    clearHistoryAction->setText("Clear history");
    connect(clearHistoryAction, triggered, this, &TimePlot::clear);

    QAction *showCountsLabelAction = new QAction(this);
    showCountsLabelAction->setText("Show counts label");
    showCountsLabelAction->setCheckable(true);
    showCountsLabelAction->setChecked(false);
    connect(showCountsLabelAction, triggered,
            countsLabel, &QwtTextLabel::setVisible);
    countsLabel->setVisible(false);

    QAction *autoscaleYAction = new QAction(this);
    autoscaleYAction->setText("Autoscale Y");
    autoscaleYAction->setCheckable(true);
    autoscaleYAction->setChecked(true);
    connect(autoscaleYAction, triggered, [ = ](){
        setAxisAutoScale(yLeft, autoscaleYAction->isChecked());
        replot();
    });

    swipeXAction = new QAction(this);
    swipeXAction->setText("Swipe X");
    swipeXAction->setCheckable(true);

    connect(swipeXAction, triggered, this, [ = ](){
        bool enable = !swipeXAction->isChecked();
        maxSlider->setEnabled(enable);
        minSlider->setEnabled(enable);
        maxSpinBox->setEnabled(enable);
        minSpinBox->setEnabled(enable);
    });

    addAction(showCountsLabelAction);
    addAction(clearHistoryAction);
    addAction(autoscaleYAction);
    addAction(swipeXAction);

    swipeXAction->trigger();
}

void TimePlot::updateCountsLabel(double value)
{
    countsLabelText->setText(QString("%1").arg(value, 4, 'g', 4));
    countsLabel->setText(*countsLabelText);
}

void TimePlot::appendPoint(double y)
{
    if ((size_t)yData->size() + 1 > nResSamples) {
        xData->remove(0);
        yData->remove(0);
        xData->append(sampCounter);
    }

    sampCounter++;
    yData->append(y);

    replot();
    updateCountsLabel(y);
}

void TimePlot::appendPoints(const QVector<double> &y)
{
    if (!y.size())
        return;
    double sr = static_cast<TimeScaleDraw*>(scaleDraw)->rate;
    if ((size_t)yData->size() + y.size() > nResSamples) {
        size_t _free = nResSamples - yData->size();
        size_t diff = y.size() - _free;
        xData->remove(0, diff);
        yData->remove(0, diff);

        for (int i = 0; i < y.size(); ++i) {
            xData->append(sampCounter + i);
        }
    }

    yData->append(y);
    sampCounter += y.size();

    replot();
    updateCountsLabel(y.last());
}

void TimePlot::clear()
{
    yData->clear();
    sampCounter = 0;
    setBufSize(nResSamples);
    curve->setRawSamples(xData->data(), yData->data(), yData->size());
    setAxisScale(QwtPlot::xBottom, 0.0, nResSamples);
    replot();
}

void TimePlot::setSamplingRate(double Hz)
{
    static_cast<TimeScaleDraw*>(scaleDraw)->rate = Hz;
}

void TimePlot::setBufSize(size_t nSamples)
{
    this->nResSamples = nSamples;
    yData->reserve(nSamples);
    xData->reserve(nSamples);
    xData->clear();
    for (size_t i = 0; i < nSamples; ++i) {
        xData->append(i);
    }
}

void TimePlot::setBufSize(double seconds)
{
    size_t bs = (size_t)(static_cast<TimeScaleDraw*>(scaleDraw)->rate * seconds);
    setBufSize(bs);
}

void TimePlot::setSwipeXEnabled(bool enable)
{
    if (enable == swipeXAction->isChecked())
        return;

    swipeXAction->trigger();
}


void TimePlot::mouseDoubleClickEvent(QMouseEvent *e)
{
    QwtScaleWidget *sw = axisWidget(xBottom);
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }
    // do not catch event if it happens outside the
    // x axis widget (see also heightForWidth())
    if (height() - e->pos().y() > sw->height())
    {
        e->ignore();
        return;
    }

    e->accept();
    dialog->show();
}

void TimePlot::replot()
{
    curve->setRawSamples(xData->data(), yData->data(), yData->size());

    if (swipeXAction->isChecked()) {
        // when swiping, make sure that the last major tick is not drawn
        // to have smooth scrolling (because its label would occupy too much
        // space)
        const QList<double> &majTicks
            = axisScaleDiv(xBottom).ticks(QwtScaleDiv::MajorTick);
        if (majTicks.size() > 2) {
            double diff = majTicks.at(1) - majTicks.at(0);
            if (sampCounter >= majTicks.last() + diff)
                static_cast<TimeScaleDraw*>(scaleDraw)->hiddenMajTick
                    = majTicks.last() + diff;
        }
        setAxisScale(QwtPlot::xBottom, xData->first(), xData->last());
    }

    QwtPlot::replot();
}

TimePlot::~TimePlot()
{
    delete xData;
    delete yData;
}
