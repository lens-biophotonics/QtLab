#include <qwt_scale_engine.h>
#include <qwt_scale_widget.h>

#include "cameraplot.h"

#include "colormaps.h"


CameraPlot::CameraPlot(uint nCols, uint nRows, QWidget *parent) :
    QwtPlot(parent), nCols(nCols), nRows(nRows)
{
    axisScaleEngine(xBottom)->setAttribute(QwtScaleEngine::Floating, true);
    axisScaleEngine(yLeft)->setAttribute(QwtScaleEngine::Floating, true);

    spectrogramPlot = new QwtPlotSpectrogram();
    spectrogramPlot->attach(this);

    data = new QwtMatrixRasterData();
    data->setInterval(Qt::XAxis, QwtInterval(0, nCols));
    data->setInterval(Qt::YAxis, QwtInterval(0, nRows));

    vec = QVector<double>(nCols * nRows, 0.);
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = i / 64;
    }

    QwtScaleWidget *rightAxis = axisWidget(QwtPlot::yRight);
    rightAxis->setColorBarEnabled(true);
    enableAxis(yRight);

    spectrogramPlot->setData(data);

    setColorMap(new GrayScaleColorMap());
    setInterval(Qt::ZAxis, 0, 65535);
}

void CameraPlot::setData(const QVector<double> &vec)
{
    data->setValueMatrix(vec, nCols);

    min = std::numeric_limits<double>::infinity();
    max = -min;
    for (const double val : vec) {
        if (val > max) {
            max = val;
        }
        if (val < min) {
            min = val;
        }
    }
    if (autoscaleZ) {
        setInterval(Qt::ZAxis, min, max);
    }
    QwtPlot::replot();
}

void CameraPlot::replot()
{
    setData(vec);
}

void CameraPlot::setInterval(const Qt::Axis axis, const double min,
                             const double max)
{
    ZInterval = QwtInterval(min, max);
    data->setInterval(axis, ZInterval);
    if (!ZInterval.isValid())
        return;
    if (axis == Qt::ZAxis) {
        setAxisScale(QwtPlot::yRight, ZInterval.minValue(), ZInterval.maxValue());
        QwtScaleWidget *rightAxis = axisWidget(QwtPlot::yRight);
        rightAxis->setColorMap(ZInterval, copyColorMap(colorMap));
    }
    spectrogramPlot->plot();
}

void CameraPlot::setZAutoscaleEnabled(bool enable)
{
    autoscaleZ = enable;
    if (enable) {
        setInterval(Qt::ZAxis, min, max);
    }
    replot();
}

void CameraPlot::setColorMap(QwtLinearColorMap *value)
{
    colorMap = value;

    spectrogramPlot->setColorMap(colorMap);
    QwtScaleWidget *rightAxis = axisWidget(QwtPlot::yRight);
    rightAxis->setColorMap(ZInterval, copyColorMap(colorMap));
    replot();
}

/**
 * @brief CameraPlot::getBuffer
 * @return A pointer to the internal buffer for data to be plotted
 */

double *CameraPlot::getBuffer()
{
    return vec.data();
}
