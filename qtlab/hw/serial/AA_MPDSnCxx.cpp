#include <QStringList>
#include <QRegularExpression>
#include <QThread>

#include "AA_MPDSnCxx.h"
#include "serialport.h"


AA_MPDSnCxx::AA_MPDSnCxx(QObject *parent) : SerialDevice(parent)
{
    serialPort->setLineEndTermination("\r");
    serialPort->setBaudRate(57600);
    serialPort->setTimeout(200);
}

void AA_MPDSnCxx::postConnect_impl()
{
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
    refresh();
}

bool AA_MPDSnCxx::isBlankingExternal() const
{
    return blankingExternal;
}

void AA_MPDSnCxx::refresh()
{
    getStatus();
    getSelectedChannel();
    parseHelp();
}

bool AA_MPDSnCxx::isBlankingEnabled() const
{
    return blankingEnabled;
}

bool AA_MPDSnCxx::isVMode10V() const
{
    return VMode10V;
}

QString AA_MPDSnCxx::getProductID()
{
    return serialPort->transceive("q", "?").remove("\n\r?").trimmed();
}

QStringList AA_MPDSnCxx::_getStatus()
{
    QStringList list;
    QString reply = serialPort->transceive("S", "?").remove("?");
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
        } else if (s.startsWith("Blanking")) {
            QRegularExpression rx("^Blanking (ON|OFF) (INT|EXT)ERNAL$");
            QRegularExpressionMatch match = rx.match(s);
            if (!match.hasMatch()) {
                throw std::runtime_error(QString("Invalid response: %1").arg(s).toStdString());
            }
            if (match.captured(1) == "ON") {
                blankingEnabled = true;
            } else {
                blankingEnabled = false;
            }
            if (match.captured(2) == "EXT") {
                blankingExternal = true;
            } else {
                blankingExternal = false;
            }
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

AA_MPDSnCxx::LineStatus *AA_MPDSnCxx::selectedChanelStatus()
{
    return status.at(selectedChannel);
}

int AA_MPDSnCxx::getSelectedChannel()
{
    QString s = serialPort->transceive("X", "?");
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

    QString s = serialPort->transceive(QString("X%1").arg(n), "?");

    bool ok;
    s.split("Line number>").last().remove("\n\r?").toInt(&ok);

    if (!ok) {
        throw std::runtime_error(("Invalid response: " + s).toStdString());
    }
}

double AA_MPDSnCxx::setFrequency(double freq)
{
    QString s = serialPort->transceive(QString("F%1").arg(freq, 0, 'f', 2), "?");
    bool ok;
    double d = s.split("Frequency>").last().remove("\n\r?").trimmed().toDouble(&ok);
    if (!ok) {
        throw std::runtime_error(("Invalid response: " + s).toStdString());
    }
    status.at(selectedChannel)->freq = d;
    return d;
}

int AA_MPDSnCxx::setPower(int p)
{
    QString s = serialPort->transceive(QString("P%1").arg(p), "?");
    bool ok;
    double i = s.split("Power>").last().remove("\n\r?").trimmed().toInt(&ok);
    if (!ok || i != p) {
        throw std::runtime_error(("Invalid response: " + s).toStdString());
    }
    return i;
}

double AA_MPDSnCxx::setPowerFineAdjustment(int line, int p)
{
    QString s = serialPort->transceive(QString("L%1P%2").arg(line).arg(p, 4), "\n\r");

    parseLResponse(s);

    return status.at(line)->power_dBm;
}

double AA_MPDSnCxx::setPower_dBm(double dBm)
{
    QString s = serialPort->transceive(QString("D%1").arg(dBm), "?");
    bool ok;
    double d = s.split("Power (dBm)>").last().remove("dBm\n\r?").trimmed().toDouble(&ok);
    if (!ok) {
        throw std::runtime_error(("Invalid response: " + s).toStdString());
    }
    status.at(selectedChannel)->power_dBm = d;
    return d;
}

void AA_MPDSnCxx::reset()
{
    serialPort->transceive("M");
    thread()->msleep(200);
    getStatus();
}

/**
 * @brief Save current settings as default on device power-up
 */
void AA_MPDSnCxx::storeParams()
{
    serialPort->transceive("E", "?");
}

int AA_MPDSnCxx::getNChannels() const
{
    return nChannels;
}

void AA_MPDSnCxx::setExternalModeEnabled(bool enable)
{
    if (enable) {
        serialPort->transceive("i1", "?");  // sic
    } else {
        serialPort->transceive("i0", "?");  // sic
    }
    getStatus();
}

void AA_MPDSnCxx::setExternalModeEnabled(int line, bool enable)
{
    parseLResponse(serialPort->transceive(QString("L%1I%2").arg(line).arg(enable), "\n\r"));
    status.at(line)->externalMode = enable;
}

void AA_MPDSnCxx::setOutputEnabled(bool enable)
{
    serialPort->transceive(QString("o%1").arg(enable ? "1" : "0"), "?");
}

void AA_MPDSnCxx::setOutputEnabled(int line, bool enable)
{
    parseLResponse(serialPort->transceive(QString("L%1O%2").arg(line).arg(enable), "\n\r"));
}

void AA_MPDSnCxx::setVMode5V()
{
    serialPort->transceive("v0", "?");
}

void AA_MPDSnCxx::setVMode10V()
{
    serialPort->transceive("v1", "?");
}

double AA_MPDSnCxx::_stepFrequency(bool up)
{
    QString r = serialPort->transceive(up ? "6" : "4", "?");
    QRegularExpression rx("Frequency> ([0-9.]+) MHz");
    QRegularExpressionMatch match = rx.match(r);
    if (!match.hasMatch()) {
        throw std::runtime_error(("Cannot parse string: " + r).toStdString());
    }

    double d = match.captured(1).toDouble();
    status.at(selectedChannel)->freq = d;
    return d;
}

int AA_MPDSnCxx::_stepPower(bool up)
{
    QString r = serialPort->transceive(up ? "8" : "2", "?");
    QRegularExpression rx("P=(\\d+)[(]([0-9.]+)dBm[)]");
    QRegularExpressionMatch match = rx.match(r);
    if (!match.hasMatch()) {
        throw std::runtime_error(("Cannot parse string: " + r).toStdString());
    }

    status.at(selectedChannel)->power_dBm = match.captured(2).toDouble();
    return match.captured(1).toInt();
}

int AA_MPDSnCxx::_stepProfile(bool up)
{
    QString r = serialPort->transceive(up ? "3" : "1", "\n\n\r> ");
    QRegularExpression rx("Selected profile: (\\d)\n\r");
    QRegularExpressionMatch match = rx.match(r);
    if (!match.hasMatch()) {
        throw std::runtime_error(("Cannot parse string: " + r).toStdString());
    }

    getStatus();
    return match.captured(1).toInt();
}

double AA_MPDSnCxx::stepFrequencyUp()
{
    return _stepFrequency(true);
}

double AA_MPDSnCxx::stepFrequencyDown()
{
    return _stepFrequency(false);
}

/**
 * @brief Increment fine power adjustment.
 * @return Fine power adjustment.
 *
 * The LineStatus::power_dBm is also updated accordingly.
 */
int AA_MPDSnCxx::stepPowerUp()
{
    return _stepPower(true);
}

/**
 * @brief Decrement fine power adjustment.
 * @return Fine power adjustment.
 *
 * The LineStatus::power_dBm is also updated accordingly.
 */
int AA_MPDSnCxx::stepPowerDown()
{
    return _stepPower(false);
}

/**
 * @brief Increment profile.
 * @return Current profile.
 *
 * The LineStatus struct is also updated with the values of the newly selected
 * profile.
 */
int AA_MPDSnCxx::stepProfileUp()
{
    return _stepProfile(true);
}

/**
 * @brief Decrement profile.
 * @return Current profile.
 *
 * The LineStatus struct is also updated with the values of the newly selected
 * profile.
 */
int AA_MPDSnCxx::stepProfileDown()
{
    return _stepProfile(true);
}

void AA_MPDSnCxx::setBlanking(bool enableOutput, bool enableExternal, bool store)
{
    QString s = QString("L0I%1O%2").arg((int)(!enableExternal)).arg((int)enableOutput);
    if (store) {
        s += "E";
    }
    QString r = serialPort->transceive(s, "\n\r");
    QRegularExpression rx("^BS([0,1])I([0,1])\n\r$");
    QRegularExpressionMatch match = rx.match(r);

    if (!match.hasMatch()) {
        throw std::runtime_error(("Cannot parse string: " + r).toStdString());
    }

    bool ok1, ok2;

    bool output = match.captured(1).toInt(&ok1);
    bool external = match.captured(2).toInt(&ok2);
    external = !external;

    if (!(output == enableOutput && external == enableExternal && ok1 && ok2)) {
        throw std::runtime_error(("Cannot parse string: " + r).toStdString());
    }

    blankingEnabled = output;
    blankingExternal = external;
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

void AA_MPDSnCxx::parseLResponse(const QString &s)
{
    QRegularExpression rx("^l(\\d)F([0-9.]+)P(-?[0-9.]+)S([0,1])\n\r$");
    QRegularExpressionMatch match = rx.match(s);

    auto errMsg = QString("Invalid response: " + s).toStdString();
    if (!match.hasMatch()) {
        throw std::runtime_error(errMsg);
    }

    bool ok;
    int c = 1;

    int i = match.captured(c++).toUInt(&ok);

    double d;

    LineStatus *st = status.at(i);

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
}

void AA_MPDSnCxx::parseHelp()
{
    QString s = serialPort->transceive(".", "\n\n\r> ");
    QRegularExpression rx("VMode: ([510]+)V");
    QRegularExpressionMatch match = rx.match(s);

    auto errMsg = QString("Invalid response: " + s).toStdString();
    if (!match.hasMatch()) {
        throw std::runtime_error(errMsg);
    }

    bool ok;

    int i = match.captured(1).toUInt(&ok);
    if (!ok) {
        throw std::runtime_error(errMsg);
    }
    if (i == 5) {
        VMode10V = false;
    } else if (i == 10) {
        VMode10V = true;
    } else {
        throw std::runtime_error(errMsg);
    }

    rx.setPattern("Selected profile: ([0-9]+)");
    match = rx.match(s);
    if (!match.hasMatch()) {
        throw std::runtime_error(errMsg);
    }
    i = match.captured(1).toUInt(&ok);
    if (!ok) {
        throw std::runtime_error(errMsg);
    }
    selectedProfile = i;
}
