///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sat Oct 14 21:28:00 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;
#define SIZE 100

static string table[SIZE];

int32_t main()
{
  int32_t H, W;
  cin >> H >> W;

  for (int32_t i = 0; i < H; i++) {
    string str;
    cin >> table[i];
  }

  for (int32_t i = 0; i < H; i++) {
    for (int32_t j = 0; j < W; j++) {
      if (table[i][j] == '.') {
        uint32_t count = 0;
        for (int32_t k = -1; k <= 1; k++) {
          for (int32_t l = -1; l <= 1; l++) {
            if (0 <= i + k && i + k <= (H - 1) && 0 <= j + l && j + l <= (W - 1) && table[i + k][j + l] == '#') {
              count++;
            }
          }
        }
        table[i][j] = count + '0';
      }
    }
  }

  for (int32_t i = 0; i < H; i++) {
    cout << table[i] << endl;
  }

  return 0;
}
