#include <qtlab/widgets/aspectratiowidget.h>
#include <qtlab/widgets/cameradisplay.h>
#include <qtlab/widgets/cameraplot.h>
#include <qtlab/widgets/colormaps.h>
#include <qtlab/widgets/customspinbox.h>

#include <qwt_plot_grid.h>
#include <qwt_slider.h>

#include <QCheckBox>
#include <QContextMenuEvent>
#include <QDialog>
#include <QDirIterator>
#include <QHBoxLayout>
#include <QPair>
#include <QPen>
#include <QRegularExpression>
#include <QStack>

class Zoomer : public QwtPlotZoomer
{
public:
    using QwtPlotZoomer::zoom;

    Zoomer(QWidget *parent, bool doReplot = true)
        : QwtPlotZoomer(parent, doReplot)
    {}

    void zoom(const QRectF &rect) override
    {
        // bound the zooming rect to the zoomBase dimensions
        QRectF boundedRect = rect & zoomBase();
        QwtPlotZoomer::zoom(boundedRect);
    }
};

CameraDisplay::CameraDisplay(QWidget *parent)
    : QWidget(parent)
{
    setupUi();
}

CameraDisplay::~CameraDisplay() {}

void CameraDisplay::setLUTPath(QString value)
{
    LUTPath = value;
    setupLUTmenu();
}

void CameraDisplay::replot()
{
    plot->replot();
}

void CameraDisplay::contextMenuEvent(QContextMenuEvent *event)
{
    event->accept();
    menu->exec(QCursor::pos());
}

CameraPlot *CameraDisplay::getPlot() const
{
    return plot;
}

void CameraDisplay::setPlotSize(QSize size)
{
    if (plot->getPlotSize() == size) {
        return;
    }
    plot->setPlotSize(size);
    plot->fillGradient();
    cursorMarker->setValue(size.width() / 2, size.height() / 2);
    QStack<QRectF> stack;
    stack.push(QRectF(QPointF(0, 0), size));
    zoomer->setZoomStack(stack);
}

QString CameraDisplay::getTitle() const
{
    return title;
}

void CameraDisplay::setTitle(const QString &value)
{
    title = value;
}

