///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sat Jul 29 21:09:29 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t val;
  cin >> val;

  uint32_t tmp = 1;
  while (2 * tmp <= val) {
    tmp *= 2;
  }
  cout << tmp << endl;

  return 0;
}
