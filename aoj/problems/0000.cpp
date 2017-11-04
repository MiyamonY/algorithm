///
// File:  0000.cpp
// Author: ymiyamoto
//
// Created on Sat Nov  4 15:30:20 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  for (uint32_t i = 1; i <= 9; i++) {
    for (uint32_t j = 1; j <= 9; j++) {
      cout << i << "x" << j << "=" << i * j << endl;
    }
  }

  return 0;
}
