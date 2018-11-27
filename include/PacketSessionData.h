#ifndef __PacketSessionData_h__
#define __PacketSessionData_h__

#include "types.h"
#include "MarshallZone.h"
#include "unpack.h"
#include <iostream>

enum Weather: uint8_t {
    CLEAR = 0, LIGHT_CLOUD = 1, OVERCAST = 2, LIGHT_RAIN = 3, HEAVY_RAIN = 4, STORM = 5
};

static const char * const Weather_name[] = {
    "CLEAR", "LIGHT_CLOUD", "OVERCAST", "LIGHT_RAIN", "HEAVY_RAIN", "STORM",
};

enum SessionType: uint8_t {
    UNKNOWN = 0, P1 = 1, P2 = 2, P3 = 3, SHORT_P = 4, Q1 = 5, Q2 = 6, Q3 = 7,
    SHORT_Q = 8, OSQ = 9, R = 10, R2 = 11, TIME_TRIAL = 12
};

static const char * const SessionType_name[] = {
    "UNKNOWN", "P1", "P2", "P3", "SHORT_P", "Q1", "Q2", "Q3", "SHORT_Q", "OSQ",
    "R", "R2", "TIME_TRIAL",
};

enum TrackID: uint8_t {
    MELBOURNE = 0, PAUL_RICARD = 1, SHANGHAI = 2, SAKHIR = 3, CATALUNYA = 4, MONACO = 5,
    MONTREAL = 6, SILVERSTONE = 7, HOCKENHEIM = 8, HUNGARORING = 9, SPA = 10, MONZA = 11,
    SINGAPORE = 12, SUZUKA = 13, ABU_DHABI = 14, TEXAS = 15, BRAZIL = 16, AUSTRIA = 17,
    SOCHI = 18, MEXICO = 19, BAKU = 20, SAKHIR_SHORT = 21, SILVERSTONE_SHORT = 22,
    TEXAS_SHORT = 23, SUZUKA_SHORT = 24
};

static const char * const TrackID_name[] = {
    "MELBOURNE", "PAUL_RICARD", "SHANGHAI", "SAKHIR", "CATALUNYA", "MONACO", "MONTREAL",
    "SILVERSTONE", "HOCKENHEIM", "HUNGARORING", "SPA", "MONZA", "SINGAPORE", "SUZUKA",
    "ABU_DHABI", "TEXAS", "BRAZIL", "AUSTRIA", "SOCHI", "MEXICO", "BAKU", "SAKHIR_SHORT",
    "SILVERSTONE_SHORT", "TEXAS_SHORT", "SUZUKA_SHORT"
};

enum Era: uint8_t {
    MODERN = 0, CLASSIC = 1,
};

static const char * const Era_name[] = {
    "MODERN", "CLASSIC",
};

enum SLIProNativeSupport: uint8_t {
    INACTIVE = 0, ACTIVE = 1,
};

static const char * const SLIProNativeSupport_name[] = {
    "INACTIVE", "ACTIVE",
};

enum SafetyCarStatus: uint8_t {
    NO_SAFETY_CAR = 0, FULL_SAFETY_CAR = 1, VIRTUAL_SAFETY_CAR = 2,
};

static const char * const SafetyCarStatus_name[] = {
    "NO_SAFETY_CAR", "FULL_SAFETY_CAR", "VIRTUAL_SAFETY_CAR"
};

enum NetworkGame: uint8_t {
    OFFLINE = 0, ONLINE = 1,
};

static const char * const NetworkGame_name[] = {
    "OFFLINE", "ONLINE",
};

struct PacketSessionData
{
    static const int SECTION1_BUFFER_SIZE = 19;
    static const int SECTION2_BUFFER_SIZE = 2;

    uint8_t         m_weather;              // Weather - 0 = clear, 1 = light cloud, 2 = overcast
                                            // 3 = light rain, 4 = heavy rain, 5 = storm
    int8_t          m_trackTemperature;    	// Track temp. in degrees celsius
    int8_t          m_airTemperature;      	// Air temp. in degrees celsius
    uint8_t         m_totalLaps;           	// Total number of laps in this race
    uint16_t        m_trackLength;          // Track length in metres
    uint8_t         m_sessionType;         	// 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P
                                            // 5 = Q1, 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ
                                            // 10 = R, 11 = R2, 12 = Time Trial
    int8_t          m_trackId;         		// -1 for unknown, 0-21 for tracks, see appendix
    uint8_t         m_era;                  // Era, 0 = modern, 1 = classic
    uint16_t        m_sessionTimeLeft;    	// Time left in session in seconds
    uint16_t        m_sessionDuration;     	// Session duration in seconds
    uint8_t         m_pitSpeedLimit;      	// Pit speed limit in kilometres per hour
    uint8_t         m_gamePaused;           // Whether the game is paused
    uint8_t         m_isSpectating;        	// Whether the player is spectating
    uint8_t         m_spectatorCarIndex;  	// Index of the car being spectated
    uint8_t         m_sliProNativeSupport;	// SLI Pro support, 0 = inactive, 1 = active
    uint8_t         m_numMarshalZones;      // Number of marshal zones to follow
    MarshalZone     m_marshalZones[21];     // List of marshal zones – max 21
    uint8_t         m_safetyCarStatus;      // 0 = no safety car, 1 = full safety car
                                            // 2 = virtual safety car
    uint8_t        m_networkGame;           // 0 = offline, 1 = online

