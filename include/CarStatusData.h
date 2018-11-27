#ifndef __CarStatusData_h__
#define __CarStatusData_h__

#include "types.h"
#include "utils.h"
#include <iostream>

enum FuelMix: uint8_t {
    FUEL_MIX_LEAN = 0,
    FUEL_MIX_STANDARD = 1,
    FUEL_MIX_RICH = 2,
    FUEL_MIX_MAX = 3,
};
static const char * const FuelMix_name[] = {
    "LEAN", "STANDARD", "RICH", "MAX",
};

enum TyreCompound: uint8_t {
    TYRE_COMPOUND_HYPER_SOFT = 0,
    TYRE_COMPOUND_ULTRA_SOFT = 1,
    TYRE_COMPOUND_SUPER_SOFT = 2,
    TYRE_COMPOUND_SOFT = 3,
    TYRE_COMPOUND_MEDIUM = 4,
    TYRE_COMPOUND_HARD = 5,
    TYRE_COMPOUND_SUPER_HARD = 6,
    TYRE_COMPOUND_INTER = 7,
    TYRE_COMPOUND_WET = 8,
};
static const char * const TyreCompound_name[] = {
    "HYPER_SOFT", "ULTRA_SOFT", "SUPER_SOFT", "SOFT", "MEDIUM", "HARD", "SUPER_HARD",
    "INTER", "WET",
};

enum ERSDeploymentMode: uint8_t {
    ERS_DEPLOYMENT_MODE_NONE = 0,
    ERS_DEPLOYMENT_MODE_LOW = 1,
    ERS_DEPLOYMENT_MODE_MEDIUM = 2,
    ERS_DEPLOYMENT_MODE_HIGH = 3,
    ERS_DEPLOYMENT_MODE_OVERTAKE = 4,
    ERS_DEPLOYMENT_MODE_HOTLAP = 5,
};
static const char * const ERSDeploymentMode_name[] = {
    "NONE", "LOW", "MEDIUM", "HIGH", "OVERTAKE", "HOTLAP",
};

struct CarStatusData
{
    uint8_t     m_tractionControl;          // 0 (off) - 2 (high)
    uint8_t     m_antiLockBrakes;           // 0 (off) - 1 (on)
    uint8_t     m_fuelMix;                  // Fuel mix - 0 = lean, 1 = standard, 2 = rich, 3 = max
    uint8_t     m_frontBrakeBias;           // Front brake bias (percentage)
    uint8_t     m_pitLimiterStatus;         // Pit limiter status - 0 = off, 1 = on
    float       m_fuelInTank;               // Current fuel mass
    float       m_fuelCapacity;             // Fuel capacity
    uint16_t    m_maxRPM;                   // Cars max RPM, point of rev limiter
    uint16_t    m_idleRPM;                  // Cars idle RPM
    uint8_t     m_maxGears;                 // Maximum number of gears
    uint8_t     m_drsAllowed;               // 0 = not allowed, 1 = allowed, -1 = unknown
    uint8_t     m_tyresWear[4];             // Tyre wear percentage
    uint8_t     m_tyreCompound;             // Modern - 0 = hyper soft, 1 = ultra soft
                                            // 2 = super soft, 3 = soft, 4 = medium, 5 = hard
                                            // 6 = super hard, 7 = inter, 8 = wet
                                            // Classic - 0-6 = dry, 7-8 = wet
    uint8_t     m_tyresDamage[4];           // Tyre damage (percentage)
    uint8_t     m_frontLeftWingDamage;      // Front left wing damage (percentage)
    uint8_t     m_frontRightWingDamage;     // Front right wing damage (percentage)
    uint8_t     m_rearWingDamage;           // Rear wing damage (percentage)
    uint8_t     m_engineDamage;             // Engine damage (percentage)
    uint8_t     m_gearBoxDamage;            // Gear box damage (percentage)
    uint8_t     m_exhaustDamage;            // Exhaust damage (percentage)
    int8_t      m_vehicleFiaFlags;          // -1 = invalid/unknown, 0 = none, 1 = green
                                            // 2 = blue, 3 = yellow, 4 = red
    float       m_ersStoreEnergy;           // ERS energy store in Joules
    uint8_t     m_ersDeployMode;            // ERS deployment mode, 0 = none, 1 = low, 2 = medium
                                            // 3 = high, 4 = overtake, 5 = hotlap
    float       m_ersHarvestedThisLapMGUK;  // ERS energy harvested this lap by MGU-K
    float       m_ersHarvestedThisLapMGUH;  // ERS energy harvested this lap by MGU-H
    float       m_ersDeployedThisLap;       // ERS energy deployed this lap

