///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sat Jan  6 22:55:34 2018
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t A, D;
  cin >> A >> D;

  cout << max((A + 1) * D, A * (D + 1)) << endl;

  return 0;
}
