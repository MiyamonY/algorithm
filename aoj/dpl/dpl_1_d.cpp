///
// File:  dpl_1_d.cpp
// Author: ymiyamoto
//
// Created on Thu Nov  2 08:05:56 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;

  vector<uint64_t> arr(N, 0);
  for (uint32_t i = 0; i < N; i++) {
    cin >> arr[i];
  }

  vector<uint64_t> dp(N + 1, 1 << 30);
  for (uint32_t i = 0; i < N; i++) {
    *lower_bound(dp.begin(), dp.end(), arr[i]) = arr[i];
  }

  for (uint32_t i = 0; i <= N; i++) {
    if (dp[i] == 1 << 30) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
