#include "include/types.h"
#include "include/PacketHeader.h"
#include "include/CarTelemetryData.h"

struct PacketCarTelemetryData
{
    PacketHeader        m_header;                // Header

    CarTelemetryData    m_carTelemetryData[20];

    uint32              m_buttonStatus;         // Bit flags specifying which buttons are being
                                                // pressed currently - see appendices
};