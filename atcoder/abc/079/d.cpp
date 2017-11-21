///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Wed Nov 22 00:06:50 2017
//

#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static array<array<uint32_t, 10>, 10> dists;

int32_t main()
{
  uint32_t H, W;
  cin >> H >> W;

  for (uint32_t i = 0; i <= 9; i++) {
    for (uint32_t j = 0; j <= 9; j++) {
      cin >> dists[i][j];
    }
  }

  for (uint32_t k = 0; k <= 9; k++) {
    for (uint32_t i = 0; i <= 9; i++) {
      for (uint32_t j = 0; j <= 9; j++) {
        dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
      }
    }
  }

  uint64_t count = 0;
  for (uint32_t i = 0; i < H; i++) {
    for (uint32_t j = 0; j < W; j++) {
      int32_t val;
      cin >> val;
      if (val >= 0) {
        count += dists[val][1];
      }
    }
  }
  cout << count << endl;

  return 0;
}
