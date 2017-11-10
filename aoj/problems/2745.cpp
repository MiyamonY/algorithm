///
// File:  2745.cpp
// Author: ymiyamoto
//
// Created on Sat Nov 11 01:28:25 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  while (true) {
    double R0, W0, C, R;
    cin >> R0 >> W0 >> C >> R;
    if (R0 == 0) break;

    int64_t X = 0;
    for (; X <= INT32_MAX; X++) {
      double Y = (R0 + X * R - C * W0) / C;
      if (-10e-6 < Y) {
        break;
      }
    }
    cout << X << endl;
  }

  return 0;
}
