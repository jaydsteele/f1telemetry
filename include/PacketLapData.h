#ifndef __PacketLapData_h__
#define __PacketLapData_h__

#include "PacketHeader.h"
#include "LapData.h"

struct PacketLapData
{
    PacketHeader    m_header;              // Header

    LapData         m_lapData[20];         // Lap data for all cars on track
};

#endif