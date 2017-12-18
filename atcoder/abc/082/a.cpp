///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 17 00:12:51 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t a, b;
  cin >> a >> b;
  cout << (uint32_t)((double)(a + b) / 2 + 0.5) << endl;

  return 0;
}
