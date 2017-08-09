///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Wed Aug  9 16:48:22 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t x;
  cin >> x;
  if (x < 1200) {
    cout << "ABC" << endl;
  } else {
    cout << "ARC" << endl;
  }

  return 0;
}
