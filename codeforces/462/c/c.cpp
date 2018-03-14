///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Wed Mar 14 22:07:06 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(_n, _init, _N) for (int32_t _n = _init; _n < (int32_t)(_N); _n++)
#define rrep(_n, _N, _end) for (int32_t _n = (int32_t)(_N); _n >= _end; _n--)
#define iceil(_x, _y) (((_x) + (_y)-1) / (_y))
#define ifloor(_x, _y) ((_x) / (_y))

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

static int32_t N;

int32_t main()
{
  cin >> N;

  vector<uint64_t> arr(N, 0);
  rep(i, 0, N)
  {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  uint64_t count = 0;
  rep(i, 0, N)
  {
    count += (i + 2) * arr[i];
  }
  count -= arr[arr.size() - 1];

  cout << count << endl;

  return 0;
}
