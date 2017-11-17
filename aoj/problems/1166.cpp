#include <array>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(array<array<uint32_t, 30>, 30> &maze, vector<vector<uint32_t>> &vwalls,
         vector<vector<uint32_t>> &pwalls) {
  queue<pair<int32_t, int32_t>> q;

  q.push({0, 0});
  maze[0][0] = 1;

  while (!q.empty()) {
    pair<int32_t, int32_t> p = q.front();
    q.pop();
    int32_t h = p.first;
    int32_t w = p.second;
    uint32_t step = maze[h][w];
    if (pwalls[h][w] == 0 && maze[h][w + 1] == 0) {
      q.push({h, w + 1});
      maze[h][w + 1] = step + 1;
    }
    if (vwalls[h][w] == 0 && maze[h + 1][w] == 0) {
      q.push({h + 1, w});
      maze[h + 1][w] = step + 1;
    }
    if (w - 1 >= 0 && pwalls[h][w - 1] == 0 && maze[h][w - 1] == 0) {
      q.push({h, w - 1});
      maze[h][w - 1] = step + 1;
    }
    if (h - 1 >= 0 && vwalls[h - 1][w] == 0 && maze[h - 1][w] == 0) {
      q.push({h - 1, w});
      maze[h - 1][w] = step + 1;
    }
  }
}

int32_t main() {
  while (true) {
    int32_t w, h;
    cin >> w >> h;
    if (w == 0) break;

    array<array<uint32_t, 30>, 30> maze;
    for (uint32_t i = 0; i < maze.size(); i++) {
      for (uint32_t j = 0; j < maze.size(); j++) {
        maze[i][j] = 0;
      }
    }

    vector<vector<uint32_t>> vwalls;
    vector<vector<uint32_t>> pwalls;
    for (uint32_t i = 0; i < 2 * h - 1; i++) {
      uint32_t block;
      if (i % 2 == 0) {
        vector<uint32_t> walls;
        for (uint32_t j = 0; j < w - 1; j++) {
          cin >> block;
          walls.push_back(block);
        }
        walls.push_back(1);
        pwalls.push_back(walls);
      } else {
        vector<uint32_t> walls;
        for (uint32_t j = 0; j < w; j++) {
          cin >> block;
          walls.push_back(block);
        }
        vwalls.push_back(walls);
      }
    }

    vector<uint32_t> senti;
    for (uint32_t j = 0; j < w; j++) {
      senti.push_back(1);
    }
    vwalls.push_back(senti);

    bfs(maze, vwalls, pwalls);

    cout << maze[h - 1][w - 1] << endl;
  }

  return 0;
}