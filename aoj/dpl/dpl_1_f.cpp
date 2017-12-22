///
// File:  dpl_1_f.cpp
// Author: ymiyamoto
//
// Created on Fri Dec 22 02:12:37 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

constexpr int32_t VAL = 100;

int32_t main()
{
  int32_t N, W;
  cin >> N >> W;

  vector<pair<int64_t, int64_t>> items(N + 1);
  for (int32_t i = 1; i <= N; i++) {
    cin >> items[i].first;
    cin >> items[i].second;
  }

  vector<vector<int64_t>> dp(N + 1, vector<int64_t>(N * VAL + 1, 1 << 30));
  dp[0][0] = 0;
  for (int32_t i = 1; i <= N; i++) {
    int64_t v = items[i].first;
    int64_t w = items[i].second;
    for (int32_t j = 0; j <= N * VAL; j++) {
      if (j - v >= 0) {
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v] + w);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  uint32_t max_val = 0;
  for (auto l : dp) {
    for (uint32_t v = 0; v < l.size(); v++) {
      if (l[v] <= W) {
        max_val = max(max_val, v);
      }
    }
  }

  cout << max_val << endl;

  return 0;
}
