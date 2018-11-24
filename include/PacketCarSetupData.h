#include "include/PacketHeader.h"
#include "include/CarSetupData.h"

struct PacketCarSetupData
{
    PacketHeader    m_header;            // Header

    CarSetupData    m_carSetups[20];
};