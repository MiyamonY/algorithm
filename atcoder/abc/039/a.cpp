///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Wed Dec 13 01:25:23 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t A, B, C;
  cin >> A >> B >> C;
  cout << 2 * (A * B + B * C + C * A) << endl;
  return 0;
}
