///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Wed Jan 17 23:07:20 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(_n, _init, _N) for (int32_t _n = _init; _n < (int32_t)(_N); _n++)
#define rrep(_n, _N, _end) for (int32_t _n = (int32_t)(_N); _n >= _end; _n--)
#define iceil(_x, _y) (((_x) + (_y)-1) / (_y))
#define ifloor(_x, _y) ((_x) / (_y))

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

int32_t main()
{
  uint32_t a, b, c;
  cin >> a >> b >> c;

  if (a < b) {
    if (b < c) {
      cout << b << endl;
    } else {
      cout << c << endl;
    }
  } else if (b < c) {
    if (c < a) {
      cout << c << endl;
    } else {
      cout << a << endl;
    }
  } else {
    if (a < b) {
      cout << a << endl;
    } else {
      cout << b << endl;
    }
  }

  return 0;
}
