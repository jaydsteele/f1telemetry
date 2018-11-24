#include "include/PacketHeader.h"
#include "include/LapData.h"

struct PacketLapData
{
    PacketHeader    m_header;              // Header

    LapData         m_lapData[20];         // Lap data for all cars on track
};