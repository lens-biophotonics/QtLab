#include <stdexcept>

#include <QRegularExpression>

#include <qtlab/hw/serial/cobolt.h>
#include <qtlab/hw/serial/serialport.h>


Cobolt::Cobolt(QObject *parent) : SerialDevice(parent)
{
    serialPort->setLineEndTermination("\r\n", "\r\n");
}

void Cobolt::postConnect_impl()
{
    for (int i = 0; i < 10; ++i) {
        try {
            ping();
            getSerialNumber();
            break;
        }
        catch (std::runtime_error) {
            continue;
        }
    }
}

QString Cobolt::getSerialNumber()
{
    return transceiveChkSyntaxError("sn?");
}

QString Cobolt::getLaserModel()
{
    return transceiveChkSyntaxError("glm?");
}

QString Cobolt::getFullName()
{
    return transceiveChkSyntaxError("gcn?");
}

int Cobolt::getWavelength()
{
    QRegularExpression re("(\\d+)nm");
    QRegularExpressionMatch match = re.match(getFullName());
    if (match.hasMatch()) {
        return match.captured(1).toInt();
    }

    QStringList sl = getLaserModel().split("-");
    if (sl.size() > 0) {
        bool ok = false;
        int wl = sl.at(0).toInt(&ok);
        if (ok) {
            return wl;
        }
    }

    return -1;
}

/**
 * @brief Get output power set point.
 * @return Output power in W.
 */

double Cobolt::getOutputPower()
{
    return serialPort->getDouble("pa?");
}

double Cobolt::getOutputPowerSetPoint()
{
    return serialPort->getDouble("p?");
}

/**
 * @brief Get drive current.
 * @return Drive current in mA.
 */

double Cobolt::getDriveCurrent()
{
    return serialPort->getDouble("i?");
}

double Cobolt::getHours()
{
    return serialPort->getDouble("hrs?");
}

double Cobolt::getModulationHighCurrent()
{
    return serialPort->getDouble("gmc?");
}

double Cobolt::getModulationLowCurrent()
{
    return serialPort->getDouble("glth?");
}

double Cobolt::getTECLDSetTemperature()
{
    return serialPort->getDouble("gtec4t?");
}

double Cobolt::readTECLDTemperature()
{
    return serialPort->getDouble("rtec4t?");
}

Cobolt::OPERATING_FAULT Cobolt::getOperatingFault()
{
    return static_cast<OPERATING_FAULT>(serialPort->getInt("f?"));
}

bool Cobolt::isInterlockOpen()
{
    return serialPort->getInt("ilk?");
}

bool Cobolt::isAnalogModulationEnabled()
{
    return serialPort->getInt("games?");
}

bool Cobolt::isDigitalModulationEnabled()
{
    return serialPort->getInt("gdmes?");
}

bool Cobolt::isAnalogLowImpedanceEnabled()
{
    return serialPort->getInt("galis?");
}

Cobolt::ON_OFF_STATE Cobolt::getOnOffState()
{
    int state = serialPort->getInt("l?");
    return static_cast<ON_OFF_STATE>(state);
}

Cobolt::OPERATING_MODE Cobolt::getOperatingMode()
{
    int mode = serialPort->getInt("gom?");
    return static_cast<OPERATING_MODE>(mode);
}

void Cobolt::setOutputPower(double W)
{
    transceiveChkOK(QString("p %1").arg(W));
}

void Cobolt::setDriveCurrent(double mA)
{
    transceiveChkOK(QString("slc %1").arg(mA));
}

void Cobolt::setModulationHighCurrent(double mA)
{
    transceiveChkOK(QString("smc %1").arg(mA));
}

void Cobolt::setModulationLowCurrent(double mA)
{
    transceiveChkOK(QString("slth %1").arg(mA));
}

void Cobolt::setTECLDTemperature(double celsius)
{
    transceiveChkOK(QString("stec4t %1").arg(celsius));
}

void Cobolt::setDigitalModulationEnabled(bool enable)
{
    transceiveChkOK(QString("sdmes %1").arg(enable ? 1 : 0));
}

void Cobolt::setAnalogModulationEnabled(bool enable)
{
    transceiveChkOK(QString("sames %1").arg(enable ? 1 : 0));
}

void Cobolt::setAnalogLowImpedanceEnabled(bool enable)
{
    transceiveChkOK(QString("salis %1").arg(enable ? 1 : 0));
}

void Cobolt::restart()
{
    transceiveChkOK("@cob1");
}

void Cobolt::setLaserOn()
{
    transceiveChkOK("l1");
}

void Cobolt::setLaserOff()
{
    transceiveChkOK("l0");
}

void Cobolt::enterConstantPowerMode()
{
    transceiveChkOK("cp");
}

void Cobolt::enterConstantCurrentMode()
{
    transceiveChkOK("ci");
}

void Cobolt::enterModulationMode()
{
    transceiveChkOK("em");
}

void Cobolt::clearFault()
{
    transceiveChkOK("cf");
}

void Cobolt::ping()
{
    transceiveChkOK("?");
}

QString Cobolt::getVerboseName() const
{
    return verboseName;
}

void Cobolt::setVerboseName(const QString &value)
{
    verboseName = value;
}

QString Cobolt::transceiveChkOK(QString cmd)
{
    QString response = serialPort->transceive(cmd);
    if (response != "OK") {
        throw std::runtime_error(response.toLatin1());
    }
    return response;
}

QString Cobolt::transceiveChkSyntaxError(QString cmd)
{
    QString response = serialPort->transceive(cmd);
    if (response.startsWith("Syntax error")) {
        throw std::runtime_error(response.toLatin1());
    }
    return response;
}
