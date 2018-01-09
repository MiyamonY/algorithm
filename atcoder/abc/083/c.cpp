///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sat Dec 23 21:48:23 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

uint64_t pow(uint64_t n)
{
  uint64_t ret = 1;
  for (uint64_t i = 0; i < n; i++) {
    ret *= 2;
  }
  return ret;
}

int32_t main()
{
  uint64_t X, Y;
  cin >> X >> Y;

  for (uint64_t i = 1; true; i++) {
    if (pow(i) * X > Y) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
