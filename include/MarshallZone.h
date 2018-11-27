#ifndef __MarshallZone_h__
#define __MarshallZone_h__

#include "types.h"
#include "utils.h"
#include <iostream>

struct MarshalZone
{
    float  m_zoneStart;   // Fraction (0..1) of way through the lap the marshal zone starts
    int8_t m_zoneFlag;    // -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow, 4 = red

    friend std::istream& operator >>(std::istream& is, MarshalZone& data) {
        is.read((char *)&data.m_zoneStart, sizeof(float));
        is.read((char *)&data.m_zoneFlag, sizeof(int8_t));
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