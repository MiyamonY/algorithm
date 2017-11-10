///
// File:  1124.cpp
// Author: ymiyamoto
//
// Created on Fri Nov 10 15:22:43 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  while (true) {
    uint32_t N, Q;
    cin >> N >> Q;
    if (N == 0) break;

    vector<uint32_t> nums(101, 0);

    for (uint32_t i = 0; i < N; i++) {
      uint32_t n;
      cin >> n;
      for (uint32_t j = 0; j < n; j++) {
        uint32_t day;
        cin >> day;
        nums[day]++;
      }
    }

    uint32_t max_num = 0;
    uint32_t the_day = 0;
    for (uint32_t i = 1; i < 101; i++) {
      if (nums[i] >= Q) {
        if (nums[i] > max_num) {
          max_num = nums[i];
          the_day = i;
        }
      }
    }

    cout << the_day << endl;
  }

  return 0;
}
