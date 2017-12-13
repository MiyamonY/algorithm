///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Thu Dec 14 01:03:36 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool in_range(int32_t H, int32_t W, int32_t x, int32_t y)
{
  return 0 <= x && x < H && 0 <= y && y < W;
}

bool center(vector<string> matrix, int32_t H, int32_t W, int32_t x, int32_t y)
{
  if (matrix[x][y] == '#') {
    for (int32_t dx = -1; dx <= 1; dx++) {
      for (int32_t dy = -1; dy <= 1; dy++) {
        if (in_range(H, W, x + dx, y + dy)) {
          if (matrix[x + dx][y + dy] != '#') {
            return false;
          }
        }
      }
    }
    return true;
  }
  return false;
}

void erase(vector<string> &matrix, int32_t H, int32_t W, int32_t x, int32_t y)
{
  for (int32_t dx = -1; dx <= 1; dx++) {
    for (int32_t dy = -1; dy <= 1; dy++) {
      if (in_range(H, W, x + dx, y + dy)) {
        matrix[x + dx][y + dy] = '.';
      }
    }
  }
}

int32_t main()
{
  int32_t H, W;
  cin >> H >> W;

  vector<string> matrix(H, "");
  for (int32_t i = 0; i < H; i++) {
    cin >> matrix[i];
  }

  vector<pair<uint32_t, uint32_t>> centers;
  for (int32_t x = 0; x < H; x++) {
    for (int32_t y = 0; y < W; y++) {
      if (center(matrix, H, W, x, y)) {
        centers.push_back({x, y});
      }
    }
  }

  for (auto c : centers) {
    erase(matrix, H, W, c.first, c.second);
  }

  for (auto line : matrix) {
    for (auto c : line) {
      if (c == '#') {
        cout << "impossible" << endl;
        return 0;
      }
    }
  }

  vector<string> matrix2(H, string(W, '.'));
  for (auto c : centers) {
    matrix2[c.first][c.second] = '#';
  }

  cout << "possible" << endl;
  for (auto line : matrix2) {
    cout << line << endl;
  }

  return 0;
}
