/***************************************************************************
**                                                                        **
**  This file is part of QtLab-Thorlabs-MC                                **
**  Copyright (C) 2022 giacomo.mazzamuto@cnr.it                           **
**  Copyright (C) 2016-2019 wido.tomas@gmail.com https://github.com/tWido **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************/


#include <sys/signalfd.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>

#include <qtlab/core/logger.h>

Logger *logger = getLogger("MotorController");

#include "motorcontroller.h"

using namespace QtLab::hw::Thorlabs;

functions_set tdc_set{
    IDENTIFY,

    SET_CHANENABLESTATE,
    REQ_CHANENABLESTATE,
    GET_CHANENABLESTATE,

    HW_DISCONNECT,
    HW_RESPONSE,
    RICHRESPONSE,

    HW_START_UPDATEMSGS,
    HW_STOP_UPDATEMSGS,
    HW_REQ_INFO,
    HW_GET_INFO,

    HUB_REQ_BAYUSED,
    HUB_GET_BAYUSED,

    SET_POSCOUNTER,
    REQ_POSCOUNTER,
    GET_POSCOUNTER,

    SET_ENCCOUNTER,
    REQ_ENCCOUNTER,
    GET_ENCCOUNTER,

    SET_VELPARAMS,
    REQ_VELPARAMS,
    GET_VELPARAMS,

    SET_JOGPARAMS,
    REQ_JOGPARAMS,
    GET_JOGPARAMS,

    SET_GENMOVEPARAMS,
    REQ_GENMOVEPARAMS,
    GET_GENMOVEPARAMS,

    SET_MOVERELPARAMS,
    REQ_MOVERELPARAMS,
    GET_MOVERELPARAMS,

    SET_MOVEABSPARAMS,
    REQ_MOVEABSPARAMS,
    GET_MOVEABSPARAMS,

    SET_HOMEPARAMS,
    REQ_HOMEPARAMS,
    GET_HOMEPARAMS,

    SET_LIMSWITCHPARAMS,
    REQ_LIMSWITCHPARAMS,
    GET_LIMSWITCHPARAMS,

    MOVE_HOME,
    MOVE_HOMED,

    MOVE_RELATIVE,
    MOVE_COMPLETED,
    MOVE_ABSOLUTE,
    MOVE_JOG,
    MOVE_VELOCITY,
    MOVE_STOP,
    MOVE_STOPPED,

    SET_AVMODES,
    REQ_AVMODES,
    GET_AVMODES,

    SET_BUTTONPARAMS,
    REQ_BUTTONPARAMS,
    GET_BUTTONPARAMS,

    GET_DCSTATUSUPDATE,
    REQ_DCSTATUSUPDATE,
    ACK_DCSTATUSUPDATE,

    REQ_STATUSBITS,
    GET_STATUSBITS,

    SUSPEND_ENDOFMOVEMSGS,
    RESUME_ENDOFMOVEMSGS,
};

functions_set tst_set{
    IDENTIFY,

    SET_CHANENABLESTATE,
    REQ_CHANENABLESTATE,
    GET_CHANENABLESTATE,

    HW_START_UPDATEMSGS,
    HW_STOP_UPDATEMSGS,

    HW_REQ_INFO,
    HW_GET_INFO,

    SET_POSCOUNTER,
    REQ_POSCOUNTER,
    GET_POSCOUNTER,

    SET_ENCCOUNTER,
    REQ_ENCCOUNTER,
    GET_ENCCOUNTER,

    SET_VELPARAMS,
    REQ_VELPARAMS,
    GET_VELPARAMS,

    SET_JOGPARAMS,
    REQ_JOGPARAMS,
    GET_JOGPARAMS,

    SET_POWERPARAMS,
    REQ_POWERPARAMS,
    GET_POWERPARAMS,

    SET_GENMOVEPARAMS,
    REQ_GENMOVEPARAMS,
    GET_GENMOVEPARAMS,

    SET_MOVERELPARAMS,
    REQ_MOVERELPARAMS,
    GET_MOVERELPARAMS,

    SET_MOVEABSPARAMS,
    REQ_MOVEABSPARAMS,
    GET_MOVEABSPARAMS,

    SET_HOMEPARAMS,
    REQ_HOMEPARAMS,
    GET_HOMEPARAMS,

    SET_LIMSWITCHPARAMS,
    REQ_LIMSWITCHPARAMS,
    GET_LIMSWITCHPARAMS,

    MOVE_HOME,
    MOVE_HOMED,

    MOVE_RELATIVE,
    MOVE_COMPLETED,
    MOVE_ABSOLUTE,
    MOVE_JOG,
    MOVE_VELOCITY,
    MOVE_STOP,
    MOVE_STOPPED,

    SET_AVMODES,
    REQ_AVMODES,
    GET_AVMODES,

    SET_BUTTONPARAMS,
    REQ_BUTTONPARAMS,
    GET_BUTTONPARAMS,

    REQ_STATUSBITS,
    GET_STATUSBITS,
};

