///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sun Jan 14 11:21:52 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(n, init, N) for (int32_t n = init; n < (int32_t)(N); n++)
#define rrep(n, N) for (int32_t n = (int32_t)(N)-1; n >= 0; n--)

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

int32_t main()
{
  uint32_t A, B, C, K;
  cin >> A >> B >> C >> K;

  uint32_t S, T;

  cin >> S >> T;

  if (K <= S + T) {
    cout << A * S + B * T - (S + T) * C << endl;
  } else {
    cout << A * S + B * T << endl;
  }

  return 0;
}
