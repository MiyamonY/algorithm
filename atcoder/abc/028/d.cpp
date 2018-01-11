///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Thu Jan 11 21:47:43 2018
//
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
  double N, K;
  cin >> N >> K;

  double ans = (1 + 3 * (N - 1) + 6 * (K - 1) * (N - K)) / pow(N, 3);
  cout << fixed << setprecision(20) << ans << endl;

  return 0;
}
