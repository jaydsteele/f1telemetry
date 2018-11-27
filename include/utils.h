#ifndef __utils_h__
#define __utils_h__

#include <iostream>

struct whitespace {
  whitespace(int n) : n(n) {}
  int n;
};

std::wostream& operator<< (std::wostream& os, const whitespace& ws) {
  for (int i=0; i<ws.n; i++) {
    os << " ";
  }
  return os;
};

#endif