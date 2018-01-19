///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Fri Jan 19 22:43:41 2018
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
  uint32_t total = 0;
  rep(i, 0, 3)
  {
    uint32_t s, e;
    cin >> s >> e;
    total += s * e / 10;
  }

  cout << total << endl;

  return 0;
}
