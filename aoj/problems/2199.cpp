///
// File:  2199.cpp
// Author: ymiyamoto
//
// Created on Sat Dec  9 23:16:36 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

#define MAX UINT32_MAX

using namespace std;

int32_t main()
{
  while (true) {
    uint32_t N, M;
    cin >> N >> M;
    if (N == 0 && M == 0) break;

    vector<int32_t> C(M);
    vector<int32_t> x(N + 1);

    for (uint32_t i = 0; i < M; i++) {
      cin >> C[i];
    }

    for (uint32_t i = 1; i <= N; i++) {
      cin >> x[i];
    }

    vector<vector<uint64_t>> dp(N + 1, vector<uint64_t>(256, MAX));
    dp[0][128] = 0;

    for (uint32_t i = 0; i < N; i++) {
      for (int32_t j = 0; j < 256; j++) {
        if (dp[i][j] == MAX) continue;
        for (uint32_t k = 0; k < C.size(); k++) {
          int32_t val = min(max(0, j + C[k]), 255);
          int32_t diff = (x[i + 1] - val);
          dp[i + 1][val] = min(dp[i + 1][val], dp[i][j] + diff * diff);
        }
      }
    }

    uint64_t minval = MAX;
    for (int32_t i = 0; i < 256; i++) {
      minval = min(minval, dp[N][i]);
    }

    cout << minval << endl;
  }

  return 0;
}
