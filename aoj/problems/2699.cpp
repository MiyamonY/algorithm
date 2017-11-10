///
// File:  2699.cpp
// Author: ymiyamoto
//
// Created on Fri Nov 10 23:53:04 2017
//

#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace std;

int32_t main()
{
  while (true) {
    uint32_t D;
    double E;
    cin >> D >> E;
    if (D == 0) break;

    double min_diff = 1000.0;
    for (uint32_t x = 0; x <= D; x++) {
      uint32_t y = D - x;
      min_diff = min(min_diff, abs(sqrt(x * x + y * y) - E));
    }

    cout << fixed;
    cout << setprecision(5) << min_diff + 0 << endl;
  }

  return 0;
}
