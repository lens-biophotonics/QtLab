#include <QStringList>
#include <QRegularExpression>
#include <QtDebug>

#include "AA_MPDSnCxx.h"
#include "serialport.h"


AA_MPDSnCxx::AA_MPDSnCxx(QObject *parent) : QObject(parent)
{
    serial = new SerialPort(this);
    serial->setLineEndTermination("\r");
    serial->setBaudRate(57600);
    serial->setTimeout(200);
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
        nChannels = 0;
        QStringList sl = _getStatus();
        for (QString s : sl) {
            if (s.startsWith("l")) {
                nChannels++;
            }
        }
        for (QString s : sl) {
            status.append(new LineStatus());
        }
        getStatus();
        getSelectedChannel();
        emit connected();
    }
}

void AA_MPDSnCxx::close()
{
    serial->close();
    qDeleteAll(status);
    emit disconnected();
}

SerialPort *AA_MPDSnCxx::getSerialPort() const
{
    return serial;
}

QString AA_MPDSnCxx::getProductID()
{
    return serial->transceive("q", "?").remove("\n\r?").trimmed();
}

QStringList AA_MPDSnCxx::_getStatus()
{
    QStringList list;
    QString reply = serial->transceive("S", "?").remove("?");
    list = reply.split("\n\r");
    return list;
}

/**
 * @brief Query and return the status of lines.
 * @return
 */
QVector<AA_MPDSnCxx::LineStatus *> AA_MPDSnCxx::getStatus()
{
    QStringList sl = _getStatus();
    for (QString s : sl) {
        if (s.startsWith("l")) {
            parseStatusLine(s);
        }
    }
    return status;
}

/**
 * @brief Return the line status (device is not queried).
 * @return
 */
QVector<AA_MPDSnCxx::LineStatus *> AA_MPDSnCxx::getLineStatus()
{
    return status;
}

int AA_MPDSnCxx::getSelectedChannel()
{
    QString s = serial->transceive("X", "?");
    bool ok = false;
    int c = s.remove("Line number>").remove("\n\r?").toInt(&ok);
    if (!ok) {
        throw std::runtime_error(("Invalid response: " + s).toStdString());
    }
    selectedChannel = c;
    return c;
}

void AA_MPDSnCxx::selectChannel(int n)
{
    if (n < 1 || n > nChannels) {
        throw std::runtime_error(QString("Invalid channel %1").arg(n).toStdString());
    }

    QString s = serial->transceive(QString("X%1").arg(n), "?");

    bool ok;
    s.split("Line number>").last().remove("\n\r?").toInt(&ok);

    if (!ok) {
        throw std::runtime_error(("Invalid response: " + s).toStdString());
    }
}

double AA_MPDSnCxx::setFrequency(double freq)
{
    QString s = serial->transceive(QString("F%1").arg(freq, 0, 'f', 2), "?");
    bool ok;
    double d = s.split("Frequency>").last().remove("\n\r?").trimmed().toDouble(&ok);
    if (!ok) {
        throw std::runtime_error(("Invalid response: " + s).toStdString());
    }
    return d;
}

int AA_MPDSnCxx::setPower(int p)
{
    if (p < 0 || p > 63) {
        throw std::runtime_error(QString("ErrorAcoustoOpticFilter: requested power %1 out of range [0,63]").arg(p).toStdString());
    }
    QString s = serial->transceive(QString("P%1").arg(p), "?");
    bool ok;
    double i = s.split("Power>").last().remove("\n\r?").trimmed().toInt(&ok);
    if (!ok || i != p) {
        throw std::runtime_error(("Invalid response: " + s).toStdString());
    }
    return i;
}