    friend std::istream& operator >>(std::istream& is, PacketSessionData& data) {
        // first read everything preceeding the marshall zones
        static char buffer1[SECTION1_BUFFER_SIZE];
        is.read(buffer1, sizeof(buffer1));
        if (is.good()) {
            int pos = 0;
            data.m_weather = unpack_uint8(buffer1, pos);
            data.m_trackTemperature = unpack_int8(buffer1, pos+=1);
            data.m_airTemperature = unpack_int8(buffer1, pos+=1);
            data.m_totalLaps = unpack_uint8(buffer1, pos+=1);
            data.m_trackLength = unpack_uint16(buffer1, pos+=1);
            data.m_sessionType = unpack_uint8(buffer1, pos+=2);
            data.m_trackId = unpack_int8(buffer1, pos+=1);
            data.m_era = unpack_uint8(buffer1, pos+=1);
            data.m_sessionTimeLeft = unpack_uint16(buffer1, pos+=1);
            data.m_sessionDuration = unpack_uint16(buffer1, pos+=2);
            data.m_pitSpeedLimit = unpack_uint8(buffer1, pos+=2);
            data.m_gamePaused = unpack_uint8(buffer1, pos+=1);
            data.m_isSpectating = unpack_uint8(buffer1, pos+=1);
            data.m_spectatorCarIndex = unpack_uint8(buffer1, pos+=1);
            data.m_sliProNativeSupport = unpack_uint8(buffer1, pos+=1);
            data.m_numMarshalZones = unpack_uint8(buffer1, pos+=1);
        }
        for (int i=0; i<21; i++) {
            is >> data.m_marshalZones[i];
        }
        static char buffer2[SECTION2_BUFFER_SIZE];
        is.read(buffer2, sizeof(buffer2));
        if (is.good()) {
            int pos = 0;
            data.m_safetyCarStatus = unpack_uint8(buffer2, pos);
            data.m_networkGame = unpack_uint8(buffer2, pos+=1);
        }
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(indent) << "PacketSessionData {" << std::endl;
        os << whitespace(indent) << "  m_weather: " << Weather_name[this->m_weather] << std::endl;
        os << whitespace(indent) << "  m_trackTemperature: " << (int)this->m_trackTemperature << std::endl;
        os << whitespace(indent) << "  m_airTemperature: " << (int)this->m_airTemperature << std::endl;
        os << whitespace(indent) << "  m_totalLaps: " << (int)this->m_totalLaps << std::endl;
        os << whitespace(indent) << "  m_trackLength: " << this->m_trackLength << std::endl;
        os << whitespace(indent) << "  m_sessionType: " << SessionType_name[this->m_sessionType] << std::endl;
        os << whitespace(indent) << "  m_trackId: " << TrackID_name[this->m_trackId] << std::endl;
        os << whitespace(indent) << "  m_era: " << Era_name[this->m_era] << std::endl;
        os << whitespace(indent) << "  m_sessionTimeLeft: " << this->m_sessionTimeLeft << std::endl;
        os << whitespace(indent) << "  m_sessionDuration: " << this->m_sessionDuration << std::endl;
        os << whitespace(indent) << "  m_pitSpeedLimit: " << (int)this->m_pitSpeedLimit << std::endl;
        os << whitespace(indent) << "  m_gamePaused: " << (int)this->m_gamePaused << std::endl;
        os << whitespace(indent) << "  m_isSpectating: " << (int)this->m_isSpectating << std::endl;
        os << whitespace(indent) << "  m_spectatorCarIndex: " << (int)this->m_spectatorCarIndex << std::endl;
        os << whitespace(indent) << "  m_sliProNativeSupport: " << SLIProNativeSupport_name[this->m_sliProNativeSupport] << std::endl;
        os << whitespace(indent) << "  m_numMarshalZones: " << (int)this->m_numMarshalZones << std::endl;
        for (int i=0; i<this->m_numMarshalZones; i++) {
            m_marshalZones[i].dump(os, indent+2);
        }
        os << whitespace(indent) << "  m_safetyCarStatus: " << SafetyCarStatus_name[this->m_safetyCarStatus] << std::endl;
        os << whitespace(indent) << "  m_networkGame: " << NetworkGame_name[this->m_networkGame] << std::endl;
        os << whitespace(indent) << "}" << std::endl;
    }

};

#endif