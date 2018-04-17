///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Tue Apr 17 22:07:09 2018
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
  int32_t N, K;
  cin >> N >> K;

  vector<int32_t> arr(N + 1);
  arr[0] = 0;
  for (int32_t i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  int32_t left = 0;
  int32_t right = N + 1;
  while (left + 1 < right) {
    vector<vector<bool>> dp(N + 1, vector<bool>(K + 1));
    dp[0][0] = true;

    int32_t mid = (left + right) / 2;
    for (int32_t num = 1; num <= N; num++) {
      if (num == mid) {
        dp[num] = dp[num - 1];
      } else {
        for (int32_t val = 0; val <= K; val++) {
          if ((val - arr[num]) >= 0) {
            dp[num][val] = dp[num][val] || dp[num - 1][val - arr[num]];
          }
          dp[num][val] = dp[num][val] || dp[num - 1][val];
        }
      }
    }

    bool found = false;
    for (int32_t i = max(0, K - arr[mid]); i < K; i++) {
      if (dp[N][i]) {
        found = true;
      }
    }

    if (found) {
      right = mid;
    } else {
      left = mid;
    }
  }

  cout << left << endl;
  return 0;
}
