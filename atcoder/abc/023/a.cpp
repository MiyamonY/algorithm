///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sun Jan 14 15:52:12 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(n, init, N) for (int32_t n = init; n < (int32_t)(N); n++)
#define rrep(n, N) for (int32_t n = (int32_t)(N)-1; n >= 0; n--)

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

int32_t main()
{
  string X;
  cin >> X;

  cout << X[0] - '0' + X[1] - '0' << endl;

  return 0;
}
