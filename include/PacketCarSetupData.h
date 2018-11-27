#ifndef __PacketCarSetupData_h__
#define __PacketCarSetupData_h__

#include "PacketHeader.h"
#include "CarSetupData.h"

struct PacketCarSetupData
{
    PacketHeader    m_header;            // Header

    CarSetupData    m_carSetups[20];
};

#endif