///
// File:  dpl_3_a.cpp
// Author: ymiyamoto
//
// Created on Wed Nov  8 01:32:41 2017
//

#include <cstdint>
#include <iostream>

using namespace std;
#define MAX_H 1400
#define MAX_W 1400

static uint32_t arr[MAX_H][MAX_W];

int32_t main()
{
  uint32_t H, W;
  cin >> H >> W;
  for (uint32_t i = 0; i < H; i++) {
    for (uint32_t j = 0; j < W; j++) {
      uint32_t val;
      cin >> val;
      if (val == 0) {
        arr[i][j] = 1;
      } else {
        arr[i][j] = 0;
      }
    }
  }

  uint32_t max_val = 0;
  for (uint32_t i = 0; i < H; i++) {
    for (uint32_t j = 0; j < W; j++) {
      if (arr[i][j] != 0 && 0 < i && 0 < j) {
        arr[i][j] = 1 + min(arr[i - 1][j], min(arr[i][j - 1], arr[i - 1][j - 1]));
      }
      max_val = max(max_val, arr[i][j]);
    }
  }

  cout << max_val * max_val << endl;

  return 0;
}
