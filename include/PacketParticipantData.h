#include "include/types.h"
#include "include/PacketHeader.h"
#include "include/ParticipantData.h"

struct PacketParticipantsData
{
    PacketHeader    m_header;            // Header

    uint8           m_numCars;           // Number of cars in the data
    ParticipantData m_participants[20];
};