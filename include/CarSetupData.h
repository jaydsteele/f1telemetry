#ifndef __CarSetupData_h__
#define __CarSetupData_h__

#include "types.h"
#include "utils.h"
#include <iostream>

struct CarSetupData
{
    uint8_t   m_frontWing;                // Front wing aero
    uint8_t   m_rearWing;                 // Rear wing aero
    uint8_t   m_onThrottle;               // Differential adjustment on throttle (percentage)
    uint8_t   m_offThrottle;              // Differential adjustment off throttle (percentage)
    float     m_frontCamber;              // Front camber angle (suspension geometry)
    float     m_rearCamber;               // Rear camber angle (suspension geometry)
    float     m_frontToe;                 // Front toe angle (suspension geometry)
    float     m_rearToe;                  // Rear toe angle (suspension geometry)
    uint8_t   m_frontSuspension;          // Front suspension
    uint8_t   m_rearSuspension;           // Rear suspension
    uint8_t   m_frontAntiRollBar;         // Front anti-roll bar
    uint8_t   m_rearAntiRollBar;          // Front anti-roll bar
    uint8_t   m_frontSuspensionHeight;    // Front ride height
    uint8_t   m_rearSuspensionHeight;     // Rear ride height
    uint8_t   m_brakePressure;            // Brake pressure (percentage)
    uint8_t   m_brakeBias;                // Brake bias (percentage)
    float     m_frontTyrePressure;        // Front tyre pressure (PSI)
    float     m_rearTyrePressure;         // Rear tyre pressure (PSI)
    uint8_t   m_ballast;                  // Ballast
    float     m_fuelLoad;                 // Fuel load

    friend std::istream& operator >>(std::istream& is, CarSetupData& data) {
        is.read((char *)&data.m_frontWing, sizeof(uint8_t));
        is.read((char *)&data.m_rearWing, sizeof(uint8_t));
        is.read((char *)&data.m_onThrottle, sizeof(uint8_t));
        is.read((char *)&data.m_offThrottle, sizeof(uint8_t));
        is.read((char *)&data.m_frontCamber, sizeof(float));
        is.read((char *)&data.m_rearCamber, sizeof(float));
        is.read((char *)&data.m_frontToe, sizeof(float));
        is.read((char *)&data.m_rearToe, sizeof(float));
        is.read((char *)&data.m_frontSuspension, sizeof(uint8_t));
        is.read((char *)&data.m_rearSuspension, sizeof(uint8_t));
        is.read((char *)&data.m_frontAntiRollBar, sizeof(uint8_t));
        is.read((char *)&data.m_rearAntiRollBar, sizeof(uint8_t));
        is.read((char *)&data.m_frontSuspensionHeight, sizeof(uint8_t));
        is.read((char *)&data.m_rearSuspensionHeight, sizeof(uint8_t));
        is.read((char *)&data.m_brakePressure, sizeof(uint8_t));
        is.read((char *)&data.m_brakeBias, sizeof(uint8_t));
        is.read((char *)&data.m_frontTyrePressure, sizeof(float));
        is.read((char *)&data.m_rearTyrePressure, sizeof(float));
        is.read((char *)&data.m_ballast, sizeof(uint8_t));
        is.read((char *)&data.m_fuelLoad, sizeof(float));
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(indent) << "CarSetupData {" << std::endl;
        os << whitespace(indent) << "  m_frontWing:" << (int)this->m_frontWing << std::endl;
        os << whitespace(indent) << "  m_rearWing:" << (int)this->m_rearWing << std::endl;
        os << whitespace(indent) << "  m_onThrottle:" << (int)this->m_onThrottle << std::endl;
        os << whitespace(indent) << "  m_offThrottle:" << (int)this->m_offThrottle << std::endl;
        os << whitespace(indent) << "  m_frontCamber:" << (float)this->m_frontCamber << std::endl;
        os << whitespace(indent) << "  m_rearCamber:" << (float)this->m_rearCamber << std::endl;
        os << whitespace(indent) << "  m_frontToe:" << (float)this->m_frontToe << std::endl;
        os << whitespace(indent) << "  m_rearToe:" << (float)this->m_rearToe << std::endl;
        os << whitespace(indent) << "  m_frontSuspension:" << (int)this->m_frontSuspension << std::endl;
        os << whitespace(indent) << "  m_rearSuspension:" << (int)this->m_rearSuspension << std::endl;
        os << whitespace(indent) << "  m_frontAntiRollBar:" << (int)this->m_frontAntiRollBar << std::endl;
        os << whitespace(indent) << "  m_rearAntiRollBar:" << (int)this->m_rearAntiRollBar << std::endl;
        os << whitespace(indent) << "  m_frontSuspensionHeight:" << (int)this->m_frontSuspensionHeight << std::endl;
        os << whitespace(indent) << "  m_rearSuspensionHeight:" << (int)this->m_rearSuspensionHeight << std::endl;
        os << whitespace(indent) << "  m_brakePressure:" << (int)this->m_brakePressure << std::endl;
        os << whitespace(indent) << "  m_brakeBias:" << (int)this->m_brakeBias << std::endl;
        os << whitespace(indent) << "  m_frontTyrePressure:" << (float)this->m_frontTyrePressure << std::endl;
        os << whitespace(indent) << "  m_rearTyrePressure:" << (float)this->m_rearTyrePressure << std::endl;
        os << whitespace(indent) << "  m_ballast:" << (int)this->m_ballast << std::endl;
        os << whitespace(indent) << "  m_fuelLoad:" << (float)this->m_fuelLoad << std::endl;
        os << whitespace(indent) << "}" << std::endl;
    }

};

#endif