double AA_MPDSnCxx::setPowerFineAdjustment(int line, int p)
{
    if (p < 0 || p > 1023) {
        throw std::runtime_error(QString("ErrorAcoustoOpticFilter: requested power %1 out of range [0,1023]").arg(p).toStdString());
    }
    QString s = serial->transceive(QString("L%1P%2").arg(line).arg(p, 4), "\n\r");
    QRegularExpression rx("^l(\\d)F([0-9.]+)P(-?[0-9.]+)S([0,1])\n\r$");
    QRegularExpressionMatch match = rx.match(s);

    auto errMsg = QString("Invalid response: " + s).toStdString();
    if (!match.hasMatch()) {
        throw std::runtime_error(errMsg);
    }

    bool ok;
    int c = 1;

    int i = match.captured(c++).toUInt(&ok);
    if (!ok || i != line) {
        throw std::runtime_error(errMsg);
    }

    double d;

    LineStatus *st = status.at(line);

    d = match.captured(c++).toDouble(&ok);
    if (!ok) {
        throw std::runtime_error(errMsg);
    }
    st->freq = d;

    d = match.captured(c++).toDouble(&ok);
    if (!ok) {
        throw std::runtime_error(errMsg);
    }
    st->power_dBm = d;

    i = match.captured(c++).toInt(&ok);
    if (!ok) {
        throw std::runtime_error(errMsg);
    }
    st->outputEnabled = i;

    return st->power_dBm;
}

double AA_MPDSnCxx::setPower_dBm(double dBm)
{
    QString s = serial->transceive(QString("D%1").arg(dBm), "?");
    bool ok;
    double d = s.split("Power (dBm)>").last().remove("dBm\n\r?").trimmed().toDouble(&ok);
    if (!ok) {
        throw std::runtime_error(("Invalid response: " + s).toStdString());
    }
    return d;
}

void AA_MPDSnCxx::reset()
{
    // We use transceive() instead of sendMsg() even if there is no response
    // because the reset command needs some sleep time.. we're using the
    // transceive timeout for this.
    serial->transceive("M");
}

/**
 * @brief Save current settings as default on device power-up
 */
void AA_MPDSnCxx::storeParams()
{
    serial->transceive("E", "?");
}

int AA_MPDSnCxx::getNChannels() const
{
    return nChannels;
}

void AA_MPDSnCxx::switchOn()
{
    serial->transceive("o1", "?");
}

void AA_MPDSnCxx::switchOff()
{
    serial->transceive("o0", "?");
}

void AA_MPDSnCxx::setExternalModeEnabled(bool enable)
{
    if (enable) {
        serial->transceive("i1", "?");  // sic
    } else {
        serial->transceive("i0", "?");  // sic
    }
    getStatus();
}

void AA_MPDSnCxx::setVMode5V()
{
    serial->transceive("v0", "?");
}

void AA_MPDSnCxx::setVMode10V()
{
    serial->transceive("v1", "?");
}

void AA_MPDSnCxx::setBlanking(bool enableOutput, bool enableExternal, bool store)
{
    QString s = QString("L0I%1O%2").arg((int)enableExternal).arg((int)enableOutput);
    if (store) {
        s += "E";
    }
    QString r = serial->transceive(s, "\n\r");
    QRegularExpression rx("^BS([0,1])I([0,1])\n\r$");
    QRegularExpressionMatch match = rx.match(r);

    if (!match.hasMatch()) {
        throw std::runtime_error(("Cannot parse string: " + r).toStdString());
    }

    bool ok1, ok2;

    bool output = match.captured(1).toInt(&ok1);
    bool external = match.captured(2).toInt(&ok2);

    if (!(output == enableOutput && external == enableExternal && ok1 && ok2)) {
        throw std::runtime_error(("Cannot parse string: " + r).toStdString());
    }
}

void AA_MPDSnCxx::parseStatusLine(const QString &s)
{
    QRegularExpression rx("^l(\\d) F=([0-9.]+) P=(-?[0-9.]+) (ON|OFF) (INT|EXT)ERNAL$");
    QRegularExpressionMatch match = rx.match(s);
    if (!match.hasMatch()) {
        throw std::runtime_error(("Cannot parse string: " + s).toStdString());
    }
    bool ok;
    int count = 0;
    int c = 1;
    int line = match.captured(c++).toInt(&ok); count += ok;
    double freq = match.captured(c++).toDouble(&ok); count += ok;
    double pow_dBm = match.captured(c++).toDouble(&ok); count += ok;
    if (count != 3) {
        throw std::runtime_error(("Cannot parse string: " + s).toStdString());
    }
    LineStatus *st = status.at(line);
    st->id = line;
    st->freq = freq;
    st->power_dBm = pow_dBm;
    if (match.captured(c++) == "ON") {
        st->outputEnabled = true;
    } else {
        st->outputEnabled = false;
    }
    if (match.captured(c++) == "EXT") {
        st->externalMode = true;
    } else {
        st->externalMode = false;
    }
}
