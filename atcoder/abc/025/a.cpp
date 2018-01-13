///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sat Jan 13 17:11:53 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(n, init, N) for (int32_t n = init; n < (int32_t)(N); n++)
#define rrep(n, N) for (int32_t n = (int32_t)(N)-1; n >= 0; n--)

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

int32_t main()
{
  string S;
  int32_t N;
  cin >> S >> N;

  int32_t count = 0;
  rep(i, 0, S.size())
  {
    rep(j, 0, S.size())
    {
      count++;
      if (count == N) {
        cout << S[i] << S[j] << endl;
        return 0;
      }
    }
  }

  return 0;
}
