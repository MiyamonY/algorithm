///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sat Jan 20 13:22:12 2018
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
  string A, B;
  cin >> A >> B;

  if (A.size() > B.size()) {
    cout << A << endl;
  } else {
    cout << B << endl;
  }

  return 0;
}