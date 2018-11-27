#ifndef __PacketCarSetupData_h__
#define __PacketCarSetupData_h__

#include "PacketHeader.h"
#include "CarSetupData.h"
#include <iostream>

struct PacketCarSetupData
{
    CarSetupData    m_carSetups[20];

    friend std::istream& operator >>(std::istream& is, PacketCarSetupData& data) {
        for (int i=0; i<20; i++) {
            is >> data.m_carSetups[i];
        }
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(indent) << "PacketCarSetupData {" << std::endl;
        for (int i=0; i<20; i++) {
            this->m_carSetups[i].dump(os, indent+2);
        }
        os << whitespace(indent) << "}" << std::endl;
    }

};

#endif