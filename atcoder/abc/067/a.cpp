///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Wed Jul 19 19:33:45 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t a, b;
  cin >> a >> b;

  if (((a % 3) == 0) || ((b % 3) == 0) || ((a + b) % 3 == 0)) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }

  return 0;
}
