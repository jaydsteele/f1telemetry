#ifndef __PacketCarStatusData_h__
#define __PacketCarStatusData_h__

#include "PacketHeader.h"
#include "CarStatusData.h"
#include <iostream>

struct PacketCarStatusData
{
    CarStatusData       m_carStatusData[20];

    friend std::istream& operator >>(std::istream& is, PacketCarStatusData& data) {
        for (int i=0; i<20; i++) {
            is >> data.m_carStatusData[i];
        }
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(indent) << "PacketCarStatusData {" << std::endl;
        for (int i=0; i<20; i++) {
            this->m_carStatusData[i].dump(os, indent+2);
        }
        os << whitespace(indent) << "}" << std::endl;
    }

};

#endif