#include <QRegularExpression>
#include <QStringList>
#include <QtDebug>

#include "AA_MPDSnCxx.h"
#include "serialport.h"


AcoustoOpticFilter::AcoustoOpticFilter(QObject *parent) : QObject(parent)
{
    serial = new SerialPort(this);
    serial->setLineEndTermination("\r"); // carriage return
    serial->setBaudRate(AOTF_SERIAL_BAUD_RATE);
    serial->setTimeout(1000);
    setMotionTime(AOTF_SWITCH_TIME); // wait in ms between reaching any position
}

AcoustoOpticFilter::~AcoustoOpticFilter()
{
    close();
}

void AcoustoOpticFilter::open()
{
    bool ret = serial->open();
    if (!ret)
        throw std::runtime_error(QString("Cannot connect to AOTF with serial number " + serial->getSerialNumber()).toLatin1());
    else {
        serial->readAll();  // empty input buffer
        //setPositionNumber(getPositionCount());
        emit connected();
    }
}

void AcoustoOpticFilter::close()
{
    serial->close();
    emit disconnected();
}

SerialPort *AcoustoOpticFilter::getSerialPort() const
{
    return serial;
}

QString AcoustoOpticFilter::getID()
{
    QString reply = transceiveChkSyntaxError("q");
    reply = reply.remove("\n");
    //reply = reply.trimmed();
    return reply;
}

QStringList AcoustoOpticFilter::getStatus()
{
    QStringList list;
    QString reply = transceiveChkSyntaxError("S");
    //reply = reply.trimmed();
    list = reply.split("\n");
    return list;
}

QString AcoustoOpticFilter::getChannelInfo()
{
    QStringList reply = getStatus(); // TODO get channel info from here
    foreach(QString item, reply)
         qDebug() << "List items = " << item;
    return reply.at(1);
}

QString AcoustoOpticFilter::getDeviceInfo()
{
    QString reply = transceiveChkSyntaxError("S"); // TODO get profile info from here
    return reply;
}

int AcoustoOpticFilter::getChannel()
{
    QString reply = transceiveChkSyntaxError("X");
    reply = reply.remove("Line number>").trimmed();
    return castStringToIntChkError(reply);
}

void AcoustoOpticFilter::setChannel(int n)
{
    if (n < 1 || n > 8) // TODO learn number of channels
        qDebug() << QString("ErrorAcoustoOpticFilter: requested channel %1 out of range [1,8]").arg(n);
    else {
        QString reply = transceiveChkSyntaxError(QString("X%1").arg(n));
        reply = reply.remove("Line number>").trimmed();
        if (castStringToIntChkError(reply.at(2))!=n)
            qDebug() << QString("ErrorAcoustoOpticFilter: requested channel %1 not set").arg(n);
    }
}

float AcoustoOpticFilter::getFrequency()
{
    QString reply = transceiveChkSyntaxError("F"); // FIXME sets frequency to default value, use status output
    reply = reply.remove("Frequency>").trimmed();
    return castStringToFloatChkError(reply);
}

void AcoustoOpticFilter::setFrequency(float freq)
{
    if (freq<74.0 || freq > 158.0) // TODO learn edge frequencies
        qDebug() << QString("ErrorAcoustoOpticFilter: requested frequency %1 out of range [74.0,158.0]").arg(freq);
    else {
        QString reply = transceiveChkSyntaxError(QString("F%1").arg(freq));
        reply = reply.remove("Frequency>").trimmed();
        QStringList list = reply.split(" ");
        if (castStringToFloatChkError(list.at(1))!=freq)
            qDebug() << QString("ErrorAcoustoOpticFilter: requested frequency %1 not set").arg(freq);
    }
}


int AcoustoOpticFilter::getPower()
{
    QString reply = transceiveChkSyntaxError("P"); // FIXME sets power to default value, use status output
    reply = reply.remove("Power>").trimmed();
    return castStringToIntChkError(reply);
}

void AcoustoOpticFilter::setPower(int amp)
{
    if (amp<0 || amp > 63) // TODO learn max power
        qDebug() << QString("ErrorAcoustoOpticFilter: requested power %1 out of range [0,63]").arg(amp);
    else {
        QString reply = transceiveChkSyntaxError(QString("P%1").arg(amp));
        reply = reply.remove("Power>").trimmed();
        QStringList list = reply.split(" ");
        if (castStringToIntChkError(list.at(1))!=amp)
            qDebug() << QString("ErrorAcoustoOpticFilter: requested power %1 not set").arg(amp);
    }
}


float AcoustoOpticFilter::getPowerDBm()
{
    QString reply = transceiveChkSyntaxError("D"); // FIXME sets power to default value, use status output
    reply = reply.remove("Power (dBm)>").trimmed();
    return castStringToFloatChkError(reply);
}