    friend std::istream& operator >>(std::istream& is, CarStatusData& data) {
        is.read((char *)&data.m_tractionControl, sizeof(uint8_t));
        is.read((char *)&data.m_antiLockBrakes, sizeof(uint8_t));
        is.read((char *)&data.m_fuelMix, sizeof(uint8_t));
        is.read((char *)&data.m_frontBrakeBias, sizeof(uint8_t));
        is.read((char *)&data.m_pitLimiterStatus, sizeof(uint8_t));
        is.read((char *)&data.m_fuelInTank, sizeof(float));
        is.read((char *)&data.m_fuelCapacity, sizeof(float));
        is.read((char *)&data.m_maxRPM, sizeof(uint16_t));
        is.read((char *)&data.m_idleRPM, sizeof(uint16_t));
        is.read((char *)&data.m_maxGears, sizeof(uint8_t));
        is.read((char *)&data.m_drsAllowed, sizeof(uint8_t));
        is.read((char *)&data.m_tyresWear, sizeof(uint8_t)*4);
        is.read((char *)&data.m_tyreCompound, sizeof(uint8_t));
        is.read((char *)&data.m_tyresDamage, sizeof(uint8_t)*4);
        is.read((char *)&data.m_frontLeftWingDamage, sizeof(uint8_t));
        is.read((char *)&data.m_frontRightWingDamage, sizeof(uint8_t));
        is.read((char *)&data.m_rearWingDamage, sizeof(uint8_t));
        is.read((char *)&data.m_engineDamage, sizeof(uint8_t));
        is.read((char *)&data.m_gearBoxDamage, sizeof(uint8_t));
        is.read((char *)&data.m_exhaustDamage, sizeof(uint8_t));
        is.read((char *)&data.m_vehicleFiaFlags, sizeof(int8_t));
        is.read((char *)&data.m_ersStoreEnergy, sizeof(float));
        is.read((char *)&data.m_ersDeployMode, sizeof(uint8_t));
        is.read((char *)&data.m_ersHarvestedThisLapMGUK, sizeof(float));
        is.read((char *)&data.m_ersHarvestedThisLapMGUH, sizeof(float));
        is.read((char *)&data.m_ersDeployedThisLap, sizeof(float));
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(indent) << "CarStatusData {" << std::endl;
        os << whitespace(indent) << "  m_tractionControl: " << (int)this->m_tractionControl << std::endl;
        os << whitespace(indent) << "  m_antiLockBrakes: " << (int)this->m_antiLockBrakes << std::endl;
        os << whitespace(indent) << "  m_fuelMix: " << FuelMix_name[this->m_fuelMix] << std::endl;
        os << whitespace(indent) << "  m_frontBrakeBias: " << (int)this->m_frontBrakeBias << std::endl;
        os << whitespace(indent) << "  m_pitLimiterStatus: " << (int)this->m_pitLimiterStatus << std::endl;
        os << whitespace(indent) << "  m_fuelInTank: " << this->m_fuelInTank << std::endl;
        os << whitespace(indent) << "  m_fuelCapacity: " << this->m_fuelCapacity << std::endl;
        os << whitespace(indent) << "  m_maxRPM: " << (int)this->m_maxRPM << std::endl;
        os << whitespace(indent) << "  m_idleRPM: " << (int)this->m_idleRPM << std::endl;
        os << whitespace(indent) << "  m_maxGears: " << (int)this->m_maxGears << std::endl;
        os << whitespace(indent) << "  m_drsAllowed: " << (int)this->m_drsAllowed << std::endl;
        os << whitespace(indent) << "  m_tyresWear[4]: ["
            << this->m_tyresWear[0] << ", "
            << this->m_tyresWear[1] << ", "
            << this->m_tyresWear[2] << ", "
            << this->m_tyresWear[3] << "]"
            << std::endl;
        os << whitespace(indent) << "  m_tyreCompound: " << TyreCompound_name[this->m_tyreCompound] << std::endl;
        os << whitespace(indent) << "  m_tyresDamage: ["
            << this->m_tyresDamage[0] << ", "
            << this->m_tyresDamage[1] << ", "
            << this->m_tyresDamage[2] << ", "
            << this->m_tyresDamage[3] << "]"
            << std::endl;
        os << whitespace(indent) << "  m_frontLeftWingDamage: " << (int)this->m_frontLeftWingDamage << std::endl;
        os << whitespace(indent) << "  m_frontRightWingDamage: " << (int)this->m_frontRightWingDamage << std::endl;
        os << whitespace(indent) << "  m_rearWingDamage: " << (int)this->m_rearWingDamage << std::endl;
        os << whitespace(indent) << "  m_engineDamage: " << (int)this->m_engineDamage << std::endl;
        os << whitespace(indent) << "  m_gearBoxDamage: " << (int)this->m_gearBoxDamage << std::endl;
        os << whitespace(indent) << "  m_exhaustDamage: " << (int)this->m_exhaustDamage << std::endl;
        os << whitespace(indent) << "  m_vehicleFiaFlags: " << (int)this->m_vehicleFiaFlags << std::endl;
        os << whitespace(indent) << "  m_ersStoreEnergy: " << this->m_ersStoreEnergy << std::endl;
        os << whitespace(indent) << "  m_ersDeployMode: " << ERSDeploymentMode_name[this->m_ersDeployMode] << std::endl;
        os << whitespace(indent) << "  m_ersHarvestedThisLapMGUK: " << this->m_ersHarvestedThisLapMGUK << std::endl;
        os << whitespace(indent) << "  m_ersHarvestedThisLapMGUH: " << this->m_ersHarvestedThisLapMGUH << std::endl;
        os << whitespace(indent) << "  m_ersDeployedThisLap: " << this->m_ersDeployedThisLap << std::endl;
        os << whitespace(indent) << "}" << std::endl;
    }


};

#endif