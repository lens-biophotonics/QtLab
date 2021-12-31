#ifndef CAMERPLOT_H
#define CAMERPLOT_H

#include <qwt_plot.h>
#include <qwt_matrix_raster_data.h>
#include <qwt_color_map.h>
#include <qwt_plot_spectrogram.h>
#include <qwt_interval.h>


class CameraPlot : public QwtPlot
{
public:
    CameraPlot(QWidget *parent = nullptr);
    CameraPlot(uint nRows, uint nCols, QWidget *parent = nullptr);

    void setInterval(const Qt::Axis axis, const double min, const double max);

    void setColorMap(QwtLinearColorMap *value);
    void setPlotSize(uint nCols, uint nRows);
    void setPlotSize(QSize size);
    QSize getPlotSize();

    void setData(const QVector<double> &data);
    void setData(const double *data, const size_t size);
    void replot() override;
    void fillGradient();

public slots:
    void setZAutoscaleEnabled(bool enable);

private:
    QwtMatrixRasterData *data = nullptr;
    QwtLinearColorMap *colorMap = nullptr;
    QwtPlotSpectrogram *spectrogramPlot = nullptr;
    bool autoscaleZ = true;
    double min;
    double max;
    uint nCols = 0, nRows = 0;
    QwtInterval ZInterval;
    QVector<double> vec;

    void setup();
    void _autoscale();
};

#endif // CAMERPLOT_H
