#ifndef CAMERADISPLAY_H
#define CAMERADISPLAY_H

#include <qwt_plot_marker.h>
#include <qwt_plot_zoomer.h>

#include <QMenu>
#include <QWidget>

class CameraPlot;

class CameraDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit CameraDisplay(QWidget *parent = nullptr);
    virtual ~CameraDisplay();

    void setLUTPath(QString value);

    QString getTitle() const;
    void setTitle(const QString &value);

    CameraPlot *getPlot() const;

    void setPlotSize(QSize size);

signals:

public slots:
    void replot();

protected:
    virtual void contextMenuEvent(QContextMenuEvent *event);

protected:
    CameraPlot *plot;
    QMenu *menu;
    QMenu *LUTMenu;

    QString LUTPath;
    QString title;

    QwtPlotMarker *cursorMarker;
    QwtPlotZoomer *zoomer;

    void setupUi();
    void setupLUTmenu();
};

#endif // CAMERADISPLAY_H
