#ifndef __LapData_h__
#define __LapData_h__

#include "include/types.h"

struct LapData
{
    float       m_lastLapTime;           // Last lap time in seconds
    float       m_currentLapTime;        // Current time around the lap in seconds
    float       m_bestLapTime;           // Best lap time of the session in seconds
    float       m_sector1Time;           // Sector 1 time in seconds
    float       m_sector2Time;           // Sector 2 time in seconds
    float       m_lapDistance;           // Distance vehicle is around current lap in metres – could
                                         // be negative if line hasn’t been crossed yet
    float       m_totalDistance;         // Total distance travelled in session in metres – could
                                         // be negative if line hasn’t been crossed yet
    float       m_safetyCarDelta;        // Delta in seconds for safety car
    uint8_t     m_carPosition;           // Car race position
    uint8_t     m_currentLapNum;         // Current lap number
    uint8_t     m_pitStatus;             // 0 = none, 1 = pitting, 2 = in pit area
    uint8_t     m_sector;                // 0 = sector1, 1 = sector2, 2 = sector3
    uint8_t     m_currentLapInvalid;     // Current lap invalid - 0 = valid, 1 = invalid
    uint8_t     m_penalties;             // Accumulated time penalties in seconds to be added
    uint8_t     m_gridPosition;          // Grid position the vehicle started the race in
    uint8_t     m_driverStatus;          // Status of driver - 0 = in garage, 1 = flying lap
                                         // 2 = in lap, 3 = out lap, 4 = on track
    uint8_t     m_resultStatus;          // Result status - 0 = invalid, 1 = inactive, 2 = active
                                         // 3 = finished, 4 = disqualified, 5 = not classified
                                         // 6 = retired
};

#endif