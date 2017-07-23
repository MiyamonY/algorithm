///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sat Jul 22 18:11:59 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t r, g, b;
  cin >> r >> g >> b;

  uint32_t val = 100 * r + 10 * g + b;
  if (val % 4 == 0)
    cout << "YES";
  else
    cout << "NO";
  cout << endl;

  return 0;
}
