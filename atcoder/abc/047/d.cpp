///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Thu Sep 28 21:47:48 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
static vector<int64_t> cost;

int32_t main()
{
  int64_t N, T;
  cin >> N >> T;

  int64_t min_val = INT64_MAX;
  for (int64_t i = 0; i < N; i++) {
    int64_t A;
    cin >> A;
    min_val = min(min_val, A);
    cost.push_back(A - min_val);
  }

  sort(cost.begin(), cost.end(), greater<int64_t>());

  uint32_t i = 0;
  uint64_t count = 0;
  while (cost[0] == cost[i] && i < cost.size()) {
    count++;
    i++;
  }

  cout << count << endl;

  return 0;
}
