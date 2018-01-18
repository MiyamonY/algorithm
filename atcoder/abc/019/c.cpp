///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Thu Jan 18 21:54:01 2018
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
  vector<uint32_t> arr(N);
  rep(i, 0, N)
  {
    cin >> arr[i];
  }

  while (true) {
    bool divided = false;
    rep(i, 0, N)
    {
      if (arr[i] % 2 == 0) {
        arr[i] /= 2;
        divided = true;
      }
    }

    if (!divided) {
      break;
    }
  }

  sort(arr.begin(), arr.end());

  uint32_t count = 1;
  rep(i, 1, N)
  {
    if (arr[i - 1] != arr[i]) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
