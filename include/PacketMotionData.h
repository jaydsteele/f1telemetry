#ifndef __PacketMotionData_h__
#define __PacketMotionData_h__

#include "PacketHeader.h"
#include "CarMotionData.h"

struct PacketMotionData
{
    CarMotionData   m_carMotionData[20];    // Data for all cars on track

    // Extra player car ONLY data
    float         m_suspensionPosition[4];       // Note: All wheel arrays have the following order:
    float         m_suspensionVelocity[4];       // RL, RR, FL, FR
    float         m_suspensionAcceleration[4];   // RL, RR, FL, FR
    float         m_wheelSpeed[4];               // Speed of each wheel
    float         m_wheelSlip[4];                // Slip ratio for each wheel
    float         m_localVelocityX;              // Velocity in local space
    float         m_localVelocityY;              // Velocity in local space
    float         m_localVelocityZ;              // Velocity in local space
    float         m_angularVelocityX;            // Angular velocity x-component
    float         m_angularVelocityY;            // Angular velocity y-component
    float         m_angularVelocityZ;            // Angular velocity z-component
    float         m_angularAccelerationX;        // Angular velocity x-component
    float         m_angularAccelerationY;        // Angular velocity y-component
    float         m_angularAccelerationZ;        // Angular velocity z-component
    float         m_frontWheelsAngle;            // Current front wheels angle in radians

    friend std::istream& operator >>(std::istream& is, PacketMotionData& data) {
        for (int i=0; i<20; i++) {
            is >> data.m_carMotionData[i];
        }
        is.read((char *)&data.m_suspensionPosition, sizeof(float)*4);
        is.read((char *)&data.m_suspensionVelocity, sizeof(float)*4);
        is.read((char *)&data.m_suspensionAcceleration, sizeof(float)*4);
        is.read((char *)&data.m_wheelSpeed, sizeof(float)*4);
        is.read((char *)&data.m_wheelSlip, sizeof(float)*4);
        is.read((char *)&data.m_localVelocityX, sizeof(float));
        is.read((char *)&data.m_localVelocityY, sizeof(float));
        is.read((char *)&data.m_localVelocityZ, sizeof(float));
        is.read((char *)&data.m_angularVelocityX, sizeof(float));
        is.read((char *)&data.m_angularVelocityY, sizeof(float));
        is.read((char *)&data.m_angularVelocityZ, sizeof(float));
        is.read((char *)&data.m_angularAccelerationX, sizeof(float));
        is.read((char *)&data.m_angularAccelerationY, sizeof(float));
        is.read((char *)&data.m_angularAccelerationZ, sizeof(float));
        is.read((char *)&data.m_frontWheelsAngle, sizeof(float));
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        os << whitespace(indent) << "PacketMotionData {" << std::endl;
        for (int i=0; i<20; i++) {
            this->m_carMotionData[i].dump(os, indent+2);
        }
        os << whitespace(indent) << "  m_suspensionPosition: " << "["
            << this->m_suspensionPosition[0] << ", "
            << this->m_suspensionPosition[1] << ", "
            << this->m_suspensionPosition[2] << ", "
            << this->m_suspensionPosition[3] << "]"
            << std::endl;

        os << whitespace(indent) << "  m_suspensionVelocity: " << "["
            << this->m_suspensionVelocity[0] << ", "
            << this->m_suspensionVelocity[1] << ", "
            << this->m_suspensionVelocity[2] << ", "
            << this->m_suspensionVelocity[3] << "]"
            << std::endl;

        os << whitespace(indent) << "  m_suspensionAcceleration: " << "["
            << this->m_suspensionAcceleration[0] << ", "
            << this->m_suspensionAcceleration[1] << ", "
            << this->m_suspensionAcceleration[2] << ", "
            << this->m_suspensionAcceleration[3] << "]"
            << std::endl;

        os << whitespace(indent) << "  m_wheelSpeed: " << "["
            << this->m_wheelSpeed[0] << ", "
            << this->m_wheelSpeed[1] << ", "
            << this->m_wheelSpeed[2] << ", "
            << this->m_wheelSpeed[3] << "]"
            << std::endl;

        os << whitespace(indent) << "  m_wheelSlip: " << "["
            << this->m_wheelSlip[0] << ", "
            << this->m_wheelSlip[1] << ", "
            << this->m_wheelSlip[2] << ", "
            << this->m_wheelSlip[3] << "]"
            << std::endl;

        os << whitespace(indent) << "  m_localVelocityX: " << this->m_localVelocityX << std::endl;
        os << whitespace(indent) << "  m_localVelocityY: " << this->m_localVelocityY << std::endl;
        os << whitespace(indent) << "  m_localVelocityZ: " << this->m_localVelocityZ << std::endl;

        os << whitespace(indent) << "  m_angularVelocityX: " << this->m_angularVelocityX << std::endl;
        os << whitespace(indent) << "  m_angularVelocityY: " << this->m_angularVelocityY << std::endl;
        os << whitespace(indent) << "  m_angularVelocityZ: " << this->m_angularVelocityZ << std::endl;

        os << whitespace(indent) << "  m_angularAccelerationX: " << this->m_angularAccelerationX << std::endl;
        os << whitespace(indent) << "  m_angularAccelerationY: " << this->m_angularAccelerationY << std::endl;
        os << whitespace(indent) << "  m_angularAccelerationZ: " << this->m_angularAccelerationZ << std::endl;

        os << whitespace(indent) << "}" << std::endl;
    }

};

#endif