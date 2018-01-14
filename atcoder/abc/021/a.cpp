///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sun Jan 14 17:11:40 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(n, init, N) for (int32_t n = init; n < (int32_t)(N); n++)
#define rrep(n, N) for (int32_t n = (int32_t)(N)-1; n >= 0; n--)

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

int32_t main()
{
  int32_t N;
  cin >> N;

  vector<int32_t> exp2 = {8, 4, 2, 1};
  vector<int32_t> nums(4, 0);
  uint32_t index = 0;
  uint32_t count = 0;
  while (N > 0) {
    if (N - exp2[index] >= 0) {
      count++;
      nums[index]++;
      N -= exp2[index];
    } else {
      index++;
    }
  }
  cout << count << endl;

  rep(i, 0, exp2.size())
  {
    if (nums[i] > 0) {
      cout << exp2[i] << endl;
    }
  }

  return 0;
}
