/***************************************************************************
**                                                                        **
**  This file is part of TMC, Thorlabs motor controller                   **
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

#ifndef MESS_CODES
#define MESS_CODES

enum {
    //Generic messages
    IDENTIFY = 0x0223,

    SET_CHANENABLESTATE = 0x0210,
    REQ_CHANENABLESTATE = 0x0211,
    GET_CHANENABLESTATE = 0x0212,

    HW_DISCONNECT = 0x0002,
    HW_RESPONSE = 0x0080,
    RICHRESPONSE = 0x0081,

    HW_START_UPDATEMSGS = 0x0011,
    HW_STOP_UPDATEMSGS = 0x0012,
    HW_REQ_INFO = 0x0005,
    HW_GET_INFO = 0x0006,

    RACK_REQ_BAYUSED = 0x0060,
    RACK_GET_BAYUSED = 0x0061,
    HUB_REQ_BAYUSED = 0x0065,
    HUB_GET_BAYUSED = 0x0066,

    //Motor control messages
    HW_YES_FLASH_PROGRAMMING = 0x0017,
    HW_NO_FLASH_PROGRAMMING = 0x0018,

    SET_POSCOUNTER = 0x0410,
    REQ_POSCOUNTER = 0x0411,
    GET_POSCOUNTER = 0x0412,

    SET_ENCCOUNTER = 0x0409,
    REQ_ENCCOUNTER = 0x040a,
    GET_ENCCOUNTER = 0x040b,

    SET_VELPARAMS = 0x0413,
    REQ_VELPARAMS = 0x0414,
    GET_VELPARAMS = 0x0415,

    SET_JOGPARAMS = 0x0416,
    REQ_JOGPARAMS = 0x0417,
    GET_JOGPARAMS = 0x0418,

    SET_POWERPARAMS = 0x0426,
    REQ_POWERPARAMS = 0x0427,
    GET_POWERPARAMS = 0x0428,

    SET_GENMOVEPARAMS = 0x043a,
    REQ_GENMOVEPARAMS = 0x043b,
    GET_GENMOVEPARAMS = 0x043c,

    SET_MOVERELPARAMS = 0x0445,
    REQ_MOVERELPARAMS = 0x0446,
    GET_MOVERELPARAMS = 0x0447,

    SET_MOVEABSPARAMS = 0x0450,
    REQ_MOVEABSPARAMS = 0x0451,
    GET_MOVEABSPARAMS = 0x0452,

    SET_HOMEPARAMS = 0x0440,
    REQ_HOMEPARAMS = 0x0441,
    GET_HOMEPARAMS = 0x0442,

    SET_LIMSWITCHPARAMS = 0x0423,
    REQ_LIMSWITCHPARAMS = 0x0424,
    GET_LIMSWITCHPARAMS = 0x0425,

    MOVE_HOME = 0x0443,
    MOVE_HOMED = 0x0444,

    MOVE_RELATIVE = 0x0448,
    MOVE_COMPLETED = 0x0464,
    MOVE_ABSOLUTE = 0x0453,
    MOVE_JOG = 0x046a,
    MOVE_VELOCITY = 0x0457,
    MOVE_STOP = 0x0465,
    MOVE_STOPPED = 0x0466,

    SET_BOWINDEX = 0x04f4,
    REQ_BOWINDEX = 0x04f5,
    GET_BOWINDEX = 0x04f6,

    SET_AVMODES = 0x04b3,
    REQ_AVMODES = 0x04b4,
    GET_AVMODES = 0x04b5,

    SET_BUTTONPARAMS = 0x04b6,
    REQ_BUTTONPARAMS = 0x04b7,
    GET_BUTTONPARAMS = 0x04b8,

    GET_STATUSUPDATE = 0x0481,
    REQ_STATUSUPDATE = 0x0480,

    GET_DCSTATUSUPDATE = 0x0491,
    REQ_DCSTATUSUPDATE = 0x0490,
    ACK_DCSTATUSUPDATE = 0x0492,

    REQ_STATUSBITS = 0x0429,
    GET_STATUSBITS = 0x042a,

    SUSPEND_ENDOFMOVEMSGS = 0x046b,
    RESUME_ENDOFMOVEMSGS = 0x046c,

    SET_TRIGGER = 0x0500,
    REQ_TRIGGER = 0x0501,
    GET_TRIGGER = 0x0502,
};

#endif
