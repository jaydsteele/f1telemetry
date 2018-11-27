#ifndef __CarMotionData_h__
#define __CarMotionData_h__

#include "types.h"
#include "utils.h"
#include <iostream>

struct CarMotionData
{
    float         m_worldPositionX;           // World space X position
    float         m_worldPositionY;           // World space Y position
    float         m_worldPositionZ;           // World space Z position
    float         m_worldVelocityX;           // Velocity in world space X
    float         m_worldVelocityY;           // Velocity in world space Y
    float         m_worldVelocityZ;           // Velocity in world space Z
    int16_t       m_worldForwardDirX;         // World space forward X direction (normalised)
    int16_t       m_worldForwardDirY;         // World space forward Y direction (normalised)
    int16_t       m_worldForwardDirZ;         // World space forward Z direction (normalised)
    int16_t       m_worldRightDirX;           // World space right X direction (normalised)
    int16_t       m_worldRightDirY;           // World space right Y direction (normalised)
    int16_t       m_worldRightDirZ;           // World space right Z direction (normalised)
    float         m_gForceLateral;            // Lateral G-Force component
    float         m_gForceLongitudinal;       // Longitudinal G-Force component
    float         m_gForceVertical;           // Vertical G-Force component
    float         m_yaw;                      // Yaw angle in radians
    float         m_pitch;                    // Pitch angle in radians
    float         m_roll;                     // Roll angle in radians

    friend std::istream& operator >>(std::istream& is, CarMotionData& data) {
        is.read((char *)&data.m_worldPositionX, sizeof(float));
        is.read((char *)&data.m_worldPositionY, sizeof(float));
        is.read((char *)&data.m_worldPositionZ, sizeof(float));
        is.read((char *)&data.m_worldVelocityX, sizeof(float));
        is.read((char *)&data.m_worldVelocityY, sizeof(float));
        is.read((char *)&data.m_worldVelocityZ, sizeof(float));
        is.read((char *)&data.m_worldForwardDirX, sizeof(int16_t));
        is.read((char *)&data.m_worldForwardDirY, sizeof(int16_t));
        is.read((char *)&data.m_worldForwardDirZ, sizeof(int16_t));
        is.read((char *)&data.m_worldRightDirX, sizeof(int16_t));
        is.read((char *)&data.m_worldRightDirY, sizeof(int16_t));
        is.read((char *)&data.m_worldRightDirZ, sizeof(int16_t));
        is.read((char *)&data.m_gForceLateral, sizeof(float));
        is.read((char *)&data.m_gForceLongitudinal, sizeof(float));
        is.read((char *)&data.m_gForceVertical, sizeof(float));
        is.read((char *)&data.m_yaw, sizeof(float));
        is.read((char *)&data.m_pitch, sizeof(float));
        is.read((char *)&data.m_roll, sizeof(float));
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(indent) << "CarMotionData {" << std::endl;
        os << whitespace(indent) << "  m_worldPositionX: " << this->m_worldPositionX << std::endl;
        os << whitespace(indent) << "  m_worldPositionY: " << this->m_worldPositionY << std::endl;
        os << whitespace(indent) << "  m_worldPositionZ: " << this->m_worldPositionZ << std::endl;

        os << whitespace(indent) << "  m_worldVelocityX: " << this->m_worldVelocityX << std::endl;
        os << whitespace(indent) << "  m_worldVelocityY: " << this->m_worldVelocityY << std::endl;
        os << whitespace(indent) << "  m_worldVelocityZ: " << this->m_worldVelocityZ << std::endl;

        os << whitespace(indent) << "  m_worldForwardDirX: " << (int)this->m_worldForwardDirX << std::endl;
        os << whitespace(indent) << "  m_worldForwardDirY: " << (int)this->m_worldForwardDirY << std::endl;
        os << whitespace(indent) << "  m_worldForwardDirZ: " << (int)this->m_worldForwardDirZ << std::endl;

        os << whitespace(indent) << "  m_worldRightDirX: " << (int)this->m_worldRightDirX << std::endl;
        os << whitespace(indent) << "  m_worldRightDirY: " << (int)this->m_worldRightDirY << std::endl;
        os << whitespace(indent) << "  m_worldRightDirZ: " << (int)this->m_worldRightDirZ << std::endl;

        os << whitespace(indent) << "  m_gForceLateral: " << this->m_gForceLateral << std::endl;
        os << whitespace(indent) << "  m_gForceLongitudinal: " << this->m_gForceLongitudinal << std::endl;
        os << whitespace(indent) << "  m_gForceVertical: " << this->m_gForceVertical << std::endl;
        os << whitespace(indent) << "  m_yaw: " << this->m_yaw << std::endl;
        os << whitespace(indent) << "  m_pitch: " << this->m_pitch << std::endl;
        os << whitespace(indent) << "  m_roll: " << this->m_roll << std::endl;

        os << whitespace(indent) << "}" << std::endl;
    }

};

#endif