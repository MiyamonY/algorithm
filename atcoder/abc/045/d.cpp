///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Tue Oct  3 19:31:52 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
static vector<pair<int64_t, int64_t>> rects;
static uint64_t counts[10];

int32_t main()
{
  int64_t H, W, N;
  cin >> H >> W >> N;
  for (int64_t i = 0; i < N; i++) {
    int64_t a, b;
    cin >> a >> b;
    for (int64_t i = 0; i < 3; i++) {
      for (int64_t j = 0; j < 3; j++) {
        int64_t x = a - i;
        int64_t y = b - j;
        if (1 <= x && x <= H - 2) {
          if (1 <= y && y <= W - 2) {
            rects.push_back({x, y});
          }
        }
      }
    }
  }

  int64_t has_black = 0;

  if (N > 0) {
    sort(rects.begin(), rects.end());

    pair<int64_t, int64_t> rect = rects[0];
    uint64_t count = 0;
    for (uint64_t i = 0; i < rects.size(); i++) {
      if (rect == rects[i]) {
        count++;
      } else {
        counts[count]++;
        has_black++;
        rect = rects[i];
        count = 1;
      }
    }

    counts[count]++;
    has_black++;
  }

  for (uint32_t i = 0; i < 10; i++) {
    if (i == 0) {
      cout << (H - 2) * (W - 2) - has_black << endl;
    } else {
      cout << counts[i] << endl;
    }
  }

  return 0;
}
