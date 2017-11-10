///
// File:  1125.cpp
// Author: ymiyamoto
//
// Created on Fri Nov 10 20:46:16 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  while (true) {
    uint32_t N, W, H;
    cin >> N;
    if (N == 0) break;
    cin >> W >> H;

    vector<pair<uint32_t, uint32_t>> trees;
    for (uint32_t i = 0; i < N; i++) {
      uint32_t x, y;
      cin >> x >> y;
      trees.push_back({x - 1, y - 1});
    }
    uint32_t U, T;
    cin >> U >> T;

    uint32_t max_count = 0;
    for (uint32_t i = 0; i < W; i++) {
      for (uint32_t j = 0; j < H; j++) {
        uint32_t count = 0;
        for (auto tree = trees.begin(); tree < trees.end(); tree++) {
          if (i <= tree->first && tree->first <= (i + U - 1) && j <= tree->second && tree->second <= (j + T - 1)) {
            count++;
          }
        }
        max_count = max(max_count, count);
      }
    }
    cout << max_count << endl;
  }

  return 0;
}
