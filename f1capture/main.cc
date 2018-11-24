#include "include/PacketHeader.h"
#include <getopt.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "f1capture/capture_telemetry.h"

using namespace std;

void displayUsage(string programName);

int main(int argc, char** argv) {

  static struct option longopts[] = {
    { "port", required_argument, 0, 'p' },
    { "output", required_argument, 0, 'o' },
  };

  int c;
  int port = -1;
  string outputFilename;
  bool error = false;

  while ((c = getopt_long(argc, argv, "p:o:", longopts, NULL)) != -1) {
    switch(c) {
      case 'p':
        try {
          port = stoi(optarg);
        } catch (std::invalid_argument) {
          cerr << "Invalid port number: " << optarg << endl;
          error = true;
        }
        break;
      case 'o':
        outputFilename = optarg;
        break;
    }
  }

  if (outputFilename.length() == 0) {
    cerr << "Error: No output filename provided" << endl;
    error = true;
  }
  if (port == -1) {
    cerr << "Error: No port number provided" << endl;
    error = true;
  }

  if (error) {
    displayUsage(argv[0]);
    exit(EXIT_FAILURE);
  }

  cout << "OUTPUT: " << outputFilename << endl;
  cout << "PORT: " << port << endl;

  return 0;
}

void displayUsage(string programName) {
  cerr << "Usage: " << programName
    << " --port|-p <udp-port>"
    << " --output|-o <output-filename>"
    << endl;
}