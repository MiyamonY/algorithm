///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Wed Dec  6 23:21:35 2017
//

#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t n;
  cin >> n;

  uint32_t minval = UINT32_MAX;
  for (uint32_t i = 1; i <= n; i++) {
    uint32_t j = n / i;
    minval = min(minval, abs((int32_t)i - (int32_t)j) + (n - i * j));
  }

  cout << minval << endl;
  return 0;
}