void CameraDisplay::setupUi()
{
    QPair<double, double> *currentRange = new QPair<double, double>(0, 65535);

    menu = new QMenu();
    setContextMenuPolicy(Qt::DefaultContextMenu);

    plot = new CameraPlot(512, 512);

    zoomer = new Zoomer(plot->canvas());
    zoomer->setRubberBandPen(QPen(Qt::green));
    zoomer->setTrackerPen(QPen(Qt::green));

    cursorMarker = new QwtPlotMarker();
    cursorMarker->setLineStyle(
        static_cast<QwtPlotMarker::LineStyle>(QwtPlotMarker::VLine | QwtPlotMarker::HLine));
    cursorMarker->setLinePen(Qt::green);
    cursorMarker->setValue(256, 256);
    cursorMarker->attach(plot);
    cursorMarker->setVisible(false);

    QwtPlotGrid *plotGrid = new QwtPlotGrid();
    plotGrid->setPen(Qt::green);
    plotGrid->attach(plot);
    plotGrid->setVisible(false);

    QAction *autoscaleAction = new QAction("Autoscale");
    autoscaleAction->setCheckable(true);
    autoscaleAction->setChecked(true);

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(title);

    QwtSlider *minSlider = new QwtSlider(Qt::Horizontal, dialog);
    QwtSlider *maxSlider = new QwtSlider(Qt::Horizontal, dialog);

    minSlider->setScalePosition(QwtSlider::NoScale);
    minSlider->setLowerBound(0);
    minSlider->setUpperBound(65535);
    minSlider->setValue(currentRange->first);
    minSlider->setEnabled(false);
    minSlider->setMinimumWidth(300);

    maxSlider->setScalePosition(QwtSlider::NoScale);
    maxSlider->setLowerBound(0);
    maxSlider->setUpperBound(65535);
    maxSlider->setValue(currentRange->second);
    maxSlider->setEnabled(false);

    DoubleSpinBox *minSpinBox = new DoubleSpinBox();
    minSpinBox->setRange(minSlider->minimum(), minSlider->maximum());
    minSpinBox->setDecimals(0);
    minSpinBox->setEnabled(false);

    DoubleSpinBox *maxSpinBox = new DoubleSpinBox();
    maxSpinBox->setRange(maxSlider->minimum(), maxSlider->maximum());
    maxSpinBox->setDecimals(0);
    maxSpinBox->setValue(maxSlider->maximum());
    maxSpinBox->setEnabled(false);

    QGridLayout *grid = new QGridLayout();
    int row = 0;
    int col = 0;
    grid->addWidget(minSlider, row, col++);
    grid->addWidget(minSpinBox, row++, col++);
    col = 0;
    grid->addWidget(maxSlider, row, col++);
    grid->addWidget(maxSpinBox, row++, col++);

    QCheckBox *autoscaleCheckBox = new QCheckBox("Autoscale");
    autoscaleCheckBox->setChecked(autoscaleAction->isChecked());
    connect(autoscaleCheckBox, &QCheckBox::clicked, autoscaleAction, &QAction::trigger);

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addLayout(grid);
    vLayout->addWidget(autoscaleCheckBox);
    dialog->setLayout(vLayout);

    std::function<void(void)> updatePlotRange = [=]() {
        plot->setInterval(Qt::ZAxis, currentRange->first, currentRange->second);
    };

    connect(minSlider, &QwtSlider::valueChanged, this, [=](double value) {
        currentRange->first = value;
        minSpinBox->setValue(value);
        updatePlotRange();
    });

    connect(maxSlider, &QwtSlider::valueChanged, this, [=](double value) {
        currentRange->second = value;
        maxSpinBox->setValue(value);
        updatePlotRange();
    });

    connect(minSpinBox, &DoubleSpinBox::returnPressed, this, [=](double value) {
        currentRange->first = value;
        minSlider->setValue(value);
        updatePlotRange();
    });

    connect(maxSpinBox, &DoubleSpinBox::returnPressed, this, [=](double value) {
        currentRange->second = value;
        maxSlider->setValue(value);
        updatePlotRange();
    });

    connect(autoscaleAction, &QAction::triggered, this, [=](bool checked) {
        plot->setZAutoscaleEnabled(checked);
        if (!checked) {
            updatePlotRange();
        }
        autoscaleCheckBox->setChecked(checked);

        minSlider->setEnabled(!checked);
        maxSlider->setEnabled(!checked);
        minSpinBox->setEnabled(!checked);
        maxSpinBox->setEnabled(!checked);
    });
    menu->addAction(autoscaleAction);

    QAction *action;
    action = new QAction("Set Z range...");
    connect(action, &QAction::triggered, dialog, &QDialog::show);
    menu->addAction(action);

    menu->addSeparator();

    action = new QAction("Zoom out", this);
    connect(action, &QAction::triggered, this, [=]() { zoomer->zoom(-1); });
    menu->addAction(action);

    action = new QAction("Zoom in", this);
    connect(action, &QAction::triggered, this, [=]() { zoomer->zoom(1); });
    menu->addAction(action);

    action = new QAction("Reset zoom", this);
    connect(action, &QAction::triggered, this, [=]() { zoomer->zoom(0); });
    menu->addAction(action);

    menu->addSeparator();

    action = new QAction("Show cross", this);
    action->setCheckable(true);
    action->setChecked(false);
    connect(action, &QAction::triggered, this, [=](bool checked) {
        cursorMarker->setVisible(checked);
        plot->replot();
    });
    menu->addAction(action);

    QAction *showGridAction = new QAction("Show grid", this);
    QAction *showMinorGridAction = new QAction("Show minor grid", this);
    showGridAction->setCheckable(true);
    showGridAction->setChecked(false);
    connect(showGridAction, &QAction::triggered, this, [=](bool checked) {
        plotGrid->enableXMin(false);
        plotGrid->enableYMin(false);
        plotGrid->setVisible(checked);
        showMinorGridAction->setChecked(false);
        plot->replot();
    });
    menu->addAction(showGridAction);

    showMinorGridAction->setCheckable(true);
    showMinorGridAction->setChecked(false);
    connect(showMinorGridAction, &QAction::triggered, this, [=](bool checked) {
        plotGrid->enableXMin(true);
        plotGrid->enableYMin(true);
        plotGrid->setVisible(checked);
        showGridAction->setChecked(false);
        plot->replot();
    });
    menu->addAction(showMinorGridAction);
    menu->addSeparator();

    LUTMenu = new QMenu("LUT");

    setupLUTmenu();

    menu->addMenu(LUTMenu);

    QWidget *aspectRatioWidget = new AspectRatioWidget(plot, 1.1, -80, -50);

    QBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(aspectRatioWidget, 1);

    setLayout(layout);
}

void CameraDisplay::setupLUTmenu()
{
    LUTMenu->clear();
    QAction *action = new QAction("Grayscale");
    LUTMenu->addAction(action);
    connect(action, &QAction::triggered, this, [=]() {
        plot->setColorMap(new GrayScaleColorMap());
    });

    action = new QAction("Black Blue White");
    LUTMenu->addAction(action);
    connect(action, &QAction::triggered, this, [=]() {
        plot->setColorMap(new BlueWhiteColorMap());
    });

    action = new QAction("Hi Low");
    LUTMenu->addAction(action);
    connect(action, &QAction::triggered, this, [=]() { plot->setColorMap(new HiLowColorMap()); });

    LUTMenu->addSeparator();

    if (LUTPath.isEmpty())
        return;
    QDirIterator it(LUTPath, QStringList() << "*.lut", QDir::NoFilter, QDirIterator::Subdirectories);
    QStringList sl;
    while (it.hasNext()) {
        sl << it.next();
    }
    sl.sort();

    QStringListIterator sli(sl);
    while (sli.hasNext()) {
        QString path = sli.next();
        QString name = path;
        QAction *action = new QAction(name.remove(LUTPath).remove(QRegularExpression("\\.lut$")));
        LUTMenu->addAction(action);

        connect(action, &QAction::triggered, this, [=]() {
            plot->setColorMap(new IJLUTColorMap(path));
        });
    }
}
