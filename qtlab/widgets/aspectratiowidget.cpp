#include <QResizeEvent>

#include "aspectratiowidget.h"

AspectRatioWidget::AspectRatioWidget(
        QWidget *widget, double ratio,
        int paddingW, int paddingH, QWidget *parent) :
    QWidget(parent), wdg(widget), ratio(ratio),
    paddingW(paddingW), paddingH(paddingH)
{
    layout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    layout->setMargin(0);

    layout->addItem(new QSpacerItem(0, 0));
    layout->addWidget(widget);
    layout->addItem(new QSpacerItem(0, 0));
}

void AspectRatioWidget::resizeEvent(QResizeEvent *event) {
    Q_UNUSED(event);
    readjust();
}

void AspectRatioWidget::readjust()
{
    double thisAspectRatio = static_cast<double>(size().width())
                             / size().height();
    int widgetStretch, outerStretch;

    double h = height() + paddingH;
    double w = width() + paddingW;

    double r = _invertRatio ? 1. / ratio : ratio;

    if (thisAspectRatio > r) // too wide
    {
        layout->setDirection(QBoxLayout::LeftToRight);
        widgetStretch = static_cast<int>(h * r);
        outerStretch = static_cast<int>((w - widgetStretch) / 2 + 0.5);
    }
    else // too tall
    {
        layout->setDirection(QBoxLayout::TopToBottom);
        widgetStretch = static_cast<int>(w * (1. / r));
        outerStretch = static_cast<int>((h - widgetStretch) / 2 + 0.5);
    }

    layout->setStretch(0, outerStretch);
    layout->setStretch(1, widgetStretch);
    layout->setStretch(2, outerStretch);
}

void AspectRatioWidget::setAspectRatio(double ratio)
{
    this->ratio = ratio;
    update();
}

void AspectRatioWidget::invertRatio()
{
    _invertRatio = !_invertRatio;
    readjust();
}
