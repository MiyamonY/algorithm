///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Jan 14 11:25:28 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(n, init, N) for (int32_t n = init; n < (int32_t)(N); n++)
#define rrep(n, N) for (int32_t n = (int32_t)(N)-1; n >= 0; n--)

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

int32_t main()
{
  uint64_t N, T;
  cin >> N >> T;

  vector<int64_t> t(10000001, 0);
  rep(i, 0, N)
  {
    uint64_t A;
    cin >> A;
    t[A] += 1;
    if (A + T < 10000001) {
      t[A + T] += -1;
    }
  }

  t[10000000] = -1;

  rep(i, 0, 10000000)
  {
    t[i + 1] += t[i];
  }

  uint32_t count = 0;
  rep(i, 0, 10000000)
  {
    if (t[i] > 0) {
      count++;
    }
  }

  cout << count << endl;
  return 0;
}
