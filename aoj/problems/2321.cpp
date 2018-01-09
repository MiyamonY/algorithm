///
// File:  2321.cpp
// Author: ymiyamoto
//
// Created on Fri Dec 29 10:09:56 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  while (true) {
    uint32_t N;
    cin >> N;
    if (N == 0) break;

    vector<uint64_t> sats(N + 1, 0);
    vector<uint32_t> dates(N + 1, 0);
    for (uint32_t i = 1; i <= N; i++) {
      uint64_t M, L;
      cin >> M >> L;
      uint32_t date = 0;
      for (uint32_t j = 0; j < M; j++) {
        uint32_t S, E;
        cin >> S >> E;
        for (uint32_t k = S - 6; k < E - 6; k++) {
          date |= 1 << k;
        }
      }
      sats[i] = L;
      dates[i] = date;
    }

    vector<vector<uint64_t>> dp(N + 1, vector<uint64_t>(1 << 16, 0));
    for (uint32_t i = 1; i <= N; i++) {
      for (uint32_t j = 0; j < (1 << 16); j++) {
        dp[i][j] = dp[i - 1][j];
      }
      for (uint32_t j = 0; j < (1 << 16); j++) {
        if (j & dates[i]) continue;
        dp[i][j | dates[i]] = max(dp[i][j | dates[i]], dp[i - 1][j] + sats[i]);
      }
    }

    uint64_t max_val = 0;
    for (auto d : dp[N]) {
      max_val = max(max_val, d);
    }
    cout << max_val << endl;
  }

  return 0;
}
