#include "customspinbox.h"

#include <QLineEdit>

SpinBox::SpinBox(QWidget *parent)
    : QSpinBox(parent)
{
    connect(lineEdit(), &QLineEdit::returnPressed, [=]() { emit returnPressed(value()); });
}

DoubleSpinBox::DoubleSpinBox(QWidget *parent)
    : QDoubleSpinBox(parent)
{
    connect(lineEdit(), &QLineEdit::returnPressed, [=]() { emit returnPressed(value()); });
}
