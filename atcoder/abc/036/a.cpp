///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sat Dec 23 20:11:22 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t A, B;
  cin >> A >> B;

  for (uint32_t i = 0; true; i++) {
    if (B <= A * i) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