functions_set bsc_set{
    IDENTIFY,

    SET_CHANENABLESTATE,
    REQ_CHANENABLESTATE,
    GET_CHANENABLESTATE,

    HW_DISCONNECT,
    HW_RESPONSE,
    RICHRESPONSE,

    HW_START_UPDATEMSGS,
    HW_STOP_UPDATEMSGS,
    HW_REQ_INFO,
    HW_GET_INFO,

    RACK_REQ_BAYUSED,
    RACK_GET_BAYUSED,

    SET_POSCOUNTER,
    REQ_POSCOUNTER,
    GET_POSCOUNTER,

    SET_ENCCOUNTER,
    REQ_ENCCOUNTER,
    GET_ENCCOUNTER,

    SET_VELPARAMS,
    REQ_VELPARAMS,
    GET_VELPARAMS,

    SET_JOGPARAMS,
    REQ_JOGPARAMS,
    GET_JOGPARAMS,

    SET_POWERPARAMS,
    REQ_POWERPARAMS,
    GET_POWERPARAMS,

    SET_GENMOVEPARAMS,
    REQ_GENMOVEPARAMS,
    GET_GENMOVEPARAMS,

    SET_MOVERELPARAMS,
    REQ_MOVERELPARAMS,
    GET_MOVERELPARAMS,

    SET_MOVEABSPARAMS,
    REQ_MOVEABSPARAMS,
    GET_MOVEABSPARAMS,

    SET_HOMEPARAMS,
    REQ_HOMEPARAMS,
    GET_HOMEPARAMS,

    SET_LIMSWITCHPARAMS,
    REQ_LIMSWITCHPARAMS,
    GET_LIMSWITCHPARAMS,

    MOVE_HOME,
    MOVE_HOMED,

    MOVE_RELATIVE,
    MOVE_COMPLETED,
    MOVE_ABSOLUTE,
    MOVE_JOG,
    MOVE_VELOCITY,
    MOVE_STOP,
    MOVE_STOPPED,

    GET_STATUSUPDATE,
    REQ_STATUSUPDATE,

    REQ_STATUSBITS,
    GET_STATUSBITS,

    SET_TRIGGER,
    REQ_TRIGGER,
    GET_TRIGGER
};

functions_set bbd_set{
    IDENTIFY,

    SET_CHANENABLESTATE,
    REQ_CHANENABLESTATE,
    GET_CHANENABLESTATE,

    HW_DISCONNECT,
    HW_RESPONSE,
    RICHRESPONSE,

    HW_START_UPDATEMSGS,
    HW_STOP_UPDATEMSGS,
    HW_REQ_INFO,
    HW_GET_INFO,

    RACK_REQ_BAYUSED,
    RACK_GET_BAYUSED,

    SET_POSCOUNTER,
    REQ_POSCOUNTER,
    GET_POSCOUNTER,

    SET_ENCCOUNTER,
    REQ_ENCCOUNTER,
    GET_ENCCOUNTER,

    SET_VELPARAMS,
    REQ_VELPARAMS,
    GET_VELPARAMS,

    SET_JOGPARAMS,
    REQ_JOGPARAMS,
    GET_JOGPARAMS,

    SET_GENMOVEPARAMS,
    REQ_GENMOVEPARAMS,
    GET_GENMOVEPARAMS,

    SET_MOVERELPARAMS,
    REQ_MOVERELPARAMS,
    GET_MOVERELPARAMS,

    SET_MOVEABSPARAMS,
    REQ_MOVEABSPARAMS,
    GET_MOVEABSPARAMS,

    SET_HOMEPARAMS,
    REQ_HOMEPARAMS,
    GET_HOMEPARAMS,

    SET_LIMSWITCHPARAMS,
    REQ_LIMSWITCHPARAMS,
    GET_LIMSWITCHPARAMS,

    MOVE_HOME,
    MOVE_HOMED,

    MOVE_RELATIVE,
    MOVE_COMPLETED,
    MOVE_ABSOLUTE,
    MOVE_JOG,
    MOVE_VELOCITY,
    MOVE_STOP,
    MOVE_STOPPED,

    GET_DCSTATUSUPDATE,
    REQ_DCSTATUSUPDATE,
    ACK_DCSTATUSUPDATE,

    REQ_STATUSBITS,
    GET_STATUSBITS,

    SUSPEND_ENDOFMOVEMSGS,
    RESUME_ENDOFMOVEMSGS,

    SET_TRIGGER,
    REQ_TRIGGER,
    GET_TRIGGER
};

