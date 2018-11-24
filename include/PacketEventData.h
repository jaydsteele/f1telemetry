#ifndef __PacketEventData_h__
#define __PacketEventData_h__

#include "include/types.h"
#include "include/PacketHeader.h"

struct PacketEventData
{
    PacketHeader    m_header;               // Header
    uint8           m_eventStringCode[4];   // Event string code, see above
};

#endif