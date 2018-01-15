///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Jan 14 21:04:49 2018
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
  int32_t K;
  cin >> K;

  vector<int64_t> A(K);
  rep(i, 0, K)
  {
    cin >> A[i];
  }

  int64_t num_min = 2;
  int64_t num_max = 2;
  rrep(i, K - 1, 0)
  {
    num_min = A[i] * iceil(num_min, A[i]);
    num_max = A[i] * ifloor(num_max, A[i]) + A[i] - 1;

    if (num_max < num_min || (num_min == num_max && (num_min % A[i] != 0))) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << num_min << " " << num_max << endl;

  return 0;
}
