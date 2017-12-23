///
// File:  2746.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 24 03:44:12 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  while (true) {
    string jfen;
    cin >> jfen;
    if (jfen[0] == '#') break;

    uint32_t height = 1;
    uint32_t width = 0;
    for (uint32_t i = 0; i < jfen.size(); i++) {
      if (jfen[i] == '/') {
        height++;
      } else {
        if (height == 1) {
          if (jfen[i] == 'b') {
            width++;
          } else {
            width += jfen[i] - '0';
          }
        }
      }
    }

    vector<vector<char>> board(height, vector<char>(width, '.'));
    uint32_t x = 0;
    uint32_t y = 0;
    for (uint32_t i = 0; i < jfen.size(); i++) {
      if (jfen[i] == '/') {
        x = 0;
        y++;
      } else {
        if (jfen[i] == 'b') {
          board[y][x] = 'b';
          x++;
        } else {
          x += jfen[i] - '0';
        }
      }
    }

    uint32_t a, b, c, d;
    cin >> a >> b >> c >> d;
    board[a - 1][b - 1] = '.';
    board[c - 1][d - 1] = 'b';

    for (uint32_t i = 0; i < height; i++) {
      if (i != 0) cout << "/";
      uint32_t cnt = 0;
      string line = "";
      for (uint32_t j = 0; j < width; j++) {
        if (board[i][j] == 'b') {
          if (cnt > 0) {
            line += to_string(cnt);
            cnt = 0;
          }
          line += 'b';
        } else {
          cnt++;
        }
      }
      if (cnt > 0) {
        line += to_string(cnt);
      }
      cout << line;
    }
    cout << endl;
  }

  return 0;
}
