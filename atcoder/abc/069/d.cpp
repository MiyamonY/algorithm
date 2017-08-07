///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sun Aug  6 22:42:44 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
#define MAX_HEIGHT 100
#define MAX_WIDTH 100
#define MAX_NUM (MAX_HEIGHT * MAX_WIDTH)

static uint32_t color_matrix[MAX_HEIGHT * MAX_WIDTH];

int32_t main()
{
  uint32_t H, W;
  cin >> H >> W;

  uint32_t N;
  cin >> N;
  uint32_t count = 0;
  for (uint32_t i = 0; i < N; i++) {
    uint32_t num;
    cin >> num;
    for (uint32_t j = 0; j < num; j++) {
      color_matrix[count] = i + 1;
      count++;
    }
  }

  for (uint32_t i = 0; i < H; i++) {
    for (uint32_t j = 0; j < W; j++) {
      if (j != 0) cout << " ";
      if (i % 2 == 0) {
        cout << color_matrix[i * W + j];
      } else {
        cout << color_matrix[i * W + W - 1 - j];
      }
    }
    cout << endl;
  }
  return 0;
}
