///
// File:  dpl_1_c.cpp
// Author: ymiyamoto
//
// Created on Fri Dec 22 01:56:21 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  int32_t N, W;
  cin >> N >> W;

  vector<pair<int32_t, int32_t>> items(N + 1);
  for (int32_t i = 1; i <= N; i++) {
    cin >> items[i].first;
    cin >> items[i].second;
  }

  vector<vector<uint32_t>> dp(N + 1, vector<uint32_t>(W + 1, 0));

  for (int32_t i = 1; i <= N; i++) {
    int32_t v = items[i].first;
    int32_t w = items[i].second;
    for (int32_t j = 0; j <= W; j++) {
      if (j - w >= 0) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - w] + v);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[N][W] << endl;

  return 0;
}
