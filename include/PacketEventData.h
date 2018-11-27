#ifndef __PacketEventData_h__
#define __PacketEventData_h__

#include "types.h"
#include "PacketHeader.h"
#include <iostream>

struct PacketEventData
{
    uint8_t         m_eventStringCode[4];   // Event string code, see above

    friend std::istream& operator >>(std::istream& is, PacketEventData& data) {
        is.read((char *)&data.m_eventStringCode, sizeof(uint8_t)*4);
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(indent) << "PacketEventData {" << std::endl;
        os << whitespace(indent) << "  m_eventStringCode: "
            << (char)this->m_eventStringCode[0]
            << (char)this->m_eventStringCode[1]
            << (char)this->m_eventStringCode[2]
            << (char)this->m_eventStringCode[3]
            << std::endl;
        os << whitespace(indent) << "}" << std::endl;
    }
};

#endif