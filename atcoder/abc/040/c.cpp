///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Thu Dec  7 00:11:20 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t n;
  cin >> n;

  vector<int32_t> arr(n);
  for (uint32_t i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<uint32_t> dp(n);
  dp[1] = abs(arr[1] - arr[0]);
  for (uint32_t i = 2; i < n; i++) {
    dp[i] = min(dp[i - 2] + abs(arr[i] - arr[i - 2]), dp[i - 1] + abs(arr[i] - arr[i - 1]));
  }

  cout << dp[n - 1] << endl;

  return 0;
}
