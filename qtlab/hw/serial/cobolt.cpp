#include <stdexcept>

#include <QRegularExpression>

#include <qtlab/hw/serial/cobolt.h>
#include <qtlab/hw/serial/serialport.h>


Cobolt::Cobolt(QObject *parent) : SerialDevice(parent)
{
    serial->setLineEndTermination("\r\n", "\r\n");

    QState *cs = serial->getConnectedState();
    QState *classUninitialized = new QState(cs);
    classInitializedState = new QState(cs);

    classUninitialized->addTransition(this, &Cobolt::connected, classInitializedState);
    classInitializedState->addTransition(this, &Cobolt::disconnected, classUninitialized);
    cs->setInitialState(classUninitialized);

    laserOnState = new QState(classInitializedState);
    laserOffState = new QState(classInitializedState);

    laserOnState->addTransition(this, &Cobolt::laserOff, laserOffState);
    laserOffState->addTransition(this, &Cobolt::laserOn, laserOnState);
}

void Cobolt::postConnect_impl()
{
    for (int i = 0; i < 10; ++i) {
        try {
            init();
            break;
        }
        catch (std::runtime_error) {
            continue;
        }
    }
}

void Cobolt::init()
{
    ping();

    QString sn, fv;

    fv = getFirmwareVersion();
    sn = getSerialNumber();

    if (fv.contains('.')) {
        modelNumber = transceiveChkSyntaxError("glm?");
    } else if (sn.contains('0')) {
        modelNumber = QString("0%1-04-XX-XXXX-XXX").arg(sn.section('0', 0, 0));
    }
    _setCoboltClass();
    classInitializedState->setInitialState(isLaserOn() ? laserOnState : laserOffState);
}

void Cobolt::_setCoboltClass()
{
    coboltClass = COBOLT_LASER;
    if (modelNumber.contains("-71-")) {
        return;
    }
    if (!modelNumber.contains("-06-")) {
        return;
    }
    QString mod = modelNumber.left(4);
    if (mod.contains("-91-") || mod.contains("-93-")) {
        coboltClass = COBOLT_06DPL;
    } else {
        coboltClass = COBOLT_06MLD;
    }
}

QString Cobolt::getModelNumber() const
{
    return modelNumber;
}

QState *Cobolt::getLaserOffState() const
{
    return laserOffState;
}

QState *Cobolt::getLaserOnState() const
{
    return laserOnState;
}

QString Cobolt::getSerialNumber()
{
    return transceiveChkSyntaxError("sn?");
}

QString Cobolt::getFirmwareVersion()
{
    return transceiveChkSyntaxError("gfv?");
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

    bool ok;
    int wl;

    QStringList sl = modelNumber.split("-");
    if (sl.size() > 0) {
        ok = false;
        wl = sl.at(0).toInt(&ok);
        if (ok) {
            return wl;
        }
    }

    ok = false;
    wl = modelNumber.left(4).toUInt(&ok);
    if (ok) {
        return wl;
    }

    return -1;
}

double Cobolt::getOutputPower()
{
    return serial->getDouble("pa?");
}

/**
 * @brief Get output power set point.
 * @return Output power in W.
 */

double Cobolt::getOutputPowerSetPoint()
{
    return serial->getDouble("p?");
}

/**
 * @brief Get drive current.
 * @return Drive current in mA.
 */

double Cobolt::getDriveCurrent()
{
    return serial->getDouble("i?");
}

double Cobolt::getHours()
{
    return serial->getDouble("hrs?");
}

double Cobolt::getModulationHighCurrent()
{
    return serial->getDouble("gmc?");
}

double Cobolt::getModulationLowCurrent()
{
    return serial->getDouble("glth?");
}

double Cobolt::getTECLDSetTemperature()
{
    return serial->getDouble("gtec4t?");
}

double Cobolt::readTECLDTemperature()
{
    return serial->getDouble("rtec4t?");
}

Cobolt::OPERATING_FAULT Cobolt::getOperatingFault()
{
    return static_cast<OPERATING_FAULT>(serial->getInt("f?"));
}

bool Cobolt::isInterlockOpen()
{
    return serial->getInt("ilk?");
}

bool Cobolt::isAnalogModulationEnabled()
{
    return serial->getInt("games?");
}

bool Cobolt::isDigitalModulationEnabled()
{
    return serial->getInt("gdmes?");
}

bool Cobolt::isAnalogLowImpedanceEnabled()
{
    return serial->getInt("galis?");
}

bool Cobolt::isLaserOn()
{
    int state = serial->getInt("l?");
    switch (state) {
    case STATE_ON:
        emit laserOn();
        return true;
    case STATE_OFF:
        emit laserOff();
        return false;
    }
    return false;
}

Cobolt::OPERATING_MODE Cobolt::getOperatingMode()
{
    int mode = serial->getInt("gom?");
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
    emit laserOn();
}

void Cobolt::setLaserOff()
{
    transceiveChkOK("l0");
    emit laserOff();
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
    QString response = serial->transceive(cmd);
    if (response != "OK") {
        throw std::runtime_error(response.toLatin1());
    }
    return response;
}

QString Cobolt::transceiveChkSyntaxError(QString cmd)
{
    QString response = serial->transceive(cmd);
    if (response.startsWith("Syntax error")) {
        throw std::runtime_error(response.toLatin1());
    }
    return response;
}
