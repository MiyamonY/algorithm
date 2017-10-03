///
// File:  alds1_1_d.cpp
// Author: ymiyamoto
//
// Created on Wed Oct  4 00:51:49 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint64_t n;
  cin >> n;

  int64_t max_value = INT64_MIN;
  int64_t min_value;
  cin >> min_value;
  for (uint64_t i = 1; i < n; i++) {
    int64_t value;
    cin >> value;
    max_value = max(value - min_value, max_value);
    min_value = min(value, min_value);
  }

  cout << max_value << endl;

  return 0;
}
