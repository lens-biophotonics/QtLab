#include "aa_aotf_widget.h"

#include <qtlab/widgets/customspinbox.h>

#include <QBoxLayout>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QListView>
#include <QMessageBox>
#include <QPushButton>
#include <QRadioButton>
#include <QSerialPortInfo>

#define CHECK_EXCEPTION(callable) \
    try { \
        callable; \
    } catch (std::runtime_error e) { \
        QMessageBox::critical(nullptr, "Error", e.what()); \
    }

AA_AOTFWidget::AA_AOTFWidget(AA_MPDSnCxx *aotf, int lines, QWidget *parent)
    : QWidget(parent)
    , aotf(aotf)
{
    setupUi(lines);
}

void AA_AOTFWidget::setupUi(int lines)
{
    QComboBox *serialPortComboBox = new QComboBox();
    QListView *view = new QListView();
    view->setFixedWidth(350);
    serialPortComboBox->setView(view);
    serialPortComboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
    serialPortComboBox->setMinimumContentsLength(29);

    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts()) {
        if (!info.manufacturer().startsWith("FTDI")) {
            continue;
        }
        QString descr = QString("%1 (%2, %3)")
                            .arg(info.portName())
                            .arg(info.description())
                            .arg(info.serialNumber());
        serialPortComboBox->addItem(descr, info.portName());
    }

    serialPortComboBox->setCurrentIndex(
        serialPortComboBox->findData(aotf->serialPort()->portName()));

    int row = 0;
    QGridLayout *gridTop = new QGridLayout();
    gridTop->addWidget(new QLabel("Serial port"), row, 0);
    gridTop->addWidget(serialPortComboBox, row++, 1);

    QHBoxLayout *hLayout = new QHBoxLayout();
    QPushButton *connectPushButton = new QPushButton("Connect");
    QPushButton *disconnectPushButton = new QPushButton("Disconnect");
    hLayout->addWidget(connectPushButton);
    hLayout->addWidget(disconnectPushButton);
    gridTop->addLayout(hLayout, row++, 1, 1, 1);

    connect(connectPushButton, &QPushButton::clicked, aotf, [=]() {
        aotf->serialPort()->setPortName(serialPortComboBox->currentData().toString());
        CHECK_EXCEPTION(aotf->connect())
    });

    // connect(disconnectPushButton, &QPushButton::clicked, aotf, &SerialDevice::disconnect);
    // causes QSocketNotifier: Socket notifiers cannot be enabled or disabled from another thread
    connect(disconnectPushButton, &QPushButton::clicked, aotf, [=]() {
        CHECK_EXCEPTION(aotf->disconnect())
    });

    // selected line

    QGridLayout *gridSelected = new QGridLayout();
    int i = 0;
    QLabel *lineLabel = new QLabel();
    lineLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    gridSelected->addWidget(new QLabel("Line"), i, 0);
    gridSelected->addWidget(lineLabel, i++, 1);

    DoubleSpinBox *freqSpinBox = new DoubleSpinBox();
    freqSpinBox->setDecimals(3);
    freqSpinBox->setSuffix("MHz");
    freqSpinBox->setRange(0, 1000);
    gridSelected->addWidget(new QLabel("Frequency"), i, 0);
    gridSelected->addWidget(freqSpinBox, i, 1);
    QPushButton *decrFreqPushButton = new QPushButton("-");
    decrFreqPushButton->setToolTip("Fine adjustment");
    gridSelected->addWidget(decrFreqPushButton, i, 2);
    QPushButton *incrFreqPushButton = new QPushButton("+");
    gridSelected->addWidget(incrFreqPushButton, i++, 3);
    incrFreqPushButton->setToolTip("Fine adjustment");

    connect(
        incrFreqPushButton,
        &QPushButton::clicked,
        this,
        [=]() { CHECK_EXCEPTION(freqSpinBox->setValue(aotf->stepFrequencyUp())) },
        Qt::DirectConnection);

    connect(
        decrFreqPushButton,
        &QPushButton::clicked,
        this,
        [=]() { CHECK_EXCEPTION(freqSpinBox->setValue(aotf->stepFrequencyDown())) },
        Qt::DirectConnection);

    connect(
        freqSpinBox,
        &DoubleSpinBox::returnPressed,
        this,
        [=](double value) { CHECK_EXCEPTION(freqSpinBox->setValue(aotf->setFrequency(value))) },
        Qt::DirectConnection);

    DoubleSpinBox *powerSpinBox = new DoubleSpinBox();
    powerSpinBox->setSuffix("dBm");
    powerSpinBox->setRange(-100, 100);
    gridSelected->addWidget(new QLabel("Power"), i, 0);
    gridSelected->addWidget(powerSpinBox, i, 1);
    QPushButton *decrPowerPushButton = new QPushButton("-");
    decrPowerPushButton->setToolTip("Fine adjustment");
    gridSelected->addWidget(decrPowerPushButton, i, 2);
    QPushButton *incrPowerPushButton = new QPushButton("+");
    gridSelected->addWidget(incrPowerPushButton, i++, 3);
    incrPowerPushButton->setToolTip("Fine adjustment");

    connect(
        incrPowerPushButton,
        &QPushButton::clicked,
        this,
        [=]() {
            CHECK_EXCEPTION(aotf->stepPowerUp())
            powerSpinBox->setValue(aotf->selectedChanelStatus()->getPower_dBm());
        },
        Qt::DirectConnection);

    connect(
        decrPowerPushButton,
        &QPushButton::clicked,
        this,
        [=]() {
            CHECK_EXCEPTION(powerSpinBox->setValue(aotf->stepPowerDown()))
            powerSpinBox->setValue(aotf->selectedChanelStatus()->getPower_dBm());
        },
        Qt::DirectConnection);

    connect(
        powerSpinBox,
        &DoubleSpinBox::returnPressed,
        this,
        [=](double value) { CHECK_EXCEPTION(powerSpinBox->setValue(aotf->setPower_dBm(value))) },
        Qt::DirectConnection);

    QGroupBox *selectedLineGb = new QGroupBox("Selected line");
    selectedLineGb->setLayout(gridSelected);

    // push buttons

    QBoxLayout *hPushButtonLayout = new QHBoxLayout();
    QPushButton *storePushButton = new QPushButton("Store");
    QPushButton *resetPushButton = new QPushButton("Reset");
    QPushButton *refreshPushButton = new QPushButton("Refresh");
    QPushButton *intModePushButton = new QPushButton("All INT");
    QPushButton *extModePushButton = new QPushButton("All EXT");
    hPushButtonLayout->addWidget(storePushButton);
    hPushButtonLayout->addWidget(resetPushButton);
    QFrame *line;
    line = new QFrame();
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    hPushButtonLayout->addWidget(line);
    hPushButtonLayout->addWidget(refreshPushButton);
    line = new QFrame();
    line = new QFrame();
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    hPushButtonLayout->addWidget(line);
    hPushButtonLayout->addWidget(intModePushButton);
    hPushButtonLayout->addWidget(extModePushButton);

    connect(
        storePushButton,
        &QPushButton::clicked,
        this,
        [=]() { CHECK_EXCEPTION(aotf->storeParams()) },
        Qt::DirectConnection);

    connect(
        resetPushButton,
        &QPushButton::clicked,
        this,
        [=]() { CHECK_EXCEPTION(aotf->reset()) },
        Qt::DirectConnection);

    connect(
        refreshPushButton,
        &QPushButton::clicked,
        this,
        [=]() { CHECK_EXCEPTION(aotf->refresh()) },
        Qt::DirectConnection);

    connect(
        intModePushButton,
        &QPushButton::clicked,
        this,
        [=]() { CHECK_EXCEPTION(aotf->setExternalModeEnabled(false)); },
        Qt::DirectConnection);

    connect(
        extModePushButton,
        &QPushButton::clicked,
        this,
        [=]() { CHECK_EXCEPTION(aotf->setExternalModeEnabled(true)); },
        Qt::DirectConnection);

    // vmode
    QRadioButton *_5VMode = new QRadioButton("5V");
    QRadioButton *_10VMode = new QRadioButton("10V");

    auto updateVMode = [=]() {
        _5VMode->setChecked(!aotf->isVMode10V());
        _10VMode->setChecked(aotf->isVMode10V());
    };

    connect(_5VMode, &QRadioButton::clicked, [=]() { CHECK_EXCEPTION(aotf->setVMode5V()); });
    connect(_10VMode, &QRadioButton::clicked, [=]() { CHECK_EXCEPTION(aotf->setVMode10V()); });

    connect(aotf, &SerialDevice::connected, updateVMode);
    connect(refreshPushButton, &QPushButton::clicked, this, updateVMode, Qt::QueuedConnection);
    connect(resetPushButton, &QPushButton::clicked, this, updateVMode, Qt::QueuedConnection);

    // line status

    int col = 0;
    QGridLayout *gridBottom = new QGridLayout();

    gridBottom->addWidget(new QLabel("Select"), 0, col++);
    gridBottom->addWidget(new QLabel("Frequency"), 0, col++);
    gridBottom->addWidget(new QLabel("Power"), 0, col++);
    gridBottom->addWidget(new QLabel("Status"), 0, col++);
    gridBottom->addWidget(new QLabel("Mode"), 0, col++);
    gridBottom->addWidget(new QLabel("On/Off"), 0, col++);
    gridBottom->addWidget(new QLabel("Ext"), 0, col++);

    QList<QLabel *> freqLabels;
    QList<QLabel *> powerLabels;
    QList<QLabel *> statusLabels;
    QList<QLabel *> modeLabels;

    QLabel *blanking = new QLabel("Blanking");
    blanking->setAlignment(Qt::AlignCenter);
    gridBottom->addWidget(blanking, 1, 0);

    QCheckBox *blnkStatusCheckbox = new QCheckBox();
    gridBottom->addWidget(blnkStatusCheckbox, 1, 5, Qt::AlignHCenter);
    QCheckBox *blnkExternalCheckbox = new QCheckBox();
    gridBottom->addWidget(blnkExternalCheckbox, 1, 6);

    auto setBlanking = [=]() {
        aotf->setBlanking(blnkStatusCheckbox->isChecked(), blnkExternalCheckbox->isChecked());
    };

    auto updateBlanking = [=]() {
        blnkStatusCheckbox->setChecked(aotf->isBlankingEnabled());
        blnkExternalCheckbox->setChecked(aotf->isBlankingExternal());
    };

    connect(blnkStatusCheckbox, &QCheckBox::clicked, setBlanking);
    connect(blnkExternalCheckbox, &QCheckBox::clicked, setBlanking);
    connect(resetPushButton, &QPushButton::clicked, this, updateBlanking, Qt::QueuedConnection);
    connect(refreshPushButton, &QPushButton::clicked, this, updateBlanking, Qt::QueuedConnection);

    connect(aotf, &SerialDevice::connected, updateBlanking);

    for (int i = 1; i <= lines; ++i) {
        col = 0;
        QRadioButton *radio = new QRadioButton(QString("Line %1").arg(i));
        gridBottom->addWidget(radio, i + 1, col++);

        QLabel *freqLabel = new QLabel("141.500 MHz");
        freqLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        freqLabel->setAlignment(Qt::AlignRight);
        freqLabels.append(freqLabel);
        gridBottom->addWidget(freqLabel, i + 1, col++);

        QLabel *powerLabel = new QLabel("-6.70 dBm");
        powerLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        powerLabel->setAlignment(Qt::AlignRight);
        powerLabels.append(powerLabel);
        gridBottom->addWidget(powerLabel, i + 1, col++);

        QLabel *statusLabel = new QLabel("ON");
        statusLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        statusLabel->setAlignment(Qt::AlignRight);
        statusLabels.append(statusLabel);
        gridBottom->addWidget(statusLabel, i + 1, col++);

        QLabel *modeLabel = new QLabel("EXT");
        modeLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        modeLabel->setAlignment(Qt::AlignRight);
        modeLabels.append(modeLabel);
        gridBottom->addWidget(modeLabel, i + 1, col++);

        QCheckBox *statusCheckbox = new QCheckBox();
        gridBottom->addWidget(statusCheckbox, i + 1, col++, Qt::AlignHCenter);

        QCheckBox *externalCheckbox = new QCheckBox();
        gridBottom->addWidget(externalCheckbox, i + 1, col++);

        auto updateRow = [=]() {
            AA_MPDSnCxx::LineStatus *st = aotf->getLineStatus().at(i);
            freqLabel->setText(QString("%1 MHz").arg(st->getFreq(), 0, 'f', 3));
            powerLabel->setText(QString("%1 dBm").arg(st->getPower_dBm(), 0, 'f', 2));
            statusLabel->setText(st->isOutputEnabled() ? "ON" : "OFF");
            statusLabel->setStyleSheet(st->isOutputEnabled() ? "QLabel {color: green}" : "");
            modeLabel->setText(st->isExternalModeEnabled() ? "EXT" : "INT");
            statusCheckbox->setChecked(st->isOutputEnabled());
            externalCheckbox->setChecked(st->isExternalModeEnabled());

            if (aotf->getSelectedChannel() != i) {
                return;
            }
            radio->setChecked(true);
            lineLabel->setText(QString("%1").arg(i));
            freqSpinBox->setValue(st->getFreq());
            powerSpinBox->setValue(st->getPower_dBm());
        };

        connect(statusCheckbox, &QCheckBox::clicked, [=](bool checked) {
            CHECK_EXCEPTION(aotf->setOutputEnabled(i, checked))
            updateRow();
        });

        connect(externalCheckbox, &QCheckBox::clicked, [=](bool checked) {
            CHECK_EXCEPTION(aotf->setExternalModeEnabled(i, checked))
            updateRow();
        });

        connect(radio, &QCheckBox::clicked, [=](bool checked) {
            if (checked) {
                CHECK_EXCEPTION(aotf->selectChannel(i))
                updateRow();
            };
        });

        connect(aotf, &SerialDevice::connected, updateRow);
        QList<QWidget *> wList;
        wList << refreshPushButton << resetPushButton << intModePushButton << extModePushButton
              << incrFreqPushButton << decrFreqPushButton << incrPowerPushButton
              << decrPowerPushButton;
        for (QWidget *pb : wList) {
            connect((QPushButton *) pb, &QPushButton::clicked, this, updateRow, Qt::QueuedConnection);
        }

        wList.clear();
        wList << freqSpinBox << powerSpinBox;
        for (QWidget *pb : wList) {
            connect((DoubleSpinBox *) pb,
                    &DoubleSpinBox::returnPressed,
                    this,
                    updateRow,
                    Qt::QueuedConnection);
        }
    }

    QGroupBox *lineStatusGb = new QGroupBox("Line status");
    lineStatusGb->setLayout(gridBottom);

    // layout

    QBoxLayout *vLayoutLeft = new QVBoxLayout();
    vLayoutLeft->addWidget(selectedLineGb);

    QGroupBox *vModeGroupBox = new QGroupBox("VMode");
    QVBoxLayout *tempLayout = new QVBoxLayout();
    tempLayout->addWidget(_5VMode);
    tempLayout->addWidget(_10VMode);
    vModeGroupBox->setLayout(tempLayout);

    QBoxLayout *vLayoutRight = new QVBoxLayout();
    vLayoutRight->addWidget(vModeGroupBox);

    hLayout = new QHBoxLayout();
    hLayout->addLayout(vLayoutLeft);
    hLayout->addLayout(vLayoutRight);

    QBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addLayout(hLayout);
    vLayout->addWidget(lineStatusGb);
    vLayout->addLayout(hPushButtonLayout);
    QWidget *containerWidget = new QWidget();
    containerWidget->setLayout(vLayout);

    QBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(gridTop);
    mainLayout->addWidget(containerWidget);
    setLayout(mainLayout);

    QState *cs = aotf->serialPort()->getConnectedState();
    QState *ds = aotf->serialPort()->getDisconnectedState();

    QList<QWidget *> wList;

    // enabled when connected, disabled when disconnected
    wList = {
        containerWidget,
        disconnectPushButton,
    };

    for (QWidget *w : wList) {
        cs->assignProperty(w, "enabled", true);
        ds->assignProperty(w, "enabled", false);
    }

    // enabled when disconnected, disabled when connected
    wList = {
        serialPortComboBox,
        connectPushButton,
    };

    for (QWidget *w : wList) {
        cs->assignProperty(w, "enabled", false);
        ds->assignProperty(w, "enabled", true);
    }
}
