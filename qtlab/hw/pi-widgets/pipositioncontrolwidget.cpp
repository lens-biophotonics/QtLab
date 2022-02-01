#include "pipositioncontrolwidget.h"

#include <stdexcept>

#include <qtlab/hw/pi/pidevice.h>
#include <qtlab/widgets/customspinbox.h>

#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QState>
#include <QTimer>

PIPositionControlWidget::PIPositionControlWidget(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
}

void PIPositionControlWidget::setupUI()
{
    grid = new QGridLayout();

    gb = new QGroupBox();
    gb->setLayout(grid);

    int col = 1;
    QLabel *label;
    label = new QLabel("Curr. Pos.");
    label->setAlignment(Qt::AlignCenter);
    grid->addWidget(label, row, col);
    col += 2;
    label = new QLabel("|<");
    label->setAlignment(Qt::AlignCenter);
    grid->addWidget(label, row, col++);
    label = new QLabel("<");
    label->setAlignment(Qt::AlignCenter);
    grid->addWidget(label, row, col++);
    label = new QLabel("Set Pos.");
    label->setAlignment(Qt::AlignCenter);
    grid->addWidget(label, row, col++);
    label = new QLabel(">");
    label->setAlignment(Qt::AlignCenter);
    grid->addWidget(label, row, col++);
    label = new QLabel(">|");
    label->setAlignment(Qt::AlignCenter);
    grid->addWidget(label, row, col++);

    QFrame *line;
    line = new QFrame();
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    grid->addWidget(line, row, col++);

    label = new QLabel("Step size");
    label->setAlignment(Qt::AlignCenter);
    grid->addWidget(label, row, col++);
    label = new QLabel("Velocity");
    label->setAlignment(Qt::AlignCenter);
    grid->addWidget(label, row, col++);

    row++;

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(gb);
    setLayout(vLayout);
}

QDoubleSpinBox *PIPositionControlWidget::getStepSpinBox(int i) const
{
    return stepSpinBoxList.at(i);
}

DoubleSpinBox *PIPositionControlWidget::getVelocitySpinBox(int i) const
{
    return velocitySpinBoxList.at(i);
}

DoubleSpinBox *PIPositionControlWidget::getPositionSpinbox(int i) const
{
    return positionSpinboxList.at(i);
}

