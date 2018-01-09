///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Tue Jan  9 22:43:06 2018
//

#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace std;

int32_t main()
{
  double n, m;
  cin >> n >> m;

  if (12 <= n) {
    n -= 12;
  }

  double diff = abs(30 * n + 0.5 * m - m * 6);

  cout << fixed << setprecision(5) << min(diff, abs(360 - diff)) << endl;

  return 0;
}
