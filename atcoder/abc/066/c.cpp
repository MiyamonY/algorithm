///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Fri Jul 21 22:15:37 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

#define ARRAY_SIZE 200000
uint32_t array[ARRAY_SIZE];

static uint32_t iright = (ARRAY_SIZE / 2);
static uint32_t ileft = (ARRAY_SIZE / 2) - 1;

int32_t main()
{
  uint32_t num;
  cin >> num;

  uint8_t dir = 0;
  for (uint32_t i = 0; i < num; i++) {
    uint32_t val;
    cin >> val;
    if (!dir) {
      array[iright] = val;
      iright++;
    } else {
      array[ileft] = val;
      ileft--;
    }
    dir = !dir;
  }

  for (uint32_t i = 0; i < num; i++) {
    uint32_t index;
    if ((num % 2) == 0) {
      ileft++;
      index = ileft;
    } else {
      iright--;
      index = iright;
    }
    cout << array[index];
    if (i != (num - 1)) cout << " ";
  }
  cout << endl;

  return 0;
}
