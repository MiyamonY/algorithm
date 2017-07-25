///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Mon Jul 24 20:55:42 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t num, val;
  cin >> num;

  uint32_t total = 0;
  uint32_t min_not_10_times = UINT32_MAX;
  for (uint32_t i = 0; i < num; i++) {
    cin >> val;
    total += val;
    if ((val % 10) != 0) {
      min_not_10_times = min(min_not_10_times, val);
    }
  }

  if ((total % 10) == 0) {
    if (min_not_10_times == UINT32_MAX) {
      cout << "0" << endl;
    } else {
      cout << total - min_not_10_times << endl;
    }
  } else {
    cout << total << endl;
  }

  return 0;
}
