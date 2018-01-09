///
// File:  2781.cpp
// Author: ymiyamoto
//
// Created on Fri Dec 29 19:30:51 2017
//

#include <cstdint>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

uint32_t wfs(vector<string> map, int32_t y, int32_t x)
{
  vector<vector<int32_t>> visited(map.size(), vector<int32_t>(map[0].size(), -1));
  visited[y][x] = 0;
  queue<pair<int32_t, int32_t>> q;
  q.push({y, x});

  while (!q.empty()) {
    pair<int32_t, int32_t> p = q.front();
    q.pop();

    vector<pair<int32_t, int32_t>> ds = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (auto d : ds) {
      int32_t y2 = p.first + d.first;
      int32_t x2 = p.second + d.second;
      if (0 <= y2 && y2 < (int32_t)map.size() && 0 <= x2 && x2 < (int32_t)map[0].size() && (visited[y2][x2] == -1)) {
        if (map[y2][x2] == '#' || map[y2][x2] == '$') continue;
        visited[y2][x2] = visited[p.first][p.second] + 1;
        q.push({y2, x2});
      }
    }
  }

  for (uint32_t i = 0; i < map.size(); i++) {
    for (uint32_t j = 0; j < map[0].size(); j++) {
      if (map[i][j] == '%') {
        return visited[i][j];
      }
    }
  }
}

int32_t main()
{
  uint32_t H, W;
  cin >> H >> W;
  vector<string> map;
  for (uint32_t i = 0; i < H; i++) {
    string line;
    cin >> line;
    map.push_back(line);
  }

  uint32_t princess;
  uint32_t soldier = UINT32_MAX;
  for (uint32_t y = 0; y < H; y++) {
    for (uint32_t x = 0; x < W; x++) {
      if (map[y][x] == '@') {
        princess = wfs(map, y, x);
      } else if (map[y][x] == '$') {
        soldier = min(soldier, wfs(map, y, x));
      }
    }
  }

  if (princess < soldier) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