void PIPositionControlWidget::appendRow(PIDevice *device,
                                        const QString &axis,
                                        const QString &axisName)
{
    int col = 0;
    grid->addWidget(new QLabel(axisName.isNull() ? device->getVerboseName() : axisName), row, col++);
    QLabel *currentPos = new QLabel("0.000");
    currentPos->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    grid->addWidget(currentPos, row, col++);

    QPushButton *haltPushButton = new QPushButton("HALT");
    haltPushButton->setStyleSheet("QPushButton {color: red;}");
    grid->addWidget(haltPushButton, row, col++);

    QPushButton *negEndPushButton = new QPushButton("|<");
    negEndPushButton->setFixedWidth(30);
    negEndPushButton->setToolTip("Go to negative end");
    grid->addWidget(negEndPushButton, row, col++);

    QPushButton *stepDownPushButton = new QPushButton("<");
    stepDownPushButton->setFixedWidth(30);
    stepDownPushButton->setToolTip("Step down");
    grid->addWidget(stepDownPushButton, row, col++);

    DoubleSpinBox *positionSpinbox = new DoubleSpinBox();
    positionSpinboxList.append(positionSpinbox);
    positionSpinbox->setDecimals(3);
    positionSpinbox->setRange(0, 9e3);
    grid->addWidget(positionSpinbox, row, col++);

    QPushButton *stepUpPushButton = new QPushButton(">");
    stepUpPushButton->setFixedWidth(30);
    stepUpPushButton->setToolTip("Step up");
    grid->addWidget(stepUpPushButton, row, col++);

    QPushButton *posEndPushButton = new QPushButton(">|");
    posEndPushButton->setFixedWidth(30);
    posEndPushButton->setToolTip("Go to positive end");
    grid->addWidget(posEndPushButton, row, col++);

    QFrame *line;
    line = new QFrame();
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    grid->addWidget(line, row, col++);

    QDoubleSpinBox *stepSpinBox = new QDoubleSpinBox();
    stepSpinBoxList.append(stepSpinBox);
    stepSpinBox->setRange(0, 9e3);
    stepSpinBox->setValue(0.1);
    stepSpinBox->setDecimals(3);
    grid->addWidget(stepSpinBox, row, col++);

    DoubleSpinBox *velocitySpinBox = new DoubleSpinBox();
    velocitySpinBoxList.append(velocitySpinBox);
    velocitySpinBox->setRange(0, 9e3);
    velocitySpinBox->setValue(1);
    velocitySpinBox->setDecimals(3);
    grid->addWidget(velocitySpinBox, row, col++);

    row++;

    QState *cs = device->getConnectedState();
    QState *ds = device->getDisconnectedState();

    QList<QWidget *> wList;

    // enabled when connected, disabled when disconnected
    wList = {
        haltPushButton,
        positionSpinbox,
        negEndPushButton,
        stepDownPushButton,
        stepUpPushButton,
        posEndPushButton,
        stepSpinBox,
        velocitySpinBox,
    };

    for (QWidget *w : wList) {
        cs->assignProperty(w, "enabled", true);
        ds->assignProperty(w, "enabled", false);
    }

    connect(haltPushButton, &QPushButton::clicked, this, [=]() {
        try {
            device->halt(axis);
            device->getError();
        } catch (std::runtime_error e) {
            QMessageBox::critical(nullptr, "Error", e.what());
        }
    });

    enum ACTION {
        MOVE,
        NEGEND,
        STEPDOWN,
        STEPUP,
        POSEND,
        SETVELOCITY,
    };

    std::function<void(const enum ACTION)> performAction = [=](const enum ACTION a) {
        double pos = positionSpinbox->value();
        double vel = velocitySpinBox->value();
        double stepSize = stepSpinBox->value();

        double min, max;

        try {
            device->setVelocities(axis, &vel);

            if (a != MOVE) {
                currentPos->setStyleSheet("");
            }

            switch (a) {
            case MOVE:
                device->move(axis, &pos);
                break;

            case NEGEND:
                min = device->getTravelRangeLowEnd(axis).at(0);
                device->move(axis, &min);
                break;

            case STEPDOWN:
                device->setStepSize(axis, stepSize);
                device->stepDown(axis);
                break;

            case STEPUP:
                device->setStepSize(axis, stepSize);
                device->stepUp(axis);
                break;

            case POSEND:
                max = device->getTravelRangeHighEnd(axis).at(0);
                device->move(axis, &max);
                break;

            case SETVELOCITY:
                break;
            }
        } catch (std::runtime_error e) {
            QMessageBox::critical(nullptr, "Error", e.what());
        }
    };

    connect(positionSpinbox, &DoubleSpinBox::returnPressed, this, [=]() { performAction(MOVE); });

    connect(negEndPushButton, &QPushButton::clicked, this, [=]() { performAction(NEGEND); });

    connect(stepDownPushButton, &QPushButton::clicked, this, [=]() { performAction(STEPDOWN); });

    connect(stepUpPushButton, &QPushButton::clicked, this, [=]() { performAction(STEPUP); });

    connect(posEndPushButton, &QPushButton::clicked, this, [=]() { performAction(POSEND); });

    connect(velocitySpinBox, &DoubleSpinBox::returnPressed, this, [=]() {
        performAction(SETVELOCITY);
    });

    QTimer *updateTimer = new QTimer(this);
    updateTimer->setInterval(500);

    connect(updateTimer, &QTimer::timeout, this, [=]() {
        try {
            double pos = device->getCurrentPosition(axis).at(0);
            currentPos->setText(QString("%1").arg(pos, 0, 'f', 3));
            if (device->isOnTarget(axis)) {
                currentPos->setStyleSheet("QLabel {background-color: #c0fec0}");
            } else {
                currentPos->setStyleSheet("");
            }
        } catch (std::runtime_error e) {
        }
    });

    connect(
        device,
        &PIDevice::connected,
        this,
        [=]() {
            double min = device->getTravelRangeLowEnd(axis).at(0);
            double max = device->getTravelRangeHighEnd(axis).at(0);

            positionSpinbox->setRange(min, max);

            updateTimer->start();
        },
        Qt::QueuedConnection);

    connect(device, &PIDevice::disconnected, updateTimer, &QTimer::stop);
}

void PIPositionControlWidget::setTitle(const QString &title)
{
    gb->setTitle(title);
}
