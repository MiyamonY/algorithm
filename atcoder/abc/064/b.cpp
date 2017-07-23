///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sat Jul 22 18:14:01 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t num;

  uint32_t mi = UINT32_MAX;
  uint32_t ma = 0;

  cin >> num;
  for (uint32_t i = 0; i < num; i++) {
    uint32_t val;
    cin >> val;
    mi = min(mi, val);
    ma = max(ma, val);
  }

  cout << ma - mi << endl;
}
