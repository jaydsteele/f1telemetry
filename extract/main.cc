#include "include/f1telemetry.h"
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>

using namespace std;

void displayUsage(string programName);

int main(int argc, char** argv) {

  static struct option longopts[] = {
    { "input", required_argument, 0, 'i' },
    { "output", required_argument, 0, 'o' },
    { "verbose", no_argument, 0, 'v' },
  };

  int c;
  string inputFilename;
  string outputFilename;
  bool error = false;
  bool verbose = false;

  while ((c = getopt_long(argc, argv, "i:o:v", longopts, NULL)) != -1) {
    switch(c) {
      case 'i':
        inputFilename = optarg;
        break;
      case 'o':
        outputFilename = optarg;
        break;
      case 'v':
        verbose = true;
        break;
    }
  }

  if (inputFilename.length() == 0) {
    cerr << "Error: No input filename provided" << endl;
    error = true;
  }

  if (outputFilename.length() == 0) {
    cerr << "Error: No output filename provided" << endl;
    error = true;
  }

  ifstream inFile;
  inFile.open(inputFilename, ios::in);
  if (!inFile.is_open()) {
    cerr << "Error: Could not open " << inputFilename << endl;
    error = true;
  }

  ofstream outFile;
  outFile.open(outputFilename, ios::out);
  if (!outFile.is_open()) {
    cerr << "Error: Could not open " << outputFilename << endl;
    error = true;
  }

  if (error) {
    displayUsage(argv[0]);
    exit(EXIT_FAILURE);
  }

  PacketHeader pHeader;
  PacketParticipantsData pParticipantsData;
  PacketCarSetupData pCarSetupData;
  PacketCarStatusData pCarStatusData;
  PacketCarTelemetryData pCarTelemetryData;
  PacketLapData pLapData;
  PacketMotionData pMotionData;
  PacketSessionData pSessionData;
  PacketEventData pEventData;

  outFile << "time,speed,throttle,steer,brake,clutch,gear,engineRPM,drs,revLightsPercent,brakesTemp0,brakesTemp1,brakesTemp2,brakesTemp3,tyreSurfaceTemp0,tyreSurfaceTemp1,tyreSurfaceTemp2,tyreSurfaceTemp3,tyreInnerTemp0,tyreInnerTemp1,tyreInnerTemp2,tyreInnerTemp3,engineTemp,tyrePressure0,tyrePressure1,tyrePressure2,tyrePressure3" << endl;

  CarTelemetryData* car;

  while (inFile.good()) {
    inFile >> pHeader;
    if (verbose) pHeader.dump(wcout);
    switch(pHeader.m_packetId) {
      case PACKET_ID_CAR_SETUPS:
        inFile >> pCarSetupData;
        if (verbose) pCarSetupData.dump(wcout);
        break;
      case PACKET_ID_CAR_STATUS:
        inFile >> pCarStatusData;
        if (verbose) pCarStatusData.dump(wcout);
        break;
      case PACKET_ID_CAR_TELEMETRY:
        inFile >> pCarTelemetryData;
        if (verbose) pCarTelemetryData.dump(wcout);
        car = &pCarTelemetryData.m_carTelemetryData[pHeader.m_playerCarIndex];
        outFile << pHeader.m_sessionTime;
        outFile << "," << (int)car->m_speed;
        outFile << "," << (int)car->m_throttle;
        outFile << "," << (int)car->m_steer;
        outFile << "," << (int)car->m_brake;
        outFile << "," << (int)car->m_clutch;
        outFile << "," << (int)car->m_gear;
        outFile << "," << (int)car->m_engineRPM;
        outFile << "," << (int)car->m_drs;
        outFile << "," << (int)car->m_revLightsPercent;
        outFile << "," << (int)car->m_brakesTemperature[0];
        outFile << "," << (int)car->m_brakesTemperature[1];
        outFile << "," << (int)car->m_brakesTemperature[2];
        outFile << "," << (int)car->m_brakesTemperature[3];
        outFile << "," << (int)car->m_tyresSurfaceTemperature[0];
        outFile << "," << (int)car->m_tyresSurfaceTemperature[1];
        outFile << "," << (int)car->m_tyresSurfaceTemperature[2];
        outFile << "," << (int)car->m_tyresSurfaceTemperature[3];
        outFile << "," << (int)car->m_tyresInnerTemperature[0];
        outFile << "," << (int)car->m_tyresInnerTemperature[1];
        outFile << "," << (int)car->m_tyresInnerTemperature[2];
        outFile << "," << (int)car->m_tyresInnerTemperature[3];
        outFile << "," << (int)car->m_engineTemperature;
        outFile << "," << (float)car->m_tyresPressure[0];
        outFile << "," << (float)car->m_tyresPressure[1];
        outFile << "," << (float)car->m_tyresPressure[2];
        outFile << "," << (float)car->m_tyresPressure[3];
        outFile << endl;
        break;
      case PACKET_ID_EVENT:
        inFile >> pEventData;
        if (verbose) pEventData.dump(wcout);
        break;
      case PACKET_ID_LAP_DATA:
        inFile >> pLapData;
        if (verbose) pLapData.dump(wcout);
        break;
      case PACKET_ID_MOTION:
        inFile >> pMotionData;
        if (verbose) pMotionData.dump(wcout);
        break;
      case PACKET_ID_PARTICIPANTS:
        inFile >> pParticipantsData;
        if (verbose) pParticipantsData.dump(wcout);
        break;
      case PACKET_ID_SESSION:
        inFile >> pSessionData;
        if (verbose) pSessionData.dump(wcout);
        break;
      default:
        cerr << "Unsupported packet ID: " << (int)pHeader.m_packetId << endl;
        inFile.close();
        outFile.close();
        exit(EXIT_FAILURE);
    }
  }

  return 0;
}

void displayUsage(string programName) {
  cerr << "Usage: " << programName
    << " --input|-i <input-filename>"
    << " --output|-o <output-filename>"
    << " --verbose|-v"
    << endl;
}
