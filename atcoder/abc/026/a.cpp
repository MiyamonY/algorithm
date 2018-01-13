///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sat Jan 13 14:30:36 2018
//
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
  uint32_t A;
  cin >> A;

  uint32_t ans = 0;
  for (uint32_t i = 1; i < A; i++) {
    ans = max(ans, i * (A - i));
  }
  cout << ans << endl;

  return 0;
}
