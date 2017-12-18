///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Fri Dec 15 00:01:58 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;

  vector<uint32_t> arr(N);
  vector<uint32_t> count(N);
  for (uint32_t i = 0; i < N; i++) {
    cin >> arr[i];
  }

  count[0] = 1;
  for (uint32_t i = 1; i < N; i++) {
    if (arr[i - 1] < arr[i]) {
      count[i] = count[i - 1] + 1;
    } else {
      count[i] = 1;
    }
  }

  uint64_t total = 0;
  for (auto c : count) {
    total += c;
  }

  cout << total << endl;

  return 0;
}
