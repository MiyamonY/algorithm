///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sun Jul 23 03:39:15 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

static uint8_t colors = 0;

int32_t main()
{
  uint32_t num;
  cin >> num;

  uint8_t num_max_rate = 0;

  for (uint32_t i = 0; i < num; i++) {
    uint32_t val;
    cin >> val;

    int8_t shift = 0;
    if (val <= 399) {
      shift = 0;
    } else if (val <= 799) {
      shift = 1;
    } else if (val <= 1199) {
      shift = 2;
    } else if (val <= 1599) {
      shift = 3;
    } else if (val <= 1999) {
      shift = 4;
    } else if (val <= 2399) {
      shift = 5;
    } else if (val <= 2799) {
      shift = 6;
    } else if (val <= 3199) {
      shift = 7;
    } else {
      shift = -1;
      num_max_rate++;
    }

    if (shift != -1) {
      colors |= (1 << shift);
    }
  }

  uint8_t count = 0;
  for (uint8_t i = 0; i < 8; i++) {
    if ((colors >> i) & 0x01) {
      count++;
    }
  }

  int32_t ma = count;
  int32_t mi = count;

  ma += num_max_rate;

  if ((count == 0) && num_max_rate) {
    mi = 1;
  }

  cout << mi << " " << ma << endl;

  return 0;
}
