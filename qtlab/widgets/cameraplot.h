#ifndef CAMERPLOT_H
#define CAMERPLOT_H

#include <qwt_plot.h>
#include <qwt_matrix_raster_data.h>
#include <qwt_color_map.h>
#include <qwt_plot_spectrogram.h>


class CameraPlot : public QwtPlot
{
public:
    CameraPlot(uint nCols, uint nRows, QWidget *parent = nullptr);

    void setInterval(const Qt::Axis axis, const double min, const double max);

    void setZAutoscaleEnabled(bool enable);

    void setColorMap(QwtLinearColorMap *value);

    double *getBuffer();
    void replot() override;

public slots:
    void setData(const QVector<double> &vec);

private:
    QwtMatrixRasterData *data;
    QwtLinearColorMap *colorMap = nullptr;
    QwtPlotSpectrogram *spectrogramPlot = nullptr;
    bool autoscaleZ = true;
    double min;
    double max;
    uint nCols, nRows;
    QwtInterval ZInterval;
    QVector<double> vec;
};

#endif // CAMERPLOT_H
