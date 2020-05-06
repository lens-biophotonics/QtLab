#ifndef CAMERADISPLAY_H
#define CAMERADISPLAY_H

#include <QWidget>
#include <QMenu>

class CameraPlot;


class CameraDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit CameraDisplay(QWidget *parent = nullptr);
    virtual ~CameraDisplay();

    void setLUTPath(QString value);
    double *getBuffer();

    QString getTitle() const;
    void setTitle(const QString &value);

signals:

public slots:
    void replot();

protected:
    virtual void contextMenuEvent(QContextMenuEvent *event);

private:
    CameraPlot *plot;
    QMenu *menu;
    QMenu *LUTMenu;

    QString LUTPath;
    QString title;

    void setupUi();
    void setupLUTmenu();
};

#endif // CAMERADISPLAY_H