functions_set all_set{
    IDENTIFY,

    SET_CHANENABLESTATE,
    REQ_CHANENABLESTATE,
    GET_CHANENABLESTATE,

    HW_DISCONNECT,
    HW_RESPONSE,
    RICHRESPONSE,

    HW_START_UPDATEMSGS,
    HW_STOP_UPDATEMSGS,
    HW_REQ_INFO,
    HW_GET_INFO,

    RACK_REQ_BAYUSED,
    RACK_GET_BAYUSED,
    HUB_REQ_BAYUSED,
    HUB_GET_BAYUSED,

    HW_YES_FLASH_PROGRAMMING,
    HW_NO_FLASH_PROGRAMMING,

    SET_POSCOUNTER,
    REQ_POSCOUNTER,
    GET_POSCOUNTER,

    SET_ENCCOUNTER,
    REQ_ENCCOUNTER,
    GET_ENCCOUNTER,

    SET_VELPARAMS,
    REQ_VELPARAMS,
    GET_VELPARAMS,

    SET_JOGPARAMS,
    REQ_JOGPARAMS,
    GET_JOGPARAMS,

    SET_POWERPARAMS,
    REQ_POWERPARAMS,
    GET_POWERPARAMS,

    SET_GENMOVEPARAMS,
    REQ_GENMOVEPARAMS,
    GET_GENMOVEPARAMS,

    SET_MOVERELPARAMS,
    REQ_MOVERELPARAMS,
    GET_MOVERELPARAMS,

    SET_MOVEABSPARAMS,
    REQ_MOVEABSPARAMS,
    GET_MOVEABSPARAMS,

    SET_HOMEPARAMS,
    REQ_HOMEPARAMS,
    GET_HOMEPARAMS,

    SET_LIMSWITCHPARAMS,
    REQ_LIMSWITCHPARAMS,
    GET_LIMSWITCHPARAMS,

    MOVE_HOME,
    MOVE_HOMED,

    MOVE_RELATIVE,
    MOVE_COMPLETED,
    MOVE_ABSOLUTE,
    MOVE_JOG,
    MOVE_VELOCITY,
    MOVE_STOP,
    MOVE_STOPPED,

    SET_BOWINDEX,
    REQ_BOWINDEX,
    GET_BOWINDEX,

    SET_AVMODES,
    REQ_AVMODES,
    GET_AVMODES,

    SET_BUTTONPARAMS,
    REQ_BUTTONPARAMS,
    GET_BUTTONPARAMS,

    GET_STATUSUPDATE,
    REQ_STATUSUPDATE,

    GET_DCSTATUSUPDATE,
    REQ_DCSTATUSUPDATE,
    ACK_DCSTATUSUPDATE,

    REQ_STATUSBITS,
    GET_STATUSBITS,

    SUSPEND_ENDOFMOVEMSGS,
    RESUME_ENDOFMOVEMSGS,

    SET_TRIGGER,
    REQ_TRIGGER,
    GET_TRIGGER
};

MotorController::MotorController(QObject *parent) : SerialDevice(parent)
{
    serial->setBaudRate(SerialPort::Baud115200);
}


//----------------- Device communication functions ---------------------------------

#define RUNTIME_ERROR {QString err = QString("Runtime error (%3) at %1:%2").arg(__FILE__).arg(__LINE__).arg(ret); throw std::runtime_error(err.toStdString());}
#define RUNTIME_ERROR_INVALID_PARAM(x) throw std::runtime_error("Invalid param "#x);

#define EMPTY_IN_QUEUE ret = emptyIncomingQueue();    \
    if (ret != 0) RUNTIME_ERROR

#define CHECK_ADDR_PARAMS(dest, chanID) int ret;        \
    ret = checkParams(dest, chanID);                  \
    if (ret != 0) RUNTIME_ERROR

#define GET_MESS(req_mess_class, buff_size, get_mess_code, get_mess_class) \
    CHECK_ADDR_PARAMS(dest, channel)                        \
    EMPTY_IN_QUEUE                                          \
    req_mess_class mes(dest, SOURCE, channel);              \
    sendMessage(mes);                                       \
    uint8_t *buff = (uint8_t *) malloc(buff_size);          \
    ret = getResponseMess(get_mess_code, buff_size, buff);  \
    message.SetData(buff);                                  \
    free(buff);                                             \
    if (ret != 0) RUNTIME_ERROR;                            \
    EMPTY_IN_QUEUE


void MotorController::sendMessage(Message &message)
{
    QByteArray ba((char *)message.data(), message.msize());
    serial->sendMsg(ba);
}

