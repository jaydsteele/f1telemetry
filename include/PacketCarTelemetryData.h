#ifndef __PacketCarTelemetryData_h__
#define __PacketCarTelemetryData_h__

#include "types.h"
#include "PacketHeader.h"
#include "CarTelemetryData.h"
#include <iostream>

struct PacketCarTelemetryData
{
    CarTelemetryData    m_carTelemetryData[20];

    uint32_t            m_buttonStatus;         // Bit flags specifying which buttons are being
                                                // pressed currently - see appendices

    friend std::istream& operator >>(std::istream& is, PacketCarTelemetryData& data) {
        for (int i=0; i<20; i++) {
            is >> data.m_carTelemetryData[i];
        }
        if (!is.good()) return is;
        is.read((char *)&data.m_buttonStatus, sizeof(uint32_t));
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(indent) << "PacketCarTelemetryData {" << std::endl;
        for (int i=0; i<20; i++) {
            this->m_carTelemetryData[i].dump(os, indent+2);
        }
        os << "  m_carTelemetryData: " << this->m_buttonStatus << std::endl;
        os << whitespace(indent) << "}" << std::endl;
    }

};

#endif