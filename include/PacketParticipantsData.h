#ifndef __PacketParticipantsData_h__
#define __PacketParticipantsData_h__

#include "include/types.h"
#include "include/PacketHeader.h"
#include "include/ParticipantData.h"

struct PacketParticipantsData
{
    static const int BUFFER_SIZE = 1;

    uint8_t         m_numCars;           // Number of cars in the data
    ParticipantData m_participants[20];

    friend std::istream& operator >>(std::istream& is, PacketParticipantsData& data) {
        static char buffer[BUFFER_SIZE];
        is.read(buffer, sizeof(buffer));
        if (is.good()) {
            data.m_numCars = unpack_uint8(buffer, 0);
        }
        for (int i=0; i<data.m_numCars; i++) {
            is >> data.m_participants[i];
        }
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(indent) << "PacketParticipantsData {" << std::endl;
        os << whitespace(indent) << "  m_numCars: " << (int)this->m_numCars << std::endl;
        for (int i=0; i<this->m_numCars; i++) {
            this->m_participants[i].dump(os, 2);
        }
        os << whitespace(indent) << "}" << std::endl;
    }

};

#endif