///
// File:  2629.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 24 11:09:29 2017
//

#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace std;

int32_t main()
{
  double d;
  cin >> d;

  double y = (uint32_t)d;
  cout << fixed << setprecision(12) << max(d * sqrt(2), y + 1.0) << endl;

  return 0;
}
