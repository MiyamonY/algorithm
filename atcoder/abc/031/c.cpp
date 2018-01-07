///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sun Jan  7 16:08:38 2018
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

  vector<int32_t> arr(N, 0);
  for (uint32_t i = 0; i < N; i++) {
    cin >> arr[i];
  }

  vector<int32_t> takahashis;
  for (uint32_t i = 0; i < N; i++) {
    int32_t max_aoki = INT32_MIN;
    int32_t max_takahashi = 0;
    for (uint32_t j = 0; j < N; j++) {
      if (i != j) {
        uint32_t start = i;
        uint32_t end = j;
        if (end < start) {
          swap(start, end);
        }
        int32_t takahashi = 0;
        int32_t aoki = 0;
        for (uint32_t k = start; k <= end; k++) {
          if ((k - start) % 2 == 0) {
            takahashi += arr[k];
          } else {
            aoki += arr[k];
          }
        }
        if (max_aoki < aoki) {
          max_aoki = aoki;
          max_takahashi = takahashi;
        }
      }
    }
    takahashis.push_back(max_takahashi);
  }

  sort(takahashis.begin(), takahashis.end());

  cout << takahashis[takahashis.size() - 1] << endl;

  return 0;
}
