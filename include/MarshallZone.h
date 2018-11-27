#ifndef __MarshallZone_h__
#define __MarshallZone_h__

#include "include/types.h"
#include "include/unpack.h"
#include "include/utils.h"
#include <iostream>

struct MarshalZone
{
    static const int BUFFER_SIZE = 5;

    float  m_zoneStart;   // Fraction (0..1) of way through the lap the marshal zone starts
    int8_t m_zoneFlag;    // -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow, 4 = red

    friend std::istream& operator >>(std::istream& is, MarshalZone& data) {
        // first read everything preceeding the marshall zones
        static char buffer[BUFFER_SIZE];
        is.read(buffer, sizeof(buffer));
        if (is.good()) {
            int pos = 0;
            data.m_zoneStart = unpack_float(buffer, pos);
            data.m_zoneFlag = unpack_int8(buffer, pos+=4);
        }
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(2) << "MarshalZone {" << std::endl;
        os << whitespace(2) << "  m_zoneStart: " << this->m_zoneStart << std::endl;
        os << whitespace(2) << "  m_zoneFlag: " << (int)this->m_zoneFlag << std::endl;
        os << whitespace(2) << "}" << std::endl;
    }

};

#endif