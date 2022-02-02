#ifndef PICONTROLLERSETTINGSWIDGET_H
#define PICONTROLLERSETTINGSWIDGET_H

#include <QComboBox>
#include <QDialog>
#include <QLabel>
#include <QSpinBox>
#include <QWidget>

class PIDevice;

class PIControllerSettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PIControllerSettingsWidget(PIDevice *device, QWidget *parent = nullptr);

signals:

public slots:

private slots:
    void configureStages();
    void refreshValues();
    void connectDevice();

private:
    void setupUI();
    PIDevice *device;

    QLabel *axisIdentifiersLabel;
    QLabel *referencedStateLabel;
    QLabel *stagesLabel;

    QComboBox *serialPortComboBox;
    QSpinBox *deviceNumberSpinBox;
    QComboBox *baudComboBox;
};

#endif // PICONTROLLERSETTINGSWIDGET_H
