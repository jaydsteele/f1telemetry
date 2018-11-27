#ifndef __unpack_h__
#define __unpack_h__

#include "types.h"
#include "endian.h"
#include <cstring>

uint8_t unpack_uint8(char* b, int i) {
  return (uint8_t)b[i];
}

int8_t unpack_int8(char* b, int i) {
  return (int8_t)b[i];
}

uint16_t unpack_uint16(char* b, int i) {
  uint16_t result;
  memcpy(&result, &b[i], sizeof(uint16_t));
  return Swap2Bytes(result);
}

uint32_t unpack_uint32(char* b, int i) {
  uint32_t result;
  memcpy(&result, &b[i], sizeof(uint32_t));
  return Swap4Bytes(result);
}

uint_t unpack_uint(char* b, int i) {
  return (uint_t)unpack_uint32(b, i);
}

uint64_t unpack_uint64(char* b, int i) {
  uint64_t result;
  memcpy(&result, &b[i], sizeof(uint64_t));
  return Swap8Bytes(result);
}

float unpack_float(char* b, int i) {
  float result;
  memcpy(&result, &b[i], sizeof(float));
  return Swap4Bytes(result);
}

#endif