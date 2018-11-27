#ifndef __LapData_h__
#define __LapData_h__

#include "types.h"

enum PitStatus: uint8_t {
    PIT_STATUS_NONE = 0,
    PIT_STATUS_PITTING = 1,
    PIT_STATUS_IN_PIT_AREA = 2,
};

static const char* const PitStatus_name[] = {
    "NONE", "PITTING", "IN_PIT_AREA",
};

enum DriverStatus: uint8_t {
    DRIVER_STATUS_IN_GARAGE = 0,
    DRIVER_STATUS_FLYING_LAP = 1,
    DRIVER_STATUS_IN_LAP = 2,
    DRIVER_STATUS_OUT_LAP = 3,
    DRIVER_STATUS_ON_TRACK = 4,
};
static const char* const DriverStatus_name[] = {
    "IN_GARAGE", "FLYING_LAP", "IN_LAP", "OUT_LAP", "ON_TRACK",
};

enum ResultStatus: uint8_t {
    RESULT_STATUS_INVALID = 0,
    RESULT_STATUS_INACTIVE = 1,
    RESULT_STATUS_ACTIVE = 2,
    RESULT_STATUS_FINISHED = 3,
    RESULT_STATUS_DISQUALIFIED = 4,
    RESULT_STATUS_NOT_CLASSIFIED = 5,
    RESULT_STATUS_RETIRED = 6,
};
static const char* const ResultStatus_name[] = {
    "INVALID", "INACTIVE", "ACTIVE", "FINISHED", "DISQUALIFIED",
    "NOT_CLASSIFIED", "RETIRED",
};


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

    friend std::istream& operator >>(std::istream& is, LapData& data) {
        is.read((char *)&data.m_lastLapTime, sizeof(float));
        is.read((char *)&data.m_currentLapTime, sizeof(float));
        is.read((char *)&data.m_bestLapTime, sizeof(float));
        is.read((char *)&data.m_sector1Time, sizeof(float));
        is.read((char *)&data.m_sector2Time, sizeof(float));
        is.read((char *)&data.m_lapDistance, sizeof(float));
        is.read((char *)&data.m_totalDistance, sizeof(float));
        is.read((char *)&data.m_safetyCarDelta, sizeof(float));
        is.read((char *)&data.m_carPosition, sizeof(uint8_t));
        is.read((char *)&data.m_currentLapNum, sizeof(uint8_t));
        is.read((char *)&data.m_pitStatus, sizeof(uint8_t));
        is.read((char *)&data.m_sector, sizeof(uint8_t));
        is.read((char *)&data.m_currentLapInvalid, sizeof(uint8_t));
        is.read((char *)&data.m_penalties, sizeof(uint8_t));
        is.read((char *)&data.m_gridPosition, sizeof(uint8_t));
        is.read((char *)&data.m_driverStatus, sizeof(uint8_t));
        is.read((char *)&data.m_resultStatus, sizeof(uint8_t));
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(indent) << "LapData {" << std::endl;
        os << whitespace(indent) << "  m_lastLapTime: " << (float)this->m_lastLapTime << std::endl;
        os << whitespace(indent) << "  m_currentLapTime: " << (float)this->m_currentLapTime << std::endl;
        os << whitespace(indent) << "  m_bestLapTime: " << (float)this->m_bestLapTime << std::endl;
        os << whitespace(indent) << "  m_sector1Time: " << (float)this->m_sector1Time << std::endl;
        os << whitespace(indent) << "  m_sector2Time: " << (float)this->m_sector2Time << std::endl;
        os << whitespace(indent) << "  m_lapDistance: " << (float)this->m_lapDistance << std::endl;
        os << whitespace(indent) << "  m_totalDistance: " << (float)this->m_totalDistance << std::endl;
        os << whitespace(indent) << "  m_safetyCarDelta: " << (float)this->m_safetyCarDelta << std::endl;

        os << whitespace(indent) << "  m_carPosition: " << (int)this->m_carPosition << std::endl;
        os << whitespace(indent) << "  m_currentLapNum: " << (int)this->m_currentLapNum << std::endl;
        os << whitespace(indent) << "  m_pitStatus: " << PitStatus_name[this->m_pitStatus] << std::endl;
        os << whitespace(indent) << "  m_sector: " << (int)this->m_sector << std::endl;
        os << whitespace(indent) << "  m_currentLapInvalid: " << (int)this->m_currentLapInvalid << std::endl;
        os << whitespace(indent) << "  m_penalties: " << (int)this->m_penalties << std::endl;
        os << whitespace(indent) << "  m_gridPosition: " << (int)this->m_gridPosition << std::endl;
        os << whitespace(indent) << "  m_driverStatus: " << DriverStatus_name[this->m_driverStatus] << std::endl;
        os << whitespace(indent) << "  m_resultStatus: " << ResultStatus_name[this->m_resultStatus] << std::endl;
        os << whitespace(indent) << "}" << std::endl;
    }

};

#endif