int MotorController::checkParams(uint8_t dest, int chanID)
{
    if (chanID > opened_device.channels && chanID != -1) return INVALID_CHANNEL;
    if (dest == 0x11 || dest == 0x50) return 0;
    switch (dest) {
    case 0x21: {
        if (opened_device.bays >= 1 && opened_device.bay_used[0]) return 0;
        else return INVALID_DEST;
    }
    case 0x22: {
        if (opened_device.bays >= 2 && opened_device.bay_used[1]) return 0;
        else return INVALID_DEST;
    }
    case 0x23: {
        if (opened_device.bays == 3 && opened_device.bay_used[2]) return 0;
        else return INVALID_DEST;
    }
    default: return INVALID_DEST;
    };
    return 0;
};

int MotorController::checkIncomingQueue(uint16_t &ret_msgID)
{
    serial->waitForReadyRead(serial->getTimeout());
    unsigned int bytes = serial->bytesAvailable();
    if (bytes == 0) return EMPTY;
    uint8_t buff[MAX_RESPONSE_SIZE];
    if (serial->read((char*)buff, 2) != 2) {
        throw std::runtime_error("Cannot read from serial");
    };

    uint16_t msgID = le16toh(*((uint16_t*) &buff[0]));
    switch (msgID) {
    case HW_DISCONNECT: {
        serial->read((char*)buff, 4);
        HwDisconnect response(buff);
        logger->info(QString("Device with serial %1 disconnecting").arg(opened_device.SN));
        return FATAL_ERROR;
    }
    case HW_RESPONSE: {
        serial->read((char*)buff, 4);
        HwResponse response(buff);
        logger->critical(QString("Device with serial %1 encountered error").arg(opened_device.SN));
        return DEVICE_ERROR;
    }
    case RICHRESPONSE: {
        serial->read((char*)buff, 72);
        HwResponseInfo response(buff);
        logger->critical(QString("Device with serial %1 encountered error").arg(opened_device.SN));
        logger->critical("Detailed description of error");
        uint16_t error_cause = response.GetMsgID();
        if (error_cause != 0) logger->critical(QString("\tMessage causing error: %1").arg(error_cause));
        logger->critical(QString("\tThorlabs error code: %1").arg(response.GetCode()));
        logger->critical(QString("\t\tDescription: %1").arg(response.GetDescription()));
        return DEVICE_ERROR;
    }
    case MOVE_HOMED: {
        serial->read((char*)buff, 4);
        MovedHome response(buff);
        assert (response.GetMotorID() < 3);
        opened_device.motor[response.GetMotorID()].homing = false;
        return MOVED_HOME_STATUS;
    }
    case MOVE_COMPLETED: {
        serial->read((char*)buff, 18);     // 14 bytes for status updates
        MoveCompleted response(buff);
        assert (response.GetMotorID() < 3);
        opened_device.motor[response.GetMotorID()].homing = false;
        return MOVE_COMPLETED_STATUS;
    }
    case MOVE_STOPPED: {
        serial->read((char*)buff, 18);    // 14 bytes for status updates
        MoveStopped response(buff);
        assert (response.GetMotorID() < 3);
        opened_device.motor[response.GetMotorID()].homing = false;
        return MOVE_STOPPED_STATUS;
    }
    case GET_STATUSUPDATE: {
        serial->read((char*)buff, 18);
        GetStatusUpdate response(buff);
        assert (response.GetMotorID() < 3);
        opened_device.motor[response.GetMotorID()].status_enc_count = response.GetEncCount();
        opened_device.motor[response.GetMotorID()].status_position = response.GetPosition();
        opened_device.motor[response.GetMotorID()].status_status_bits = response.GetStatusBits();
        return 0;
    }
    case GET_DCSTATUSUPDATE: {
        serial->read((char*)buff, 18);
        GetMotChanStatusUpdate response(buff);
        assert (response.GetMotorID() < 3);
        opened_device.motor[response.GetMotorID()].status_velocity = response.GetVelocity();
        opened_device.motor[response.GetMotorID()].status_position = response.GetPosition();
        opened_device.motor[response.GetMotorID()].status_status_bits = response.GetStatusBits();
        return 0;
    }
    default: {
        ret_msgID = msgID;
        return OTHER_MESSAGE;
    }
    };
}

int MotorController::emptyIncomingQueue()
{
    while (true) {
        uint16_t messID = 0;
        int ret = checkIncomingQueue(messID);
        if (ret == EMPTY) return 0;
        if (ret == MOVED_HOME_STATUS || ret == MOVE_COMPLETED_STATUS || ret == MOVE_STOPPED_STATUS || ret == 0) continue;
        switch (ret) {
        case FATAL_ERROR: return FATAL_ERROR;
        case FT_ERROR: return FT_ERROR;
        case DEVICE_ERROR: return DEVICE_ERROR;
        case OTHER_MESSAGE: {
            throw std::runtime_error("Protocol error");
            return FATAL_ERROR;
        }
        }
    }
}

