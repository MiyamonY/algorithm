///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Wed Jan 17 23:09:14 2018
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
  string s;
  cin >> s;

  char current = '@';
  uint32_t count = 0;
  for (auto c : s) {
    if (current != c) {
      if (count > 0) {
        cout << current << count;
      }
      current = c;
      count = 1;
    } else {
      count++;
    }
  }

  cout << current << count << endl;

  return 0;
}
