#include <QStringList>
#include <QtDebug>

#include "AA_MPDSnCxx.h"
#include "serialport.h"


AA_MPDSnCxx::AA_MPDSnCxx(QObject *parent) : QObject(parent)
{
    serial = new SerialPort(this);
    serial->setLineEndTermination("\r"); // carriage return
    serial->setBaudRate(AOTF_SERIAL_BAUD_RATE);
    serial->setTimeout(1000);
}

AA_MPDSnCxx::~AA_MPDSnCxx()
{
    close();
}

void AA_MPDSnCxx::open()
{
    bool ret = serial->open();
    if (!ret)
        throw std::runtime_error(QString("Cannot connect to AOTF with serial number " + serial->getSerialNumber()).toLatin1());
    else {
        serial->readAll();  // empty input buffer
        emit connected();
    }
}

void AA_MPDSnCxx::close()
{
    serial->close();
    emit disconnected();
}

SerialPort *AA_MPDSnCxx::getSerialPort() const
{
    return serial;
}

QString AA_MPDSnCxx::getID()
{
    QString reply = transceiveChkSyntaxError("q");
    reply = reply.remove("\n");
    return reply;
}

QStringList AA_MPDSnCxx::getStatus()
{
    QStringList list;
    QString reply = transceiveChkSyntaxError("S");
    list = reply.split("\n");
    return list;
}

QString AA_MPDSnCxx::getChannelInfo()
{
    QStringList reply = getStatus(); // TODO get channel info from here
    foreach(QString item, reply)
    qDebug() << "List items = " << item;
    return reply.at(1);
}

QString AA_MPDSnCxx::getDeviceInfo()
{
    QString reply = transceiveChkSyntaxError("S"); // TODO get profile info from here
    return reply;
}

int AA_MPDSnCxx::getChannel()
{
    QString reply = transceiveChkSyntaxError("X");
    reply = reply.remove("Line number>").trimmed();
    return castStringToIntChkError(reply);
}

void AA_MPDSnCxx::setChannel(int n)
{
    if (n < 1 || n > 8) // TODO learn number of channels
        qDebug() << QString("ErrorAcoustoOpticFilter: requested channel %1 out of range [1,8]").arg(n);
    else {
        QString reply = transceiveChkSyntaxError(QString("X%1").arg(n));
        reply = reply.remove("Line number>").trimmed();
        if (castStringToIntChkError(reply.at(2)) != n)
            qDebug() << QString("ErrorAcoustoOpticFilter: requested channel %1 not set").arg(n);
    }
}

float AA_MPDSnCxx::getFrequency()
{
    QString reply = transceiveChkSyntaxError("F"); // FIXME sets frequency to default value, use status output
    reply = reply.remove("Frequency>").trimmed();
    return castStringToFloatChkError(reply);
}

void AA_MPDSnCxx::setFrequency(float freq)
{
    if (freq < 74.0 || freq > 158.0) // TODO learn edge frequencies
        qDebug() << QString("ErrorAcoustoOpticFilter: requested frequency %1 out of range [74.0,158.0]").arg(freq);
    else {
        QString reply = transceiveChkSyntaxError(QString("F%1").arg(freq));
        reply = reply.remove("Frequency>").trimmed();
        QStringList list = reply.split(" ");
        if (castStringToFloatChkError(list.at(1)) != freq)
            qDebug() << QString("ErrorAcoustoOpticFilter: requested frequency %1 not set").arg(freq);
    }
}


int AA_MPDSnCxx::getPower()
{
    QString reply = transceiveChkSyntaxError("P"); // FIXME sets power to default value, use status output
    reply = reply.remove("Power>").trimmed();
    return castStringToIntChkError(reply);
}

void AA_MPDSnCxx::setPower(int amp)
{
    if (amp < 0 || amp > 63) // TODO learn max power
        qDebug() << QString("ErrorAcoustoOpticFilter: requested power %1 out of range [0,63]").arg(amp);
    else {
        QString reply = transceiveChkSyntaxError(QString("P%1").arg(amp));
        reply = reply.remove("Power>").trimmed();
        QStringList list = reply.split(" ");
        if (castStringToIntChkError(list.at(1)) != amp)
            qDebug() << QString("ErrorAcoustoOpticFilter: requested power %1 not set").arg(amp);
    }
}


float AA_MPDSnCxx::getPowerDBm()
{
    QString reply = transceiveChkSyntaxError("D"); // FIXME sets power to default value, use status output
    reply = reply.remove("Power (dBm)>").trimmed();
    return castStringToFloatChkError(reply);
}

void AA_MPDSnCxx::setPowerDBm(float dBm)
{
    if (dBm > 22.5) // TODO learn edge powers
        qDebug() << QString("ErrorAcoustoOpticFilter: requested power %1 out of range [,22.5]").arg(dBm);
    else {
        QString reply = transceiveChkSyntaxError(QString("D%1").arg(dBm));
        reply = reply.remove("Power (dBm)>").trimmed();
        QStringList list = reply.split(" ");
        if (castStringToFloatChkError(list.at(1)) != dBm)
            qDebug() << QString("ErrorAcoustoOpticFilter: requested power%1 not set").arg(dBm);
    }
}

void AA_MPDSnCxx::reset()
{
    transceiveChkSyntaxError(QString("M")); // Hard reset by software
}

void AA_MPDSnCxx::saveSettings() // save current settings as default on device power-up
{
    transceiveChkSyntaxError(QString("E"));
}

QString AA_MPDSnCxx::transceiveChkSyntaxError(QString cmd)
{
    serial->sendMsg(cmd);
    //removeEcho(cmd);
    QString reply = serial->receive();
    //reply.append(serial->receive()); // sometimes the device does not send the full reply during one communication
    //reply.remove(serial->getLineEndTermination());
    reply = reply.remove("?");
    reply = reply.trimmed();
    //reply.remove(QRegExp("[<>]"));
    //qDebug() << reply;
    if (reply.startsWith("\f")) {
        throw std::runtime_error(reply.toLatin1());
    }
    return reply;
}

int AA_MPDSnCxx::castStringToIntChkError(QString str)
{
    bool ok;
    int integer = str.toInt(&ok);
    if (!ok) {
        throw std::runtime_error(QString("Cannot convert string to int: " + str).toLatin1());
    }
    return integer;
}

float AA_MPDSnCxx::castStringToFloatChkError(QString str)
{
    bool ok;
    float flt = str.toFloat(&ok);
    if (!ok) {
        throw std::runtime_error(QString("Cannot convert string to float: " + str).toLatin1());
    }
    return flt;
}