int MotorController::getResponseMess(uint16_t expected_msg, int size, uint8_t *mess)
{
    int ret;
    uint16_t msgID;
    while (true) {
        ret = checkIncomingQueue(msgID);
        if (ret == OTHER_MESSAGE) {
            if (msgID == expected_msg) {
                *((int16_t *) &mess[0]) =  htole16(msgID);
                QByteArray ba = serial->readNBytes(size - 2);
                memcpy(&mess[2], ba.data(), ba.size());
                return 0;
            }
            else return FATAL_ERROR;
        }
        if (ret == MOVED_HOME_STATUS || ret == MOVE_COMPLETED_STATUS || ret == MOVE_STOPPED_STATUS || ret == 0) continue;
        switch (ret) {
        case FATAL_ERROR: return FATAL_ERROR;
        case FT_ERROR: return FT_ERROR;
        case DEVICE_ERROR: return DEVICE_ERROR;
        }
    }
    return 0;
}


void MotorController::identify(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    IdentifyMs mes(dest, 0x01);
    sendMessage(mes);
    EMPTY_IN_QUEUE
}

void MotorController::enableChannel(uint8_t dest, uint8_t chanel)
{
    CHECK_ADDR_PARAMS(dest, chanel)
    EMPTY_IN_QUEUE
    SetChannelState mes(chanel, 1, dest, SOURCE);
    sendMessage(mes);
    EMPTY_IN_QUEUE
}

void MotorController::disableChannel(uint8_t dest, uint8_t chanel)
{
    CHECK_ADDR_PARAMS(dest, chanel)
    EMPTY_IN_QUEUE
    SetChannelState mes(chanel, 2, dest, SOURCE);
    sendMessage(mes);
    EMPTY_IN_QUEUE
}

ChannelState MotorController::getChannelState(uint8_t dest, uint8_t chanel)
{
    CHECK_ADDR_PARAMS(dest, chanel)
    EMPTY_IN_QUEUE
    ReqChannelState mes(chanel, dest, SOURCE);
    sendMessage(mes);
    uint8_t *buff = (uint8_t *) malloc(HEADER_SIZE);
    ret = getResponseMess(GET_CHANENABLESTATE, HEADER_SIZE, buff);
    if (ret != 0) RUNTIME_ERROR;
    ChannelState info;
    info.SetData(buff);
    free(buff);
    EMPTY_IN_QUEUE
    return info;
}

void MotorController::disconnectHW(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    HwDisconnect mes(dest, SOURCE);
    sendMessage(mes);
    EMPTY_IN_QUEUE
}

void MotorController::startUpdateMess(uint8_t rate, uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    StartUpdateMessages mes(dest, SOURCE);
    mes.opened_device = &opened_device;
    if (mes.SetUpdaterate(rate) == IGNORED_PARAM) {
        logger->warning("This parameter is ignored in connected device. Using default.");
    }
    sendMessage(mes);
    opened_device.status_updates = true;
    EMPTY_IN_QUEUE
}

void MotorController::stopUpdateMess(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    StopUpdateMessages mes(dest, SOURCE);
    sendMessage(mes);
    opened_device.status_updates = false;
    EMPTY_IN_QUEUE
}

HwInfo MotorController::getHwInfo(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    ReqHwInfo mes(dest, SOURCE);
    sendMessage(mes);
    uint8_t *buff = (uint8_t *) malloc(90);
    ret = getResponseMess(HW_GET_INFO, 90, buff);
    if (ret != 0) RUNTIME_ERROR;
    HwInfo info;
    info.SetData(buff);
    free(buff);
    EMPTY_IN_QUEUE
    return info;
}

RackBayUsed MotorController::getBayUsed(uint8_t bayID, uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    ReqRackBayUsed mes(dest, SOURCE);
    mes.SetBayIdent(bayID);
    sendMessage(mes);
    uint8_t *buff = (uint8_t *) malloc(HEADER_SIZE);
    ret = getResponseMess(RACK_GET_BAYUSED, HEADER_SIZE, buff);
    RackBayUsed message;
    if (ret != 0) RUNTIME_ERROR;
    message.SetData(buff);
    free(buff);
    EMPTY_IN_QUEUE
    return message;
}

