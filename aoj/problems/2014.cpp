///
// File:  2014.cpp
// Author: ymiyamoto
//
// Created on Sun Nov 19 01:33:04 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum color_t {
  NONE = 0,
  WHITE = 0x01,
  BLACK = 0x02,
  BLACK_AND_WHITE = 0x03,
};

color_t dfs(vector<string> &arr, vector<vector<bool>> &visited, int32_t i, int32_t j)
{
  visited[i][j] = true;
  if (arr[i][j] == 'W') {
    return WHITE;
  } else if (arr[i][j] == 'B') {
    return BLACK;
  } else {
    color_t u = NONE, d = NONE, r = NONE, l = NONE;
    if (i > 0 && !visited[i - 1][j]) {
      d = dfs(arr, visited, i - 1, j);
    }
    if (i + 1 < arr.size() && !visited[i + 1][j]) {
      u = dfs(arr, visited, i + 1, j);
    }
    if (j + 1 < arr[0].size() && !visited[i][j + 1]) {
      r = dfs(arr, visited, i, j + 1);
    }
    if (j > 0 && !visited[i][j - 1]) {
      l = dfs(arr, visited, i, j - 1);
    }
    return (color_t)(u | d | r | l);
  }
}

int32_t main()
{
  while (true) {
    uint32_t w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) break;

    vector<string> arr;
    for (uint32_t _ = 0; _ < h; _++) {
      string str;
      cin >> str;
      arr.push_back(str);
    }

    vector<vector<color_t>> colors(h);
    vector<vector<bool>> visited(h);
    for (uint32_t i = 0; i < visited.size(); i++) {
      colors[i].resize(w, NONE);
      visited[i].resize(w);
    }
    for (uint32_t i = 0; i < h; i++) {
      for (uint32_t j = 0; j < w; j++) {
        for (auto iter = visited.begin(); iter < visited.end(); iter++) {
          for (auto it = iter->begin(); it < iter->end(); it++) {
            *it = false;
          }
        }
        colors[i][j] = dfs(arr, visited, i, j);
      }
    }

    uint32_t whites = 0, blacks = 0;
    for (uint32_t i = 0; i < h; i++) {
      for (uint32_t j = 0; j < w; j++) {
        if (arr[i][j] == '.') {
          if (colors[i][j] == WHITE) {
            whites++;
          } else if (colors[i][j] == BLACK) {
            blacks++;
          }
        }
      }
    }
    cout << blacks << " " << whites << endl;
  }

  return 0;
}
