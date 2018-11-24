#ifndef __PacketCarStatusData_h__
#define __PacketCarStatusData_h__

#include "include/PacketHeader.h"
#include "include/CarStatusData.h"

struct PacketCarStatusData
{
    PacketHeader        m_header;            // Header

    CarStatusData       m_carStatusData[20];
};

#endif