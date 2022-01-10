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

#define EMPTY_IN_QUEUE ret = EmptyIncomingQueue();    \
    if (ret != 0) return ret;

#define CHECK_ADDR_PARAMS(dest, chanID) int ret;        \
    ret = CheckParams(dest, chanID);                  \
    if (ret != 0) return ret;

#define GET_MESS(req_mess_class, buff_size, get_mess_code, get_mess_class) \
    CHECK_ADDR_PARAMS(dest, channel)                        \
    EMPTY_IN_QUEUE                                          \
    req_mess_class mes(dest, SOURCE, channel);              \
    SendMessage(mes);                                       \
    uint8_t *buff = (uint8_t *) malloc(buff_size);          \
    ret = GetResponseMess(get_mess_code, buff_size, buff);  \
    message.SetData(buff);                                  \
    free(buff);                                             \
    if (ret != 0) return ret;                              \
    EMPTY_IN_QUEUE


void MotorController::SendMessage(Message &message)
{
    QByteArray ba((char *)message.data(), message.msize());
    serial->sendMsg(ba);
}

int MotorController::CheckParams(uint8_t dest, int chanID)
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

int MotorController::CheckIncomingQueue(uint16_t &ret_msgID)
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
        printf("Device with serial %s disconnecting\n", opened_device.SN);
        return FATAL_ERROR;
    }
    case HW_RESPONSE: {
        serial->read((char*)buff, 4);
        HwResponse response(buff);
        fprintf(stderr, "Device with serial %s encountered error\n", opened_device.SN);
        return DEVICE_ERROR;
    }
    case RICHRESPONSE: {
        serial->read((char*)buff, 72);
        HwResponseInfo response(buff);
        fprintf(stderr, "Device with serial %s encountered error\n", opened_device.SN);
        fprintf(stderr, "Detailed description of error \n ");
        uint16_t error_cause = response.GetMsgID();
        if (error_cause != 0) printf("\tMessage causing error: %hu\n ", error_cause);
        fprintf(stderr, "\tThorlabs error code: %hu \n", response.GetCode());
        fprintf(stderr, "\tDescription: %s\n", response.GetDescription());
        return DEVICE_ERROR;
    }
    case MOVE_HOMED: {
        serial->read((char*)buff, 4);
        MovedHome response(buff);
        assert (response.GetMotorID() < 3);
        opened_device.motor[response.GetMotorID()].homing = false;
        printf("Motor with id %i moved to home position\n", response.GetMotorID() + 1);
        return MOVED_HOME_STATUS;
    }
    case MOVE_COMPLETED: {
        serial->read((char*)buff, 18);     // 14 bytes for status updates
        MoveCompleted response(buff);
        assert (response.GetMotorID() < 3);
        opened_device.motor[response.GetMotorID()].homing = false;
        printf("Motor with id %i completed move\n", response.GetMotorID() + 1);
        return MOVE_COMPLETED_STATUS;
    }
    case MOVE_STOPPED: {
        serial->read((char*)buff, 18);    // 14 bytes for status updates
        MoveStopped response(buff);
        assert (response.GetMotorID() < 3);
        opened_device.motor[response.GetMotorID()].homing = false;
        printf("Motor with id %i stopped \n", response.GetMotorID() + 1);
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

int MotorController::EmptyIncomingQueue()
{
    while (true) {
        uint16_t messID = 0;
        int ret = CheckIncomingQueue(messID);
        if (ret == EMPTY) return 0;
        if (ret == MOVED_HOME_STATUS || ret == MOVE_COMPLETED_STATUS || ret == MOVE_STOPPED_STATUS || ret == 0) continue;
        switch (ret) {
        case FATAL_ERROR: return FATAL_ERROR;
        case FT_ERROR: return FT_ERROR;
        case DEVICE_ERROR: return DEVICE_ERROR;
        case OTHER_MESSAGE: {
            fprintf(stderr, "Unknown message received, protocol violated\n");
            return FATAL_ERROR;
        }
        }
    }
}

int MotorController::GetResponseMess(uint16_t expected_msg, int size, uint8_t *mess)
{
    int ret;
    uint16_t msgID;
    while (true) {
        ret = CheckIncomingQueue(msgID);
        if (ret == OTHER_MESSAGE) {
            if (msgID == expected_msg) {
                *((int16_t *) &mess[0]) =  htole16(msgID);
                if (serial->read((char*)(&mess[2]), size - 2) != size - 2) {
                    throw std::runtime_error("Cannot read from serial");
                }
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


int MotorController::Identify(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    IdentifyMs mes(dest, 0x01);
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
}

int MotorController::EnableChannel(uint8_t dest, uint8_t chanel)
{
    CHECK_ADDR_PARAMS(dest, chanel)
    EMPTY_IN_QUEUE
    SetChannelState mes(chanel, 1, dest, SOURCE);
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
}

int MotorController::DisableChannel(uint8_t dest, uint8_t chanel)
{
    CHECK_ADDR_PARAMS(dest, chanel)
    EMPTY_IN_QUEUE
    SetChannelState mes(chanel, 2, dest, SOURCE);
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
}

int MotorController::ChannelState(GetChannelState &info, uint8_t dest, uint8_t chanel)
{
    CHECK_ADDR_PARAMS(dest, chanel)
    EMPTY_IN_QUEUE
    ReqChannelState mes(chanel, dest, SOURCE);
    SendMessage(mes);
    uint8_t *buff = (uint8_t *) malloc(HEADER_SIZE);
    ret = GetResponseMess(GET_CHANENABLESTATE, HEADER_SIZE, buff);
    info.SetData(buff);
    free(buff);
    if (ret != 0) return ret;
    EMPTY_IN_QUEUE
    return 0;
}

int MotorController::DisconnectHW(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    HwDisconnect mes(dest, SOURCE);
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
}

int MotorController::StartUpdateMess(uint8_t rate, uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    StartUpdateMessages mes(dest, SOURCE);
    if (mes.SetUpdaterate(rate) == IGNORED_PARAM) printf("This parameter is ignored in connected device. Using default.\n");
    SendMessage(mes);
    opened_device.status_updates = true;
    EMPTY_IN_QUEUE
    return 0;
}

int MotorController::StopUpdateMess(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    StopUpdateMessages mes(dest, SOURCE);
    SendMessage(mes);
    opened_device.status_updates = false;
    EMPTY_IN_QUEUE
    return 0;
}

int MotorController::GetHwInfo(HwInfo &message, uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    ReqHwInfo mes(dest, SOURCE);
    SendMessage(mes);
    uint8_t *buff = (uint8_t *) malloc(90);
    ret = GetResponseMess(HW_GET_INFO, 90, buff);
    message.SetData(buff);
    free(buff);
    if (ret != 0) return ret;
    EMPTY_IN_QUEUE
    return 0;
}

int MotorController::GetBayUsed(GetRackBayUsed &message, uint8_t bayID, uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    ReqRackBayUsed mes(dest, SOURCE);
    mes.SetBayIdent(bayID);
    SendMessage(mes);
    uint8_t *buff = (uint8_t *) malloc(HEADER_SIZE);
    ret = GetResponseMess(RACK_GET_BAYUSED, HEADER_SIZE, buff);
    message.SetData(buff);
    free(buff);
    if (ret != 0) return ret;
    EMPTY_IN_QUEUE
    return 0;
}

int MotorController::FlashProgYes(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    YesFlashProg mes(dest, SOURCE);
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::FlashProgNo(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    NoFlashProg mes(dest, SOURCE);
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::SetPositionCounter(int32_t pos, uint8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetPosCounter mes(dest, SOURCE, channel);
    mes.SetPosition(pos);
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return ret; //return WARNING
};

int MotorController::GetPositionCounter(GetPosCounter &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqPosCounter, 12, GET_POSCOUNTER, GetPosCounter)
    return 0;
};

int MotorController::SetEncoderCounter(int32_t count, uint8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetEncCount mes(dest, SOURCE, channel);
    mes.SetEncoderCount(count);
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return ret; //return WARNING
};

int MotorController::GetEncoderCounter(GetEncCount &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqEncCount, 12, GET_ENCCOUNTER, GetEncCount)
    return 0;
};

int MotorController::SetVelocityP(int32_t acc, int32_t maxVel, uint8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetVelocityParams mes(dest, SOURCE, channel);
    if (mes.SetAcceleration(acc) == INVALID_PARAM) return INVALID_PARAM_1;
    if (mes.SetMaxVel(maxVel) == INVALID_PARAM) return INVALID_PARAM_2;
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::GetVelocityP(GetVelocityParams &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqVelocityParams, 20, GET_VELPARAMS, GetVelocityParams)
    return 0;
};

int MotorController::SetJogP(uint16_t mode, int32_t stepSize, int32_t vel, int32_t acc, uint16_t stopMode, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetJogParams mes(dest, SOURCE, channel);
    if (mes.SetJogMode(mode) == INVALID_PARAM) return INVALID_PARAM_1;
    mes.SetStepSize(stepSize);
    if (mes.SetMaxVelocity(vel) == INVALID_PARAM) return INVALID_PARAM_3;
    if (mes.SetAcceleration(acc) == INVALID_PARAM) return INVALID_PARAM_4;
    if (mes.SetStopMode(stopMode) == INVALID_PARAM) return INVALID_PARAM_5;
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::GetJogP(GetJogParams &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqJogParams, 28, GET_JOGPARAMS, GetJogParams)
    return 0;
};

int MotorController::SetPowerUsed(uint16_t rest_power, uint16_t move_power, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetPowerParams mes(dest, SOURCE, channel);
    if (mes.SetRestFactor(rest_power) == INVALID_PARAM) return INVALID_PARAM_1;
    if (mes.SetMoveFactor(move_power) == INVALID_PARAM) return INVALID_PARAM_2;
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::GetPowerUsed(GetPowerParams &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqPowerParams, 12, GET_POWERPARAMS, GetPowerParams)
    return 0;
};

int MotorController::SetBacklashDist(uint32_t dist, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetGeneralMoveParams mes(dest, SOURCE, channel);
    mes.SetBacklashDist(dist);
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::GetBacklashDist(GetGeneralMoveParams &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqGeneralMoveParams, 12, GET_GENMOVEPARAMS, GetGeneralMoveParams)
    return 0;
};

int MotorController::SetRelativeMoveP(uint32_t dist, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetRelativeMoveParams mes(dest, SOURCE, channel);
    mes.SetRelativeDist(dist);
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::GetRelativeMoveP(GetRelativeMoveParams &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqRelativeMoveParams, 12, GET_MOVERELPARAMS, GetRelativeMoveParams)
    return 0;
};

int MotorController::SetAbsoluteMoveP(uint32_t pos, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetAbsoluteMoveParams mes(dest, SOURCE, channel);
    mes.SetAbsolutePos(pos);
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::GetAbsoluteMoveP(GetAbsoluteMoveParams &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqAbsoluteMoveParams, 12, GET_MOVEABSPARAMS, GetAbsoluteMoveParams)
    return 0;
};

int MotorController::SetHomingVel(uint32_t vel, int8_t dest,  uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetHomeParams mes(dest, SOURCE, channel);
    if (mes.SetHomingVelocity(vel) == INVALID_PARAM) return INVALID_PARAM_1;
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::GetHomingVel(GetHomeParams &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqHomeParams, 20, GET_HOMEPARAMS, GetHomeParams)
    return 0;
};

int MotorController::SetLimitSwitchConfig(uint16_t CwHwLim, uint16_t CCwHwLim, uint16_t CwSwLim, uint16_t CCwSwLim, uint16_t mode, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetLimitSwitchParams mes(dest, SOURCE, channel);
    if (mes.SetClockwiseHardLimit(CwHwLim) == INVALID_PARAM) return INVALID_PARAM_1;
    if (mes.SetCounterlockwiseHardLimit(CCwHwLim) == INVALID_PARAM) return INVALID_PARAM_2;
    if (mes.SetClockwiseSoftLimit(CwSwLim) == IGNORED_PARAM) printf("Software limit ignored in this device");
    if (mes.SetCounterlockwiseSoftLimit(CCwSwLim) == IGNORED_PARAM) printf("Software limit ignored in this device");
    ret = mes.SetLimitMode(mode);
    if (ret == INVALID_PARAM) return INVALID_PARAM_5;
    if (ret == IGNORED_PARAM) printf("Limit mode ignored in this device");
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::GetLimitSwitchConfig(GetLimitSwitchParams &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqLimitSwitchParams, 22, GET_LIMSWITCHPARAMS, GetLimitSwitchParams)
    return 0;
};

int MotorController::MoveToHome(uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    MoveHome mes(dest, SOURCE, channel);
    SendMessage(mes);
    opened_device.motor[mes.GetMotorID()].homing = true;
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::StartSetRelativeMove(uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    MoveRelative1 mes(dest, SOURCE, channel);
    SendMessage(mes);
    opened_device.motor[mes.GetMotorID()].moving = true;
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::StartRelativeMove(int32_t dist, uint8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    MoveRelative2 mes(dest, SOURCE, channel);
    mes.SetRelativeDistance(dist);
    SendMessage(mes);
    opened_device.motor[mes.GetMotorID()].moving = true;
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::StartSetAbsoluteMove(uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    MoveAbsolute1 mes(dest, SOURCE, channel);
    SendMessage(mes);
    opened_device.motor[mes.GetMotorID()].moving = true;
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::StartAbsoluteMove(int32_t pos, uint8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    MoveAbsolute2 mes(dest, SOURCE, channel);
    if (mes.SetAbsoluteDistance(pos) == INVALID_PARAM) return INVALID_PARAM_1;
    SendMessage(mes);
    opened_device.motor[mes.GetMotorID()].moving = true;
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::StartJogMove(uint8_t direction, uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    JogMove mes(dest, SOURCE, channel);
    if (mes.SetDirection(direction) == INVALID_PARAM) return INVALID_PARAM_1;
    SendMessage(mes);
    opened_device.motor[mes.GetMotorID()].moving = true;
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::StartSetVelocityMove(uint8_t direction, uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    MovewVelocity mes(dest, SOURCE, channel);
    if (mes.SetDirection(direction) == INVALID_PARAM) return INVALID_PARAM_1;
    SendMessage(mes);
    opened_device.motor[mes.GetMotorID()].moving = true;
    EMPTY_IN_QUEUE
    return 0;
}

int MotorController::StopMovement(uint8_t stopMode, uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    StopMove mes(dest, SOURCE, channel);
    if (mes.SetStopMode(stopMode) == INVALID_PARAM) return INVALID_PARAM_1;
    SendMessage(mes);
    opened_device.motor[mes.GetMotorID()].stopping = true;
    EMPTY_IN_QUEUE
    return 0;
}

int MotorController::SetAccelerationProfile(uint16_t index, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetBowIndex mes(dest, SOURCE, channel);
    if (mes.SetBowindex(index) == INVALID_PARAM) return INVALID_PARAM_1;
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::GetAccelerationProfile(GetBowIndex &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqBowIndex, 10, GET_BOWINDEX, GetBowIndex)
    return 0;
};

int MotorController::SetLedP(uint16_t mode, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetLedMode mes(dest, SOURCE, channel);
    if (mes.SetMode(mode) == INVALID_PARAM) return INVALID_PARAM_1;
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::GetLedP(GetLedMode &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqLedMode, 10, GET_AVMODES, GetLedMode)
    return 0;
};

int MotorController::SetButtons(uint16_t mode, int32_t pos1, int32_t pos2, uint16_t timeout, int8_t dest, uint16_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetButtonParams mes(dest, SOURCE, channel);
    if (mes.SetMode(mode) == INVALID_PARAM) return INVALID_PARAM_1;
    if (mes.SetPosition1(pos1) == INVALID_PARAM) return INVALID_PARAM_2;
    if (mes.SetPosition2(pos2) == INVALID_PARAM) return INVALID_PARAM_3;
    if (mes.SetTimeout(timeout) == IGNORED_PARAM) printf("Timeout ignored in this device");
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::GetButtonsInfo(GetButtonParams &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqButtonParams, 22, GET_BUTTONPARAMS, GetButtonParams)
    return 0;
};

int MotorController::ReqStatus(uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    ReqStatusUpdate mes(dest, SOURCE, channel);
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::ReqDcStatus(uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    ReqMotChanStatusUpdate mes(dest, SOURCE, channel);
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::SendServerAlive(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    ServerAlive mes(dest, SOURCE);
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::GetStatBits(GetStatusBits &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqStatusBits, 12, GET_STATUSBITS, GetStatusBits)
    return 0;
};

int MotorController::DisableEomMessages(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    DisableEndMoveMessages mes(dest, SOURCE);
    SendMessage(mes);
    opened_device.end_of_move_messages = false;
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::EnableEomMessages(uint8_t dest)
{
    CHECK_ADDR_PARAMS(dest, -1)
    EMPTY_IN_QUEUE
    EnableEndMoveMessages mes(dest, SOURCE);
    SendMessage(mes);
    opened_device.end_of_move_messages = true;
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::CreateTrigger(uint8_t mode, uint8_t dest, uint8_t channel)
{
    CHECK_ADDR_PARAMS(dest, channel)
    EMPTY_IN_QUEUE
    SetTrigger mes(dest, SOURCE, channel);
    if (mes.SetMode(mode) == IGNORED_PARAM) printf("trigger ignored in this device"); ;
    SendMessage(mes);
    EMPTY_IN_QUEUE
    return 0;
};

int MotorController::GetMotorTrigger(GetTrigger &message, uint8_t dest, uint8_t channel)
{
    GET_MESS(ReqTrigger, HEADER_SIZE, GET_TRIGGER, GetTrigger)
    return 0;
}

void MotorController::postConnect_impl()
{
    opened_device.channels = -1;
};
