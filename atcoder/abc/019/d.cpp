///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Thu Jan 18 22:38:53 2018
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

  uint32_t max_node = 0;
  uint32_t max_dist = 0;
  rep(i, 2, N + 1)
  {
    cout << "? 1 " << i << endl;
    uint32_t dist;
    cin >> dist;
    if (max_dist < dist) {
      max_dist = dist;
      max_node = i;
    }
  }

  max_dist = 0;
  rep(i, 1, N + 1)
  {
    cout << "? " << max_node << " " << i << endl;
    uint32_t dist;
    cin >> dist;
    if (max_dist < dist) {
      max_dist = dist;
    }
  }

  cout << "! " << max_dist << endl;

  return 0;
}
