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

#ifndef DEVICE_H
#define DEVICE_H

#include <inttypes.h>
#include <limits.h>
#include <set>

namespace QtLab {
namespace hw {
namespace Thorlabs {
typedef std::set<int> functions_set;

typedef struct
{
    int motor_type;
    int max_pos = INT_MAX;
    int max_vel = INT_MAX;
    int max_acc = INT_MAX;
    int tick;
    uint8_t dest;
    int32_t status_position = 0;
    uint16_t status_velocity = 0;
    int32_t status_enc_count = 0;
    uint16_t status_status_bits = 0;
    bool moving = false;
    bool homing = false;
    bool stopping = false;
} motor_device;

typedef struct
{
    int device_type;
    int hw_type;
    int bays;
    int channels;
    uint8_t dest;
    bool status_updates;
    char *SN = (char *) "00000000";
    char *dev_type_name = (char *) "No device name";
    bool bay_used[3];
    motor_device motor[3];
    bool end_of_move_messages = true;
    functions_set functions;
} controller_device;

// enum for device types
enum dev_type {
    BSC001,
    BSC002,
    BMS001,
    BMS002,
    MST601,
    MST602,
    BSC101,
    BSC102,
    BSC103,
    BSC201,
    BSC202,
    BSC203,
    BBD101,
    BBD102,
    BBD103,
    BBD201,
    BBD202,
    BBD203,
    KDC101,
    OST001,
    ODC001,
    TST001,
    TDC001,
    TBD001,
};
} // namespace Thorlabs
} // namespace hw
} // namespace QtLab

#endif // DEVICE_H
