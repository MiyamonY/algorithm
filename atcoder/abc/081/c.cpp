///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 10 21:26:22 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int32_t main()
{
  int32_t N, K;
  cin >> N >> K;

  map<uint32_t, uint32_t> m;
  for (int32_t i = 0; i < N; i++) {
    uint32_t n;
    cin >> n;
    if (m.count(n) > 0) {
      m[n]++;
    } else {
      m[n] = 1;
    }
  }

  vector<uint32_t> nums;
  for (auto i = m.begin(); i != m.end(); i++) {
    nums.push_back(i->second);
  }

  sort(nums.begin(), nums.end());
  uint32_t total = 0;
  for (int32_t i = 0; i < (int32_t)nums.size() - K; i++) {
    total += nums[i];
  }

  cout << total << endl;
  return 0;
}
