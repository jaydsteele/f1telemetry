#ifndef __CarTelemetryData_h__
#define __CarTelemetryData_h__

#include "types.h"

struct CarTelemetryData
{
    uint16_t  m_speed;                      // Speed of car in kilometres per hour
    uint8_t   m_throttle;                   // Amount of throttle applied (0 to 100)
    int8_t    m_steer;                      // Steering (-100 (full lock left) to 100 (full lock right))
    uint8_t   m_brake;                      // Amount of brake applied (0 to 100)
    uint8_t   m_clutch;                     // Amount of clutch applied (0 to 100)
    int8_t    m_gear;                       // Gear selected (1-8, N=0, R=-1)
    uint16_t  m_engineRPM;                  // Engine RPM
    uint8_t   m_drs;                        // 0 = off, 1 = on
    uint8_t   m_revLightsPercent;           // Rev lights indicator (percentage)
    uint16_t  m_brakesTemperature[4];       // Brakes temperature (celsius)
    uint16_t  m_tyresSurfaceTemperature[4]; // Tyres surface temperature (celsius)
    uint16_t  m_tyresInnerTemperature[4];   // Tyres inner temperature (celsius)
    uint16_t  m_engineTemperature;          // Engine temperature (celsius)
    float     m_tyresPressure[4];           // Tyres pressure (PSI)

    friend std::istream& operator >>(std::istream& is, CarTelemetryData& data) {
        is.read((char *)&data.m_speed, sizeof(uint16_t));
        is.read((char *)&data.m_throttle, sizeof(uint8_t));
        is.read((char *)&data.m_steer, sizeof(int8_t));
        is.read((char *)&data.m_brake, sizeof(uint8_t));
        is.read((char *)&data.m_clutch, sizeof(uint8_t));
        is.read((char *)&data.m_gear, sizeof(int8_t));
        is.read((char *)&data.m_engineRPM, sizeof(uint16_t));
        is.read((char *)&data.m_drs, sizeof(uint8_t));
        is.read((char *)&data.m_revLightsPercent, sizeof(uint8_t));
        is.read((char *)&data.m_brakesTemperature, sizeof(uint16_t)*4);
        is.read((char *)&data.m_tyresSurfaceTemperature, sizeof(uint16_t)*4);
        is.read((char *)&data.m_tyresInnerTemperature, sizeof(uint16_t)*4);
        is.read((char *)&data.m_engineTemperature, sizeof(uint16_t));
        is.read((char *)&data.m_tyresPressure, sizeof(float)*4);
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(indent) << "CarTelemetryData {" << std::endl;
        os << whitespace(indent) << "  m_speed: " << (int)this->m_speed << std::endl;
        os << whitespace(indent) << "  m_throttle: " << (int)this->m_throttle << std::endl;
        os << whitespace(indent) << "  m_steer: " << (int)this->m_steer << std::endl;
        os << whitespace(indent) << "  m_brake: " << (int)this->m_brake << std::endl;
        os << whitespace(indent) << "  m_clutch: " << (int)this->m_clutch << std::endl;
        os << whitespace(indent) << "  m_gear: " << (int)this->m_gear << std::endl;
        os << whitespace(indent) << "  m_engineRPM: " << (int)this->m_engineRPM << std::endl;
        os << whitespace(indent) << "  m_drs: " << (int)this->m_drs << std::endl;
        os << whitespace(indent) << "  m_revLightsPercent: " << (int)this->m_revLightsPercent << std::endl;
        os << whitespace(indent) << "  m_brakesTemperature: ["
            << (int)this->m_brakesTemperature[0] << ", "
            << (int)this->m_brakesTemperature[1] << ", "
            << (int)this->m_brakesTemperature[2] << ", "
            << (int)this->m_brakesTemperature[3] << "]"
            << std::endl;
        os << whitespace(indent) << "  m_tyresSurfaceTemperature: ["
            << (int)this->m_tyresSurfaceTemperature[0] << ", "
            << (int)this->m_tyresSurfaceTemperature[1] << ", "
            << (int)this->m_tyresSurfaceTemperature[2] << ", "
            << (int)this->m_tyresSurfaceTemperature[3] << "]"
            << std::endl;
        os << whitespace(indent) << "  m_tyresInnerTemperature: ["
            << (int)this->m_tyresInnerTemperature[0] << ", "
            << (int)this->m_tyresInnerTemperature[1] << ", "
            << (int)this->m_tyresInnerTemperature[2] << ", "
            << (int)this->m_tyresInnerTemperature[3] << "]"
            << std::endl;
        os << whitespace(indent) << "  m_engineTemperature: " << (int)this->m_engineTemperature << std::endl;
        os << whitespace(indent) << "  m_tyresPressure: ["
            << this->m_tyresPressure[0] << ", "
            << this->m_tyresPressure[1] << ", "
            << this->m_tyresPressure[2] << ", "
            << this->m_tyresPressure[3] << "]"
            << std::endl;
        os << whitespace(indent) << "}" << std::endl;
    }

};

#endif