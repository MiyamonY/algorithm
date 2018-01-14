///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sun Jan 14 16:57:01 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(n, init, N) for (int32_t n = init; n < (int32_t)(N); n++)
#define rrep(n, N) for (int32_t n = (int32_t)(N)-1; n >= 0; n--)

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

int32_t main()
{
  int32_t N, S, T;
  cin >> N >> S >> T;

  int32_t W;
  cin >> W;

  uint32_t count = 0;

  if (S <= W && W <= T) {
    count++;
  }

  rep(i, 1, N)
  {
    int32_t A;
    cin >> A;

    W += A;
    if (S <= W && W <= T) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
