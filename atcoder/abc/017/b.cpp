///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Fri Jan 19 22:45:18 2018
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
  string X;
  cin >> X;

  rep(i, 0, X.size())
  {
    if (X[i] == 'c') {
      i++;
      if (X[i] != 'h') {
        cout << "NO" << endl;
        return 0;
      }
    } else if (!(X[i] == 'o' || X[i] == 'k' || X[i] == 'u')) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}
