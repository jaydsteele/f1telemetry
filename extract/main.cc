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

  PacketHeader packetHeader;
  PacketSessionData sessionData;
  PacketParticipantsData packetParticipantsData;

  inFile >> packetHeader;
  packetHeader.dump(wcout);

  inFile >> sessionData;
  sessionData.dump(wcout);

  inFile >> packetHeader;
  packetHeader.dump(wcout);

  inFile >> packetParticipantsData;
  packetParticipantsData.dump(wcout);

  return 0;
}

void displayUsage(string programName) {
  cerr << "Usage: " << programName
    << " --input|-i <input-filename>"
    << " --output|-o <output-filename>"
    << endl;
}