/****************************************************************************
 ** $BEGIN_LICENSE$
 **
 ** Quick System Loader
 ** Copyright (C) 2017 QSL Project
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.

 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.

 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **
 ** $END_LICENSE$
****************************************************************************/

#ifndef RPCHEADER_H
#define RPCHEADER_H

#include <stdint.h>

extern "C" {

struct RpcHeader
{
    enum Type
    {
        Reset = 0,
        Error = 1,
        Construct = 2,
        Destruct = 3,
        CallMethod = 4,
        ObjectId = 5
    };

    enum
    {
        DelimiterByte = 0x7d,
        DelimiterWord = 0x7d7d7d7d,
        DelimiterLength = 4
    };

    union {
        uint8_t delimiters[4];
        uint32_t delimiter;
    };

    uint16_t payloadLength;
    uint8_t checksum;
    uint8_t type;
    union {
        uint32_t classId;
        uint32_t objectId;
    };
} __attribute__((packed));

}

#endif // RPCHEADER_H
