///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Fri Jan  5 17:01:50 2018
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t x, y;
  cin >> x >> y;

  if (x < y) {
    cout << "Better" << endl;
  } else {
    cout << "Worse" << endl;
  }

  return 0;
}
