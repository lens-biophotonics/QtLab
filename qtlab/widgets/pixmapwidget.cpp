#include "pixmapwidget.h"

#include <QPainter>

class PaintArea : public QWidget
{
    friend PixmapWidget;

public:
    PaintArea(QWidget *parent = nullptr)
        : QWidget(parent)
    {}

protected:
    void paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event)
        QPainter painter(this);

        int w, h;

        w = width();
        h = height();

        if (fliplr) {
            painter.translate(w, 0);
            painter.scale(-1, 1);
        }

        if (flipud) {
            painter.translate(0, h);
            painter.scale(1, -1);
        }

        switch (rotationStep % 4) {
        case 1:
            painter.translate(w, 0);
            painter.rotate(90);
            break;
        case 2:
            painter.translate(w, h);
            painter.rotate(180);
            break;
        case 3:
            painter.translate(0, h);
            painter.rotate(-90);
            break;
        default:
            break;
        }

        QRect r = rect();
        if (rotationStep % 2)
            r = r.transposed();

        painter.drawPixmap(r, pm, pm.rect());
    }

private:
    bool fliplr = false;
    bool flipud = false;
    QPixmap pm;
    uchar rotationStep = 0;
};

PixmapWidget::PixmapWidget(double aspectRatio, QWidget *parent)
    : QWidget(parent)
{
    setupUi();
    setAspectRatio(aspectRatio);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

bool PixmapWidget::isFlippedlr()
{
    return static_cast<PaintArea *>(paintArea)->fliplr;
}

bool PixmapWidget::isFlippedud()
{
    return static_cast<PaintArea *>(paintArea)->flipud;
}

uint PixmapWidget::getRotationStep()
{
    return static_cast<PaintArea *>(paintArea)->rotationStep % 4;
}

void PixmapWidget::setupUi()
{
    paintArea = new PaintArea();
    arw = new AspectRatioWidget(paintArea, 1);

    fliplrPushButton = new QPushButton();
    flipudPushButton = new QPushButton();
    rotateCWPushButton = new QPushButton();
    rotateCCWPushButton = new QPushButton();

    fliplrPushButton->setCheckable(true);
    flipudPushButton->setCheckable(true);

#ifdef Q_OS_UNIX
    fliplrPushButton->setIcon(QIcon::fromTheme("image-flip-horizontal-symbolic"));
    flipudPushButton->setIcon(QIcon::fromTheme("image-flip-vertical-symbolic"));
    rotateCWPushButton->setIcon(QIcon::fromTheme("image-rotate-right-symbolic"));
    rotateCCWPushButton->setIcon(QIcon::fromTheme("image-rotate-left-symbolic"));
#else
    fliplrPushButton->setText("Flip LR");
    flipudPushButton->setText("Flip UD");
    rotateCWPushButton->setText("Rot CW");
    rotateCCWPushButton->setText("Rot CCW");
#endif

    fliplrPushButton->setToolTip("Flip horizontally");
    flipudPushButton->setToolTip("Flip vertically");
    rotateCWPushButton->setToolTip("Rotate clockwise");
    rotateCCWPushButton->setToolTip("Rotate counter-clockwise");

    connect(fliplrPushButton, &QPushButton::clicked, this, &PixmapWidget::fliplr);
    connect(flipudPushButton, &QPushButton::clicked, this, &PixmapWidget::flipud);
    connect(rotateCWPushButton, &QPushButton::clicked, this, &PixmapWidget::rotatecw);
    connect(rotateCCWPushButton, &QPushButton::clicked, this, &PixmapWidget::rotateccw);

    QHBoxLayout *controlsLayout = new QHBoxLayout();
    controlsLayout->addStretch();
    controlsLayout->addWidget(fliplrPushButton);
    controlsLayout->addWidget(flipudPushButton);
    controlsLayout->addWidget(rotateCWPushButton);
    controlsLayout->addWidget(rotateCCWPushButton);
    controlsLayout->addStretch();

    QVBoxLayout *myLayout = new QVBoxLayout();
    myLayout->addItem(new QSpacerItem(0, 0));
    myLayout->addWidget(arw);
    myLayout->addLayout(controlsLayout);
    myLayout->addItem(new QSpacerItem(0, 0));
    setLayout(myLayout);
}

void PixmapWidget::setPixmap(const QPixmap &pm)
{
    PaintArea *pa = static_cast<PaintArea *>(paintArea);
    pa->pm = pm;
    setAspectRatio(1. * pm.width() / pm.height());
    arw->readjust();
}

void PixmapWidget::rotatecw()
{
    PaintArea *pa = static_cast<PaintArea *>(paintArea);
    if (pa->fliplr ^ pa->flipud)
        pa->rotationStep--;
    else
        pa->rotationStep++;
    arw->invertRatio();
    paintArea->update();
}

void PixmapWidget::rotateccw()
{
    PaintArea *pa = static_cast<PaintArea *>(paintArea);
    if (pa->fliplr ^ pa->flipud)
        pa->rotationStep++;
    else
        pa->rotationStep--;
    arw->invertRatio();
    paintArea->update();
}

void PixmapWidget::setRotationStep(uint step)
{
    PaintArea *pa = static_cast<PaintArea *>(paintArea);
    if (step % 2)
        arw->invertRatio();
    pa->rotationStep = step;
}

void PixmapWidget::fliplr()
{
    PaintArea *pa = static_cast<PaintArea *>(paintArea);
    pa->fliplr = !pa->fliplr;
    fliplrPushButton->setChecked(pa->fliplr);
    paintArea->update();
}

void PixmapWidget::flipud()
{
    PaintArea *pa = static_cast<PaintArea *>(paintArea);
    pa->flipud = !pa->flipud;
    flipudPushButton->setChecked(pa->flipud);
    paintArea->update();
}

void PixmapWidget::setAspectRatio(double ar)
{
    arw->setAspectRatio(ar);
}
