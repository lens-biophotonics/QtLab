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

namespace QtLab {
namespace hw {
namespace Thorlabs {
class MotorController : public SerialDevice
{
    Q_OBJECT

public:

    MotorController(QObject *parent = nullptr);

// ------------------------- Generic device calls ------------------------------

    void identify(uint8_t dest = DEFAULTDEST);

    void enableChannel(uint8_t dest = DEFAULTDEST, uint8_t chanel = DEFAULTCHANNEL8);

    void disableChannel(uint8_t dest = DEFAULTDEST, uint8_t chanel = DEFAULTCHANNEL8);

    ChannelState getChannelState(uint8_t dest = DEFAULTDEST, uint8_t chanel = DEFAULTCHANNEL8);

    void disconnectHW(uint8_t dest = DEFAULTDEST);

    void startUpdateMess(uint8_t rate = 1, uint8_t dest = DEFAULTDEST);

    void stopUpdateMess(uint8_t dest = DEFAULTDEST);

    HwInfo _getHwInfo(uint8_t dest = DEFAULTDEST);

    const HwInfo *getHwInfo() const;

    RackBayUsed getBayUsed(uint8_t bayID, uint8_t dest = DEFAULTDEST);

//-------------------------- Motor control calls ------------------------------

    void flashProgYes(uint8_t dest = DEFAULTDEST);

    void flashProgNo(uint8_t dest = DEFAULTDEST);

    int setPositionCounter(int32_t pos, uint8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int getPositionCounter(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    int setEncoderCounter(int32_t count, uint8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int32_t getEncoderCounter(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void setVelocityP(int32_t acc, int32_t maxVel, uint8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    VelocityParams getVelocityP(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void setJogP(uint16_t mode, int32_t stepSize, int32_t vel, int32_t acc, uint16_t stopMode, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    JogParams getJogP(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void setPowerUsed(uint16_t rest_power, uint16_t move_power, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    PowerParams getPowerUsed(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void setBacklashDist(uint32_t dist, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int32_t getBacklashDist(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void setRelativeMoveP(uint32_t dist, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int32_t getRelativeMoveP(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void setAbsoluteMoveP(uint32_t pos, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    int32_t getAbsoluteMoveP(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void setHomingVel(uint32_t vel, int8_t dest = DEFAULTDEST,  uint16_t channel = DEFAULTCHANNEL16);

    int32_t getHomingVel(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void setLimitSwitchConfig(uint16_t CwHwLim, uint16_t CCwHwLim, uint16_t CwSwLim, uint16_t CCwSwLim, uint16_t mode, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    void getLimitSwitchConfig(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void moveToHome(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void startSetRelativeMove(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void startRelativeMove(int32_t dist, uint8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    void startSetAbsoluteMove(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void startAbsoluteMove(int32_t pos, uint8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    void startJogMove(uint8_t direction, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void startSetVelocityMove(uint8_t direction, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void stopMovement(uint8_t stopMode = 0x02, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void setAccelerationProfile(uint16_t index, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    uint16_t getAccelerationProfile(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void setLedP(uint16_t mode, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    uint16_t getLedP(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void setButtons(uint16_t mode, int32_t pos1, int32_t pos2, uint16_t timeout, int8_t dest = DEFAULTDEST, uint16_t channel = DEFAULTCHANNEL16);

    ButtonParams getButtonsInfo(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void reqStatus(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void reqDcStatus(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void sendServerAlive(uint8_t dest = DEFAULTDEST);

    uint32_t getStatBits(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    void disableEomMessages(uint8_t dest = DEFAULTDEST);

    void enableEomMessages(uint8_t dest = DEFAULTDEST);

    void createTrigger(uint8_t mode, uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

    uint8_t getMotorTrigger(uint8_t dest = DEFAULTDEST, uint8_t channel = DEFAULTCHANNEL8);

signals:
    void movedHome();
    void moveCompleted();
    void moveStopped();

protected:
    virtual void postConnect_impl() override;

private:

    //----------------- Device communication functions ---------------------------------

    int checkParams(uint8_t dest, int chanID);

    void sendMessage(Message &message);

    int checkIncomingQueue(uint16_t &ret_msgID);

    int emptyIncomingQueue();

    int getResponseMess(uint16_t expected_msg, int size, uint8_t *mess);

    int devices_connected;
    controller_device opened_device;
    int opened_device_index;

    bool awaitingResponse;
    HwInfo hwInfo;
};
}
}
}

#endif // MOTORCONTROLLER_H
