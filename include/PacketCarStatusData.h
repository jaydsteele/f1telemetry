#include "include/PacketHeader.h"
#include "include/CarStatusData.h"

struct PacketCarStatusData
{
    PacketHeader        m_header;            // Header

    CarStatusData       m_carStatusData[20];
};