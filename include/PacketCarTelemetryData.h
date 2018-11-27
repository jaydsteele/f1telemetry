#ifndef __PacketCarTelemetryData_h__
#define __PacketCarTelemetryData_h__

#include "include/types.h"
#include "include/PacketHeader.h"
#include "include/CarTelemetryData.h"

struct PacketCarTelemetryData
{
    PacketHeader        m_header;                // Header

    CarTelemetryData    m_carTelemetryData[20];

    uint32_t            m_buttonStatus;         // Bit flags specifying which buttons are being
                                                // pressed currently - see appendices
};

#endif