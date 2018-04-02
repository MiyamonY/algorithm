///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Mon Apr  2 23:38:11 2018
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
  uint32_t N;
  cin >> N;
  vector<int32_t> as(3 * N);
  rep(i, 0, 3 * N)
  {
    cin >> as[i];
  }

  sort(as.begin(), as.end());

  uint64_t count = 0;
  rep(i, 0, N)
  {
    count += as[as.size() - 1 - 1 - 2 * i];
  }
  cout << count << endl;

  return 0;
}
