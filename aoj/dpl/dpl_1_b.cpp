///
// File:  dpl_1_b.cpp
// Author: ymiyamoto
//
// Created on Wed Nov  1 23:21:00 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct item_t {
  int32_t value;
  int32_t weight;
};

#define MAX_NUM 101
#define MAX_WEIGHT 10001

static vector<item_t> weights;
static int32_t dp[MAX_NUM][MAX_WEIGHT];

int32_t main()
{
  int32_t N, W;
  cin >> N >> W;

  weights.push_back({0, 0});
  for (int32_t i = 0; i < N; i++) {
    int32_t value, weight;
    cin >> value >> weight;
    weights.push_back({value, weight});
  }

  for (int32_t n = 1; n <= N; n++) {
    for (int32_t weight = 0; weight <= W; weight++) {
      item_t item = weights[n];

      dp[n][weight] = dp[n - 1][weight];
      if (weight - item.weight >= 0) {
        dp[n][weight] = max(dp[n][weight], item.value + dp[n - 1][weight - item.weight]);
      }
    }
  }

  cout << dp[N][W] << endl;

  return 0;
}
