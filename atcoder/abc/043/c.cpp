///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Wed Oct  4 20:43:39 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
static vector<int32_t> array;

int32_t main()
{
  uint32_t N;
  cin >> N;

  for (uint32_t i = 0; i < N; i++) {
    int32_t val;
    cin >> val;
    array.push_back(val);
  }

  int64_t cost = INT64_MAX;
  for (int32_t ave = -100; ave <= 100; ave++) {
    int64_t cost_at = 0;
    for (uint32_t i = 0; i < array.size(); i++) {
      cost_at += (array[i] - ave) * (array[i] - ave);
    }
    cost = min(cost, cost_at);
  }

  cout << cost << endl;

  return 0;
}
