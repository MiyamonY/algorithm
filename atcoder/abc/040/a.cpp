///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Fri Oct  6 19:57:28 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t x, n;
  cin >> x >> n;

  cout << min(x - n, n - 1) << endl;

  return 0;
}
