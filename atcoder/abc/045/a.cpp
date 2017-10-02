///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sun Oct  1 03:10:11 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t a, b, h;
  cin >> a;
  cin >> b;
  cin >> h;

  cout << (a + b) * h / 2 << endl;

  return 0;
}
