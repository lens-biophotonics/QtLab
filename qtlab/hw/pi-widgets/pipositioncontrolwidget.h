#ifndef PIPOSITIONCONTROLWIDGET_H
#define PIPOSITIONCONTROLWIDGET_H

#include <QDoubleSpinBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QWidget>

class PIDevice;
class DoubleSpinBox;

class PIPositionControlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PIPositionControlWidget(QWidget *parent = nullptr);
    void appendRow(PIDevice *device, const QString &axis, const QString &axisName = QString());

    void setTitle(const QString &title);

    DoubleSpinBox *getPositionSpinbox(int i) const;
    DoubleSpinBox *getVelocitySpinBox(int i) const;
    QDoubleSpinBox *getStepSpinBox(int i) const;

private:
    void setupUI();

    int row = 0;
    PIDevice *device;

    QGridLayout *grid;
    QGroupBox *gb;

    QList<DoubleSpinBox *> positionSpinboxList;
    QList<DoubleSpinBox *> velocitySpinBoxList;
    QList<QDoubleSpinBox *> stepSpinBoxList;
};

#endif // PIPOSITIONCONTROLWIDGET_H
