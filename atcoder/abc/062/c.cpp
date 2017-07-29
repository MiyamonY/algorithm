///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Wed Jul 26 22:05:28 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

static int64_t split_same_height(int64_t H, int64_t W)
{
  int64_t min_diff = UINT32_MAX;
  for (int64_t i = 0; i <= H; i++) {
    int64_t w1 = i * W;
    int64_t w2 = (H - i) / 2 * W;
    int64_t w3 = (H - i - (H - i) / 2) * W;
    int64_t max_area = max(w1, max(w2, w3));
    int64_t min_area = min(w1, min(w2, w3));
    min_diff = min(min_diff, max_area - min_area);
  }
  return min_diff;
}

static int64_t split_bottom_two(int64_t H, int64_t W)
{
  int64_t min_diff = UINT32_MAX;
  for (int64_t i = 0; i <= H; i++) {
    int64_t w1 = i * W;
    int64_t w2 = (H - i) * (W / 2);
    int64_t w3 = (H - i) * (W - W / 2);
    int64_t max_area = max(w1, max(w2, w3));
    int64_t min_area = min(w1, min(w2, w3));
    min_diff = min(min_diff, max_area - min_area);
  }
  return min_diff;
}

int32_t main()
{
  int64_t H, W;
  cin >> H >> W;

  cout << min(split_same_height(H, W), min(split_same_height(W, H), min(split_bottom_two(W, H), split_bottom_two(H, W)))) << endl;
  return 0;
}
