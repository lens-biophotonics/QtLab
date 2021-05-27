#include <stdexcept>

#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QState>
#include <QTimer>

#include <qtlab/hw/pi/pidevice.h>

#include <qtlab/widgets/customspinbox.h>

#include "pipositioncontrolwidget.h"

PIPositionControlWidget::PIPositionControlWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUI();
}

void PIPositionControlWidget::setupUI()
{
    grid = new QGridLayout();

    gb = new QGroupBox();
    gb->setLayout(grid);

    int col = 1;
    grid->addWidget(new QLabel("Curr. Pos."), row, col);
    col += 2;
    grid->addWidget(new QLabel("Set Pos."), row, col++);
    grid->addWidget(new QLabel("Step down"), row, col++);
    grid->addWidget(new QLabel("Step up"), row, col++);

    QFrame *line;
    line = new QFrame();
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    grid->addWidget(line, row, col++);

    grid->addWidget(new QLabel("Step size"), row, col++);
    grid->addWidget(new QLabel("Velocity"), row, col++);

    row++;

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(gb);
    setLayout(vLayout);
}

void PIPositionControlWidget::appendRow(
    PIDevice *device, const QString &axis, const QString &axisName)
{
    int col = 0;
    grid->addWidget(new QLabel(axisName), row, col++);
    QLabel *currentPos = new QLabel("0.000");
    grid->addWidget(currentPos, row, col++);
    QString s = "QPushButton {color: red;}";
    QPushButton *haltPushButton = new QPushButton("HALT");
    haltPushButton->setStyleSheet(s);
    grid->addWidget(haltPushButton, row, col++);

    DoubleSpinBox *positionSpinbox = new DoubleSpinBox();
    positionSpinbox->setDecimals(4);
    grid->addWidget(positionSpinbox, row, col++);

    QPushButton *minusPushButton = new QPushButton("-");
    grid->addWidget(minusPushButton, row, col++);

    QPushButton *plusPushButton = new QPushButton("+");
    grid->addWidget(plusPushButton, row, col++);

    QFrame *line;
    line = new QFrame();
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    grid->addWidget(line, row, col++);

    QDoubleSpinBox *stepSpinBox = new QDoubleSpinBox();
    stepSpinBox->setValue(0.1);
    stepSpinBox->setDecimals(4);
    grid->addWidget(stepSpinBox, row, col++);

    DoubleSpinBox *velocitySpinBox = new DoubleSpinBox();
    velocitySpinBox->setValue(1);
    velocitySpinBox->setDecimals(4);
    grid->addWidget(velocitySpinBox, row, col++);

    row++;

    QState *cs = device->getConnectedState();
    QState *ds = device->getDisconnectedState();

    QList<QWidget *> wList;

    // enabled when connected, disabled when disconnected
    wList = {
        haltPushButton,
        positionSpinbox,
        minusPushButton,
        plusPushButton,
        stepSpinBox,
        velocitySpinBox,
    };

    for (QWidget * w : wList) {
        cs->assignProperty(w, "enabled", true);
        ds->assignProperty(w, "enabled", false);
    }

    connect(haltPushButton, &QPushButton::clicked, this, [ = ](){
        try {
            device->halt(axis);
            device->getError();
        }
        catch (std::runtime_error e) {
            QMessageBox::critical(nullptr, "Error", e.what());
        }
    });

    enum ACTION {
        MOVE,
        STEPUP,
        STEPDOWN,
        SETVELOCITY,
    };

    std::function<void(const enum ACTION)> performAction
        = [ = ](const enum ACTION a){
        double pos = positionSpinbox->value();
        double vel = velocitySpinBox->value();
        double stepSize = stepSpinBox->value();

        try {
            device->setVelocities(axis, &vel);

            switch (a) {
            case MOVE:
                device->move(axis, &pos);
                break;

            case STEPUP:
                device->setStepSize(axis, stepSize);
                device->stepUp(axis);
                break;

            case STEPDOWN:
                device->setStepSize(axis, stepSize);
                device->stepDown(axis);
                break;

            case SETVELOCITY:
                break;
            }
        }
        catch (std::runtime_error e) {
            QMessageBox::critical(nullptr, "Error", e.what());
        }
        };

    connect(positionSpinbox, &DoubleSpinBox::returnPressed, this, [ = ](){
        performAction(MOVE);
    });

    connect(plusPushButton, &QPushButton::clicked, this, [ = ](){
        performAction(STEPUP);
    });

    connect(minusPushButton, &QPushButton::clicked, this, [ = ](){
        performAction(STEPDOWN);
    });

    connect(velocitySpinBox, &DoubleSpinBox::returnPressed, this, [ = ](){
        performAction(SETVELOCITY);
    });

    QTimer *updateTimer = new QTimer(this);
    updateTimer->setInterval(500);

    connect(updateTimer, &QTimer::timeout, this, [ = ]() {
        try {
            double pos = device->getCurrentPosition(axis).at(0);
            currentPos->setText(QString("%1").arg(pos, 0, 'f', 4));
        }
        catch (std::runtime_error e) {
            QMessageBox::critical(nullptr, "Error", e.what());
        }
    });

    connect(device, &PIDevice::connected, this, [ = ](){
        double min = device->getTravelRangeLowEnd(axis).at(0);
        double max = device->getTravelRangeHighEnd(axis).at(0);

        positionSpinbox->setRange(min, max);
//        positionSpinbox->setValue(pos);
//        stepSpinBox->setRange(0, max);
//        velocitySpinBox->setValue(velocity);
//        stepSpinBox->setValue(stepSize);

        updateTimer->start();
    });

    connect(device, &PIDevice::disconnected, updateTimer, &QTimer::stop);
}

void PIPositionControlWidget::setTitle(const QString &title)
{
    gb->setTitle(title);
}
