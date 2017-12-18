///
// File:  1277.cpp
// Author: ymiyamoto
//
// Created on Mon Dec 11 22:08:53 2017
//

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  while (true) {
    uint32_t N, T, L, B;
    cin >> N >> T >> L >> B;

    if (N == 0) break;

    vector<uint32_t> lose(L);
    for (uint32_t i = 0; i < L; i++) {
      cin >> lose[i];
    }

    vector<uint32_t> back(B);
    for (uint32_t i = 0; i < B; i++) {
      cin >> back[i];
    }

    vector<vector<double>> dp(T + 1, vector<double>(N + 1, 0.0));
    dp[0][0] = 1;
    for (uint32_t i = 0; i < T; i++) {
      for (uint32_t j = 0; j < N; j++) {
        for (uint32_t k = 1; k <= 6; k++) {
          uint32_t next;
          if (j + k <= N) {
            next = j + k;
          } else {
            next = 2 * N - (j + k);
          }

          if (find(lose.begin(), lose.end(), next) != lose.end()) {
            if (i + 2 <= T) {
              dp[i + 2][next] += dp[i][j] / 6;
            }
          } else if (find(back.begin(), back.end(), next) != back.end()) {
            dp[i + 1][0] += dp[i][j] / 6;
          } else {
            dp[i + 1][next] += dp[i][j] / 6;
          }
        }
      }
      dp[i + 1][N] += dp[i][N];
    }

    cout << fixed << setprecision(6);
    cout << dp[T][N] << endl;
  }

  return 0;
}
