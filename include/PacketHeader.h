#ifndef __PacketHeader_h__
#define __PacketHeader_h__

#include "types.h"
#include "unpack.h"
#include <iostream>

enum PacketID: uint8_t {
    PACKET_ID_MOTION = 0,
    PACKET_ID_SESSION = 1,
    PACKET_ID_LAP_DATA = 2,
    PACKET_ID_EVENT = 3,
    PACKET_ID_PARTICIPANTS = 4,
    PACKET_ID_CAR_SETUPS = 5,
    PACKET_ID_CAR_TELEMETRY = 6,
    PACKET_ID_CAR_STATUS = 7,
};

static const char * const PacketID_name[] = {
    "MOTION", "SESSION", "LAP_DATA", "EVENT", "PARTICIPANTS", "CAR_SETUPS",
    "CAR_TELEMETRY", "CAR_STATUS",
};

struct PacketHeader
{
    static const int BUFFER_SIZE = 21;

    uint16_t    m_packetFormat;       // 2018
    uint8_t     m_packetVersion;      // Version of this packet type, all start from 1
    uint8_t     m_packetId;           // Identifier for the packet type, see below
    uint64_t    m_sessionUID;         // Unique identifier for the session
    float       m_sessionTime;        // Session timestamp
    uint_t      m_frameIdentifier;    // Identifier for the frame the data was retrieved on
    uint8_t     m_playerCarIndex;     // Index of player's car in the array

    friend std::istream& operator >>(std::istream& is, PacketHeader& data) {
        static char buffer[BUFFER_SIZE];
        is.read(buffer, sizeof(buffer));
        int pos=0;
        if (is.good()) {
            data.m_packetFormat = unpack_uint16(buffer, pos);
            data.m_packetVersion = unpack_uint8(buffer, pos+=2);
            data.m_packetId = unpack_uint8(buffer, pos+=1);
            data.m_sessionUID = unpack_uint64(buffer, pos+=1);
            data.m_sessionTime = unpack_float(buffer, pos+=8);
            data.m_frameIdentifier = unpack_uint(buffer, pos+=4);
            data.m_playerCarIndex = unpack_uint8(buffer, pos+=4);
        }
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(indent) << "PacketHeader {" << std::endl;
        os << whitespace(indent) << "  m_packetFormat: " << this->m_packetFormat << std::endl;
        os << whitespace(indent) << "  m_packetVersion: " << (uint16_t)this->m_packetVersion << std::endl;
        os << whitespace(indent) << "  m_packetId: " << PacketID_name[this->m_packetId] << std::endl;
        os << whitespace(indent) << "  m_sessionUID: " << this->m_sessionUID << std::endl;
        os << whitespace(indent) << "  m_sessionTime: " << this->m_sessionTime << std::endl;
        os << whitespace(indent) << "  m_frameIdentifier: " << this->m_frameIdentifier << std::endl;
        os << whitespace(indent) << "  m_playerCarIndex: " << (uint16_t)this->m_playerCarIndex << std::endl;
        os << whitespace(indent) << "}" << std::endl;
    }
};

#endif