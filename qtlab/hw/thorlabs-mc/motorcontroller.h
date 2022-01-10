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

#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <endian.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <pthread.h>

#include <QObject>

#include <qtlab/hw/serial/serialdevice.h>

#include "device.h"
#include "messages.h"


#define MAX_RESPONSE_SIZE 128
#define SOURCE 0x01

#define FT_ERROR -6
#define DEVICE_ERROR -7
#define FATAL_ERROR -8

#define MOVED_HOME_STATUS 3
#define MOVE_COMPLETED_STATUS 2
#define MOVE_STOPPED_STATUS 4

#define OTHER_MESSAGE 5
#define EMPTY 1

#define INVALID_DEST -10
#define INVALID_SOURCE -11
#define INVALID_CHANNEL -12

#define INVALID_PARAM_1 -15
#define INVALID_PARAM_2 -16
#define INVALID_PARAM_3 -17
#define INVALID_PARAM_4 -18
#define INVALID_PARAM_5 -19

#define DEFAULTDEST 0x50
#define DEFAULTCHANNEL8 0x01
#define DEFAULTCHANNEL16 0x01


class MotorController : public SerialDevice
{
public:

    MotorController(QObject *parent = nullptr);

    //----------------- Device communication functions ---------------------------------

    int CheckParams(uint8_t dest, int chanID);

    void SendMessage(Message &message);

    int CheckIncomingQueue(uint16_t &ret_msgID);

    int EmptyIncomingQueue();

    int GetResponseMess(uint16_t expected_msg, int size, uint8_t *mess);


// ------------------------- Generic device calls ------------------------------

    int Identify(uint8_t dest = DEFAULTDEST);

    int EnableChannel(uint8_t dest = DEFAULTDEST, uint8_t chanel = DEFAULTCHANNEL8);

    int DisableChannel(uint8_t dest = DEFAULTDEST, uint8_t chanel = DEFAULTCHANNEL8);

    int ChannelState(GetChannelState &info, uint8_t dest = DEFAULTDEST, uint8_t chanel = DEFAULTCHANNEL8);

    int DisconnectHW(uint8_t dest = DEFAULTDEST);

    int StartUpdateMess(uint8_t rate = 1, uint8_t dest = DEFAULTDEST);

    int StopUpdateMess(uint8_t dest = DEFAULTDEST);

    int GetHwInfo(HwInfo &message, uint8_t dest = DEFAULTDEST);

    int GetBayUsed(GetRackBayUsed &message, uint8_t bayID, uint8_t dest = DEFAULTDEST);

//-------------------------- Motor control calls ------------------------------

    int FlashProgYes(uint8_t dest = DEFAULTDEST);

    int FlashProgNo(uint8_t dest = DEFAULTDEST);

    int SetPositionCounter(int32_t pos, uint8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int GetPositionCounter(GetPosCounter &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int SetEncoderCounter(int32_t count, uint8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int GetEncoderCounter(GetEncCount &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int SetVelocityP(int32_t acc, int32_t maxVel, uint8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int GetVelocityP(GetVelocityParams &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int SetJogP(uint16_t mode, int32_t stepSize, int32_t vel, int32_t acc, uint16_t stopMode, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int GetJogP(GetJogParams &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int SetPowerUsed(uint16_t rest_power, uint16_t move_power, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int GetPowerUsed(GetPowerParams &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int SetBacklashDist(uint32_t dist, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int GetBacklashDist(GetGeneralMoveParams &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int SetRelativeMoveP(uint32_t dist, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int GetRelativeMoveP(GetRelativeMoveParams &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int SetAbsoluteMoveP(uint32_t pos, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int GetAbsoluteMoveP(GetAbsoluteMoveParams &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int SetHomingVel(uint32_t vel, int8_t dest = DEFAULTDEST,  uint16_t channel = DEFAULTCHANNEL16);

    int GetHomingVel(GetHomeParams &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int SetLimitSwitchConfig(uint16_t CwHwLim, uint16_t CCwHwLim, uint16_t CwSwLim, uint16_t CCwSwLim, uint16_t mode, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int GetLimitSwitchConfig(GetLimitSwitchParams &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int MoveToHome(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int StartSetRelativeMove(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int StartRelativeMove(int32_t dist, uint8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int StartSetAbsoluteMove(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int StartAbsoluteMove(int32_t pos, uint8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int StartJogMove(uint8_t direction, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int StartSetVelocityMove(uint8_t direction, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int StopMovement(uint8_t stopMode = 0x02, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int SetAccelerationProfile(uint16_t index, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int GetAccelerationProfile(GetBowIndex &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int SetLedP(uint16_t mode, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int GetLedP(GetLedMode &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int SetButtons(uint16_t mode, int32_t pos1, int32_t pos2, uint16_t timeout, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int GetButtonsInfo(GetButtonParams &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int ReqStatus(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int ReqDcStatus(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int SendServerAlive(uint8_t dest = DEFAULTDEST);

    int GetStatBits(GetStatusBits &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int DisableEomMessages(uint8_t dest = DEFAULTDEST);

    int EnableEomMessages(uint8_t dest = DEFAULTDEST);

    int CreateTrigger(uint8_t mode, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int GetMotorTrigger(GetTrigger &message, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

protected:
    virtual void postConnect_impl() override;

private:

    int devices_connected;
    controller_device opened_device;
    int opened_device_index;
};

#endif // MOTORCONTROLLER_H
