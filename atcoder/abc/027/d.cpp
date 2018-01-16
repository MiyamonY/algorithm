///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Tue Jan 16 22:44:51 2018
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
  string S;
  cin >> S;

  vector<int32_t> sign(S.size(), 0);
  rep(i, 0, S.size())
  {
    if (S[i] == '+') {
      sign[i]++;
    } else if (S[i] == '-') {
      sign[i]--;
    }
  }

  vector<int32_t> nums;
  rrep(i, sign.size() - 1, 1)
  {
    sign[i - 1] += sign[i];
    if (S[i] == 'M') {
      nums.push_back(sign[i]);
    }
  }

  if (S[0] == 'M') {
    nums.push_back(sign[0]);
  }

  sort(nums.begin(), nums.end());

  int32_t count = 0;
  rep(i, 0, nums.size())
  {
    if (i < (int32_t)(nums.size() / 2)) {
      count -= nums[i];
    } else {
      count += nums[i];
    }
  }

  cout << count << endl;

  return 0;
}