void MotorController::flashProgYes(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    YesFlashProg mes(dest, SOURCE);
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

void MotorController::flashProgNo(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    NoFlashProg mes(dest, SOURCE);
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

int MotorController::setPositionCounter(int32_t pos, uint8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetPosCounter mes(dest, SOURCE, channel);
    mes.SetPosition(pos);
    sendMessage(mes);
    EMPTY_IN_QUEUE
    return ret; //return WARNING
};

int32_t MotorController::getPositionCounter(uint8_t dest, uint8_t channel)
{
    GetPosCounter message;
    GET_MESS(ReqPosCounter, 12, GET_POSCOUNTER, GetPosCounter)
    return message.GetPosition();
};

int MotorController::setEncoderCounter(int32_t count, uint8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetEncCount mes(dest, SOURCE, channel);
    mes.SetEncoderCount(count);
    sendMessage(mes);
    EMPTY_IN_QUEUE
    return ret; //return WARNING
};

int32_t MotorController::getEncoderCounter(uint8_t dest, uint8_t channel)
{
    GetEncCount message;
    GET_MESS(ReqEncCount, 12, GET_ENCCOUNTER, GetEncCount)
    return message.GetEncCounter();
};

void MotorController::setVelocityP(int32_t acc, int32_t maxVel, uint8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetVelocityParams mes(dest, SOURCE, channel);
    mes.opened_device = &opened_device;
    if (mes.SetAcceleration(acc) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(1);
    if (mes.SetMaxVel(maxVel) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(2);
    EMPTY_IN_QUEUE
};

VelocityParams MotorController::getVelocityP(uint8_t dest, uint8_t channel)
{
    VelocityParams message;
    GET_MESS(ReqVelocityParams, 20, GET_VELPARAMS, VelocityParams)
    return message;
};

void MotorController::setJogP(uint16_t mode, int32_t stepSize, int32_t vel, int32_t acc, uint16_t stopMode, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetJogParams mes(dest, SOURCE, channel);
    mes.opened_device = &opened_device;
    if (mes.SetJogMode(mode) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(1);
    mes.SetStepSize(stepSize);
    if (mes.SetMaxVelocity(vel) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(3);
    if (mes.SetAcceleration(acc) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(4);
    if (mes.SetStopMode(stopMode) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(5);
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

JogParams MotorController::getJogP(uint8_t dest, uint8_t channel)
{
    JogParams message;
    GET_MESS(ReqJogParams, 28, GET_JOGPARAMS, JogParams)
    return message;
};

void MotorController::setPowerUsed(uint16_t rest_power, uint16_t move_power, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetPowerParams mes(dest, SOURCE, channel);
    if (mes.SetRestFactor(rest_power) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(1);
    if (mes.SetMoveFactor(move_power) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(2);
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

PowerParams MotorController::getPowerUsed(uint8_t dest, uint8_t channel)
{
    PowerParams message;
    GET_MESS(ReqPowerParams, 12, GET_POWERPARAMS, PowerParams)
    return message;
};

void MotorController::setBacklashDist(uint32_t dist, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetGeneralMoveParams mes(dest, SOURCE, channel);
    mes.SetBacklashDist(dist);
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

int32_t MotorController::getBacklashDist(uint8_t dest, uint8_t channel)
{
    GeneralMoveParams message;
    GET_MESS(ReqGeneralMoveParams, 12, GET_GENMOVEPARAMS, GeneralMoveParams)
    return message.GetBacklashDist();
};

void MotorController::setRelativeMoveP(uint32_t dist, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetRelativeMoveParams mes(dest, SOURCE, channel);
    mes.SetRelativeDist(dist);
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

int32_t MotorController::getRelativeMoveP(uint8_t dest, uint8_t channel)
{
    RelativeMoveParams message;
    GET_MESS(ReqRelativeMoveParams, 12, GET_MOVERELPARAMS, RelativeMoveParams)
    return message.GetRelativeDist();
};

void MotorController::setAbsoluteMoveP(uint32_t pos, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetAbsoluteMoveParams mes(dest, SOURCE, channel);
    mes.opened_device = &opened_device;
    mes.SetAbsolutePos(pos);
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

int32_t MotorController::getAbsoluteMoveP(uint8_t dest, uint8_t channel)
{
    AbsoluteMoveParams message;
    GET_MESS(ReqAbsoluteMoveParams, 12, GET_MOVEABSPARAMS, AbsoluteMoveParams)
    return message.GetAbsolutePos();
};

void MotorController::setHomingVel(uint32_t vel, int8_t dest,  uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetHomeParams mes(dest, SOURCE, channel);
    mes.opened_device = &opened_device;
    if (mes.SetHomingVelocity(vel) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(1);
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

int32_t MotorController::getHomingVel(uint8_t dest, uint8_t channel)
{
    HomeParams message;
    GET_MESS(ReqHomeParams, 20, GET_HOMEPARAMS, HomeParams)
    return message.GetHomingVelocity();
};

void MotorController::setLimitSwitchConfig(uint16_t CwHwLim, uint16_t CCwHwLim, uint16_t CwSwLim, uint16_t CCwSwLim, uint16_t mode, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetLimitSwitchParams mes(dest, SOURCE, channel);
    mes.opened_device = &opened_device;
    if (mes.SetClockwiseHardLimit(CwHwLim) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(1);
    if (mes.SetCounterlockwiseHardLimit(CCwHwLim) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(2);
    if (mes.SetClockwiseSoftLimit(CwSwLim) == IGNORED_PARAM) logger->warning("Software limit ignored in this device");
    if (mes.SetCounterlockwiseSoftLimit(CCwSwLim) == IGNORED_PARAM) logger->warning("Software limit ignored in this device");
    ret = mes.SetLimitMode(mode);
    if (ret == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(5);
    if (ret == IGNORED_PARAM) logger->warning("Limit mode ignored in this device");
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

void MotorController::getLimitSwitchConfig(uint8_t dest, uint8_t channel)
{
    LimitSwitchParams message;
    GET_MESS(ReqLimitSwitchParams, 22, GET_LIMSWITCHPARAMS, LimitSwitchParams)
};

void MotorController::moveToHome(uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    MoveHome mes(dest, SOURCE, channel);
    sendMessage(mes);
    opened_device.motor[mes.GetMotorID()].homing = true;
    EMPTY_IN_QUEUE
};

void MotorController::startSetRelativeMove(uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    MoveRelative1 mes(dest, SOURCE, channel);
    sendMessage(mes);
    opened_device.motor[mes.GetMotorID()].moving = true;
    EMPTY_IN_QUEUE
};

void MotorController::startRelativeMove(int32_t dist, uint8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    MoveRelative2 mes(dest, SOURCE, channel);
    mes.SetRelativeDistance(dist);
    sendMessage(mes);
    opened_device.motor[mes.GetMotorID()].moving = true;
    EMPTY_IN_QUEUE
};

void MotorController::startSetAbsoluteMove(uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    MoveAbsolute1 mes(dest, SOURCE, channel);
    mes.opened_device = &opened_device;
    sendMessage(mes);
    opened_device.motor[mes.GetMotorID()].moving = true;
    EMPTY_IN_QUEUE
};

void MotorController::startAbsoluteMove(int32_t pos, uint8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    MoveAbsolute2 mes(dest, SOURCE, channel);
    mes.opened_device = &opened_device;
    if (mes.SetAbsoluteDistance(pos) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(1);
    sendMessage(mes);
    opened_device.motor[mes.GetMotorID()].moving = true;
    EMPTY_IN_QUEUE
};

void MotorController::startJogMove(uint8_t direction, uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    JogMove mes(dest, SOURCE, channel);
    if (mes.SetDirection(direction) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(1);
    sendMessage(mes);
    opened_device.motor[mes.GetMotorID()].moving = true;
    EMPTY_IN_QUEUE
};

void MotorController::startSetVelocityMove(uint8_t direction, uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    MovewVelocity mes(dest, SOURCE, channel);
    if (mes.SetDirection(direction) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(1);
    sendMessage(mes);
    opened_device.motor[mes.GetMotorID()].moving = true;
    EMPTY_IN_QUEUE
}

void MotorController::stopMovement(uint8_t stopMode, uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    StopMove mes(dest, SOURCE, channel);
    if (mes.SetStopMode(stopMode) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(1);
    sendMessage(mes);
    opened_device.motor[mes.GetMotorID()].stopping = true;
    EMPTY_IN_QUEUE
}

void MotorController::setAccelerationProfile(uint16_t index, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetBowIndex mes(dest, SOURCE, channel);
    if (mes.SetBowindex(index) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(1);
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

uint16_t MotorController::getAccelerationProfile(uint8_t dest, uint8_t channel)
{
    BowIndex message;
    GET_MESS(ReqBowIndex, 10, GET_BOWINDEX, BowIndex)
    return message.GetBowIndex();
};

void MotorController::setLedP(uint16_t mode, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetLedMode mes(dest, SOURCE, channel);
    if (mes.SetMode(mode) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(1);
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

uint16_t MotorController::getLedP(uint8_t dest, uint8_t channel)
{
    LedMode message;
    GET_MESS(ReqLedMode, 10, GET_AVMODES, LedMode)
    return message.GetMode();
};

void MotorController::setButtons(uint16_t mode, int32_t pos1, int32_t pos2, uint16_t timeout, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetButtonParams mes(dest, SOURCE, channel);
    mes.opened_device = &opened_device;
    if (mes.SetMode(mode) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(1);
    if (mes.SetPosition1(pos1) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(2);
    if (mes.SetPosition2(pos2) == INVALID_PARAM) RUNTIME_ERROR_INVALID_PARAM(3);
    if (mes.SetTimeout(timeout) == IGNORED_PARAM) logger->warning("Timeout ignored in this device");
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

ButtonParams MotorController::getButtonsInfo(uint8_t dest, uint8_t channel)
{
    ButtonParams message;
    GET_MESS(ReqButtonParams, 22, GET_BUTTONPARAMS, ButtonParams)
    return message;
};

void MotorController::reqStatus(uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    ReqStatusUpdate mes(dest, SOURCE, channel);
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

void MotorController::reqDcStatus(uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    ReqMotChanStatusUpdate mes(dest, SOURCE, channel);
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

void MotorController::sendServerAlive(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    ServerAlive mes(dest, SOURCE);
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

uint32_t MotorController::getStatBits(uint8_t dest, uint8_t channel)
{
    StatusBits message;
    GET_MESS(ReqStatusBits, 12, GET_STATUSBITS, StatusBits)
    return message.GetStatBits();
};

void MotorController::disableEomMessages(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    DisableEndMoveMessages mes(dest, SOURCE);
    sendMessage(mes);
    opened_device.end_of_move_messages = false;
    EMPTY_IN_QUEUE
};

void MotorController::enableEomMessages(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    EnableEndMoveMessages mes(dest, SOURCE);
    sendMessage(mes);
    opened_device.end_of_move_messages = true;
    EMPTY_IN_QUEUE
};

void MotorController::createTrigger(uint8_t mode, uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetTrigger mes(dest, SOURCE, channel);
    mes.opened_device = &opened_device;
    if (mes.SetMode(mode) == IGNORED_PARAM) logger->warning("trigger ignored in this device");
    sendMessage(mes);
    EMPTY_IN_QUEUE
};

uint8_t MotorController::getMotorTrigger(uint8_t dest, uint8_t channel)
{
    GetTrigger message;
    GET_MESS(ReqTrigger, HEADER_SIZE, GET_TRIGGER, GetTrigger)
    return message.GetMode();
}

void MotorController::postConnect_impl()
{
    HwInfo info = getHwInfo();
    QMap<QString, dev_type> map;

#define APPEND_TO_MAP(code) map[#code] = code;

    APPEND_TO_MAP(BSC001);
    APPEND_TO_MAP(BSC002);
    APPEND_TO_MAP(BMS001);
    APPEND_TO_MAP(BMS002);
    APPEND_TO_MAP(MST601);
    APPEND_TO_MAP(MST602);
    APPEND_TO_MAP(BSC001);
    APPEND_TO_MAP(BSC002);
    APPEND_TO_MAP(BSC101);
    APPEND_TO_MAP(BSC102);
    APPEND_TO_MAP(BSC103);
    APPEND_TO_MAP(BSC201);
    APPEND_TO_MAP(BSC202);
    APPEND_TO_MAP(BSC203);
    APPEND_TO_MAP(BBD101);
    APPEND_TO_MAP(BBD102);
    APPEND_TO_MAP(BBD103);
    APPEND_TO_MAP(BBD201);
    APPEND_TO_MAP(BBD202);
    APPEND_TO_MAP(BBD203);
    APPEND_TO_MAP(KDC101);
    APPEND_TO_MAP(OST001);
    APPEND_TO_MAP(ODC001);
    APPEND_TO_MAP(TST001);
    APPEND_TO_MAP(TDC001);
    APPEND_TO_MAP(TBD001);

    dev_type dt = map[QString::fromStdString(info.ModelNumber()).left(6)];
    int bays, channels;
    switch (dt) {
    case BBD101:
    case BBD201:
    case BSC001:
        bays = 1;
        break;

    case BBD102:
    case BBD202:
    case BSC002:
        bays = 2;
        break;

    case BSC103:
    case BBD103:
    case BSC203:
        bays = 3;
        break;

    default:
        bays = -1;
        break;
    }

    switch (dt) {
    case BSC001:
    case BSC101:
    case BMS001:
    case KDC101:
    case OST001:
    case ODC001:
    case TST001:
    case TDC001:
    case TBD001:
        channels = 1;
        break;

    case BSC002:
    case BSC102:
    case BMS002:
    case MST601:
        channels = 2;
        break;
    default:
        channels = -1;
        break;
    }

    functions_set fs;

    switch (dt) {
    case TDC001:
        fs = tdc_set;
        break;

    case TST001:
        fs = tst_set;
        break;

    case BSC001:
    case BSC002:
    case BSC101:
    case BSC102:
    case BSC103:
    case BSC201:
    case BSC202:
    case BSC203:
        fs = bsc_set;
        break;

    case BBD101:
    case BBD102:
    case BBD103:
    case BBD201:
    case BBD202:
    case BBD203:
        fs = bbd_set;

    default:
        fs = all_set;
        break;
    }

    opened_device.channels = channels;
    opened_device.bays = bays;
    opened_device.functions = fs;
};
