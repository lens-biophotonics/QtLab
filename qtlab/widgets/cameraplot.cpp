#include <qwt_scale_engine.h>
#include <qwt_scale_widget.h>

#include "cameraplot.h"

#include "colormaps.h"


CameraPlot::CameraPlot(QWidget *parent) : QwtPlot(parent)
{
    setup();
}

CameraPlot::CameraPlot(uint nRows, uint nCols, QWidget *parent) : QwtPlot(parent)
{
    setup();
    setPlotSize(nRows, nCols);
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = i / 64;
    }
    replot();
}

void CameraPlot::setup()
{
    axisScaleEngine(xBottom)->setAttribute(QwtScaleEngine::Floating, true);
    axisScaleEngine(yLeft)->setAttribute(QwtScaleEngine::Floating, true);

    spectrogramPlot = new QwtPlotSpectrogram();
    spectrogramPlot->attach(this);

    data = new QwtMatrixRasterData();
    spectrogramPlot->setData(data);

    QwtScaleWidget *rightAxis = axisWidget(QwtPlot::yRight);
    rightAxis->setColorBarEnabled(true);
    enableAxis(yRight);

    setColorMap(new GrayScaleColorMap());
    setInterval(Qt::ZAxis, 0, 65535);
}

void CameraPlot::setPlotSize(uint nRows, uint nCols)
{
    this->nCols = nCols;
    this->nRows = nRows;

    data->setInterval(Qt::XAxis, QwtInterval(0, nCols));
    data->setInterval(Qt::YAxis, QwtInterval(0, nRows));

    vec.fill(0, nCols * nRows);
}

void CameraPlot::setData(const QVector<double> &data)
{
    vec = data;
    replot();
}

void CameraPlot::setData(const double *data, const size_t n)
{
    vec.resize(n);
    memcpy(vec.data(), data, n * sizeof(double));
    replot();
}

void CameraPlot::_autoscale()
{
    if (!autoscaleZ || !vec.size())
        return;

    max = vec.at(0);
    max = min;
    for (const double val : vec) {
        if (val > max) {
            max = val;
        }
        if (val < min) {
            min = val;
        }
    }

    setInterval(Qt::ZAxis, min, max);
}

void CameraPlot::replot()
{
    data->setValueMatrix(vec, nCols);

    _autoscale();
    QwtPlot::replot();
}

void CameraPlot::setInterval(const Qt::Axis axis, const double min,
                             const double max)
{
    ZInterval = QwtInterval(min, max);
    if (!ZInterval.isValid())
        return;
    data->setInterval(axis, ZInterval);
    if (axis == Qt::ZAxis) {
        setAxisScale(QwtPlot::yRight, ZInterval.minValue(), ZInterval.maxValue());
        QwtScaleWidget *rightAxis = axisWidget(QwtPlot::yRight);
        rightAxis->setColorMap(ZInterval, copyColorMap(colorMap));
    }
    QwtPlot::replot();
}

void CameraPlot::setZAutoscaleEnabled(bool enable)
{
    autoscaleZ = enable;
    replot();
}

void CameraPlot::setColorMap(QwtLinearColorMap *value)
{
    colorMap = value;

    spectrogramPlot->setColorMap(colorMap);
    QwtScaleWidget *rightAxis = axisWidget(QwtPlot::yRight);
    rightAxis->setColorMap(ZInterval, copyColorMap(colorMap));
    QwtPlot::replot();
}
