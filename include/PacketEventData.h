#ifndef __PacketEventData_h__
#define __PacketEventData_h__

#include "types.h"
#include "PacketHeader.h"

struct PacketEventData
{
    PacketHeader    m_header;               // Header
    uint8_t         m_eventStringCode[4];   // Event string code, see above
};

#endif