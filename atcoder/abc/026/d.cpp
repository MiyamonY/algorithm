///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sat Jan 13 15:03:36 2018
//
#include <bits/stdc++.h>

using namespace std;

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

double A, B, C;

double f(double t)
{
  return A * t + B * sin(C * t * pi);
}

int32_t main()
{
  cin >> A >> B >> C;

  double low = ((100 - B) / A);
  double high = ((100 + B) / A);

  for (uint32_t i = 0; i < 10000; i++) {
    double mid = (low + high) / 2;
    double val = f(mid);
    if (100 - precision < val && val < 100 + precision) {
      low = mid;
      break;
    } else if (val > 100 + precision) {
      high = mid;
    } else {
      low = mid;
    }
  }

  cout << fixed << setprecision(10);
  cout << low << endl;

  return 0;
}
