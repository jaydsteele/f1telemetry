#ifndef __PacketLapData_h__
#define __PacketLapData_h__

#include "PacketHeader.h"
#include "LapData.h"

struct PacketLapData
{
    LapData         m_lapData[20];         // Lap data for all cars on track

    friend std::istream& operator >>(std::istream& is, PacketLapData& data) {
        for (int i=0; i<20; i++) {
            is >> data.m_lapData[i];
        }
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(indent) << "PacketLapData {" << std::endl;
        for (int i=0; i<20; i++) {
            this->m_lapData[i].dump(os, indent+2);
        }
        os << whitespace(indent) << "}" << std::endl;
    }

};

#endif