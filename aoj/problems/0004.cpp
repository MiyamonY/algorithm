///
// File:  0004.cpp
// Author: ymiyamoto
//
// Created on Wed Nov  8 21:45:53 2017
//

#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace std;

int32_t main()
{
  while (true) {
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (cin.eof()) break;

    double x = (e * c - b * f) / (a * e - b * d);
    double y = (a * f - d * c) / (a * e - b * d);
    cout << fixed;
    cout << setprecision(3) << x + 0.0 << " " << y + 0.0 << endl;
  }

  return 0;
}
