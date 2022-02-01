#ifndef PIXMAPWIDGET_H
#define PIXMAPWIDGET_H

#include <qtlab/widgets/aspectratiowidget.h>

#include <QPushButton>
#include <QWidget>

/**
 * @brief The PixmapWidget class displays a pixmap with some visualization
 *        controls.
 *
 * It can be used as a simple display widget for a camera output.
 */

class PixmapWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PixmapWidget(double aspectRatio = 1, QWidget *parent = nullptr);

    bool isFlippedlr();
    bool isFlippedud();
    uint getRotationStep();

public slots:
    void setPixmap(const QPixmap &pm);
    void rotatecw();
    void rotateccw();
    void setRotationStep(uint step);
    void fliplr();
    void flipud();
    void setAspectRatio(double arw);

signals:

private:
    QWidget *paintArea;
    AspectRatioWidget *arw;
    QPushButton *fliplrPushButton = new QPushButton();
    QPushButton *flipudPushButton = new QPushButton();
    QPushButton *rotateCWPushButton = new QPushButton();
    QPushButton *rotateCCWPushButton = new QPushButton();

    void setupUi();
};

#endif // PIXMAPWIDGET_H
