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
  };

  int c;
  string inputFilename;
  string outputFilename;
  bool error = false;

  while ((c = getopt_long(argc, argv, "i:o:", longopts, NULL)) != -1) {
    switch(c) {
      case 'i':
        inputFilename = optarg;
        break;
      case 'o':
        outputFilename = optarg;
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
  PacketCarSetupData pCarSetupData;
  PacketCarStatusData pCarStatusData;
  PacketCarTelemetryData pCarTelemetryData;
  PacketLapData pLapData;
  PacketMotionData pMotionData;
  PacketParticipantsData pParticipantsData;
  PacketSessionData pSessionData;
  PacketEventData pEventData;

  while (inFile.good()) {
    inFile >> pHeader;
    // cout << "Packet: " << (int)pHeader.m_packetId << endl;
    pHeader.dump(wcout);
    switch(pHeader.m_packetId) {
      case PACKET_ID_CAR_SETUPS:
        inFile >> pCarSetupData;
        break;
      case PACKET_ID_CAR_STATUS:
        inFile >> pCarStatusData;
        break;
      case PACKET_ID_CAR_TELEMETRY:
        inFile >> pCarTelemetryData;
        break;
      case PACKET_ID_EVENT:
        inFile >> pEventData;
        break;
      case PACKET_ID_LAP_DATA:
        inFile >> pLapData;
        break;
      case PACKET_ID_MOTION:
        inFile >> pMotionData;
        break;
      case PACKET_ID_PARTICIPANTS:
        inFile >> pParticipantsData;
        break;
      case PACKET_ID_SESSION:
        inFile >> pSessionData;
        break;
      default:
        cerr << "Unsupported packet ID: " << (int)pHeader.m_packetId << endl;
        inFile.close();
        outFile.close();
        exit(EXIT_FAILURE);
    }
  }

  // inFile >> pHeader; pHeader.dump(wcout);
  // inFile >> pSessionData; pSessionData.dump(wcout);
  // inFile >> pHeader; pHeader.dump(wcout);
  // inFile >> pParticipantsData; pParticipantsData.dump(wcout);
  // inFile >> pHeader; pHeader.dump(wcout);
  // inFile >> pCarSetupData; pCarSetupData.dump(wcout);
  // inFile >> pHeader; pHeader.dump(wcout);
  // inFile >> pLapData; pLapData.dump(wcout);
  // inFile >> pHeader; pHeader.dump(wcout);
  // inFile >> pMotionData; pMotionData.dump(wcout);
  // inFile >> pHeader; pHeader.dump(wcout);
  // inFile >> pCarTelemetryData; pCarTelemetryData.dump(wcout);
  // inFile >> pHeader; pHeader.dump(wcout);

  return 0;
}

void displayUsage(string programName) {
  cerr << "Usage: " << programName
    << " --input|-i <input-filename>"
    << " --output|-o <output-filename>"
    << endl;
}