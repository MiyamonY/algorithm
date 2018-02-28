///
// File:  0529.cpp
// Author: ymiyamoto
//
// Created on Wed Feb 28 21:12:52 2018
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
  while (true) {
    int64_t N, M;
    cin >> N >> M;
    if (N == 0) break;

    vector<int64_t> arr = vector<int64_t>(N + 1);
    rep(i, 1, N + 1)
    {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    vector<int64_t> sums = vector<int64_t>((N + 1) * (N + 1));
    uint32_t cnt = 0;
    rep(i, 0, N + 1)
    {
      rep(j, 0, N + 1)
      {
        sums[cnt] = arr[i] + arr[j];
        cnt++;
      }
    }

    sort(sums.begin(), sums.end());
    int64_t m = 0;
    rep(i, 0, sums.size())
    {
      int64_t rem = M - sums[i];
      if (0 <= rem) {
        auto p = lower_bound(sums.begin(), sums.end(), rem);
        if (p != sums.begin() && p != sums.end()) {
          m = max(m, *(p - 1) + sums[i]);
        }
      }
    }
    cout << m << endl;
  }

  return 0;
}
