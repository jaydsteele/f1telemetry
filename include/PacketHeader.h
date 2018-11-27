#ifndef __PacketHeader_h__
#define __PacketHeader_h__

#include "types.h"
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
    uint16_t    m_packetFormat;       // 2018
    uint8_t     m_packetVersion;      // Version of this packet type, all start from 1
    uint8_t     m_packetId;           // Identifier for the packet type, see below
    uint64_t    m_sessionUID;         // Unique identifier for the session
    float       m_sessionTime;        // Session timestamp
    uint_t      m_frameIdentifier;    // Identifier for the frame the data was retrieved on
    uint8_t     m_playerCarIndex;     // Index of player's car in the array

    friend std::istream& operator >>(std::istream& is, PacketHeader& data) {
        is.read((char *)&data.m_packetFormat, sizeof(uint16_t));
        is.read((char *)&data.m_packetVersion, sizeof(uint8_t));
        is.read((char *)&data.m_packetId, sizeof(uint8_t));
        is.read((char *)&data.m_sessionUID, sizeof(uint64_t));
        is.read((char *)&data.m_sessionTime, sizeof(float));
        is.read((char *)&data.m_frameIdentifier, sizeof(uint_t));
        is.read((char *)&data.m_playerCarIndex, sizeof(uint8_t));
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