void AcoustoOpticFilter::setPowerDBm(float dBm)
{
    if (dBm > 22.5) // TODO learn edge powers
        qDebug() << QString("ErrorAcoustoOpticFilter: requested power %1 out of range [,22.5]").arg(dBm);
    else {
        QString reply = transceiveChkSyntaxError(QString("D%1").arg(dBm));
        reply = reply.remove("Power (dBm)>").trimmed();
        QStringList list = reply.split(" ");
        if (castStringToFloatChkError(list.at(1))!=dBm)
            qDebug() << QString("ErrorAcoustoOpticFilter: requested power%1 not set").arg(dBm);
    }
}

//    qDebug() << reply;
//    QStringList list;
//    list = reply.split("\n");
//    list = list.replaceInStrings("Line number>","");
//    foreach(QString item, list)
//         qDebug() << "List items = " << item;



//int AcoustoOpticFilter::getPosition()
//{
//    QString str = transceiveChkSyntaxError("pos?");
//    return castStringToIntChkError(str);
//}

//int AcoustoOpticFilter::getPositionCount() // return wheel type, has either 6 or 12 filter slots
//{
//    QString str = transceiveChkSyntaxError("pcount?");
//    return castStringToIntChkError(str);
//}

//int AcoustoOpticFilter::getPositionNumber() const
//{
//    return positionNumber;
//}

//void AcoustoOpticFilter::setPositionNumber(const int count)
//{
//    positionNumber = count;
//}

int AcoustoOpticFilter::getMotionTime() const
{
    return motionTime; // ms
}

void AcoustoOpticFilter::setMotionTime(const int timewait)
{
    motionTime = timewait; // ms
}


//void AcoustoOpticFilter::restoreDefaultSettings()
//{
//    //transceiveChkSyntaxError(QString("M")); // Hard reset by software
//}

void AcoustoOpticFilter::reset()
{
    transceiveChkSyntaxError(QString("M")); // Hard reset by software
}

void AcoustoOpticFilter::saveSettings() // save current settings as default on device power-up
{
    transceiveChkSyntaxError(QString("E"));
}

//QString AcoustoOpticFilter::setPosition(int n)
//{
//    if (n < 1 || n > positionNumber)
//        return QString("ErrorAcoustoOpticFilter: requested position %1 out of range [1,%2]").arg(n).arg(positionNumber);
//    else
//        return transceiveChkSyntaxError(QString("pos=%1").arg(n));
//}

//void AcoustoOpticFilter::setPositionCount(int n)
//{
//    transceiveChkSyntaxError(QString("pcount=%1").arg(n));
//}

QString AcoustoOpticFilter::getVerboseName() const
{
    return verboseName;
}

void AcoustoOpticFilter::setVerboseName(const QString &value)
{
    verboseName = value;
}

//QStringList AcoustoOpticFilter::getFilterListName() const // TODO Dynamically load from text file?
//{
//    QStringList list;
//    QString str = "NF03-405/488/561/635E,FF02-447/60,FF03-525/50,FF01-600/52,FF01-697/70,empty";
//    list = str.split(",");
//    return list;
//}

//QString AcoustoOpticFilter::getFilterName(int n)
//{
//    if (n < 1 || n > positionNumber) {
//        return QString("ErrorAcoustoOpticFilter: requested position %1 out of range [1,%2]").arg(n).arg(positionNumber);
//    }
//    else {
//        QStringList list = getFilterListName();
//        return list.at(n);
//    }
//}

QString AcoustoOpticFilter::transceiveChkSyntaxError(QString cmd)
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

void AcoustoOpticFilter::removeEcho(QString cmd)
{
    QString cmdecho = QString();
    do {
        QString msg = serial->receive();
        cmdecho.append(msg);
        //qDebug() << cmdecho;
    } while (!cmdecho.contains(cmd, Qt::CaseSensitive));
}

QString AcoustoOpticFilter::removeTrailingWhitespace(const QString& str) {
  int n = str.size() - 1;
  for (; n >= 0; --n) {
    if (!str.at(n).isSpace()) {
      return str.left(n + 1);
    }
  }
  return "";
}

int AcoustoOpticFilter::castStringToIntChkError(QString str)
{
    bool ok;
    int integer = str.toInt(&ok);
    if (!ok) {
        throw std::runtime_error(QString("Cannot convert string to int: " + str).toLatin1());
    }
    return integer;
}

float AcoustoOpticFilter::castStringToFloatChkError(QString str)
{
    bool ok;
    float flt = str.toFloat(&ok);
    if (!ok) {
        throw std::runtime_error(QString("Cannot convert string to float: " + str).toLatin1());
    }
    return flt;
}
