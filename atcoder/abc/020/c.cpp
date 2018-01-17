///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Wed Jan 17 01:45:56 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(_n, _init, _N) for (int32_t _n = _init; _n < (int32_t)(_N); _n++)
#define rrep(_n, _N, _end) for (int32_t _n = (int32_t)(_N); _n >= _end; _n--)
#define iceil(_x, _y) (((_x) + (_y)-1) / (_y))
#define ifloor(_x, _y) ((_x) / (_y))

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

struct pos_t {
  int32_t x;
  int32_t y;

  bool operator<(const pos_t &_) const
  {
    return true;
  }
};

int64_t dfs(vector<vector<char>> matrix, pos_t start, pos_t end, int64_t t)
{
  vector<vector<int64_t>> dists(matrix.size(), vector<int64_t>(matrix[0].size(), -1));
  priority_queue<pair<int64_t, pos_t>> q;
  q.push({0, {start.x, start.y}});

  while (!q.empty()) {
    pair<int64_t, pos_t> n = q.top();
    int64_t dist = -n.first;
    pos_t p = n.second;
    dists[p.x][p.y] = dist;

    q.pop();
    vector<pos_t> diff = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto d : diff) {
      int32_t x = p.x + d.x;
      int32_t y = p.y + d.y;
      if (0 <= x && x < (int32_t)matrix.size() && 0 <= y && y < (int32_t)matrix[0].size() && dists[x][y] == -1) {
        int64_t dist = 0;
        if (matrix[x][y] == '#') {
          dist = dists[p.x][p.y] + t;
        } else {
          dist = dists[p.x][p.y] + 1;
        }
        q.push({-dist, {x, y}});
      }
    }
  }

  return dists[end.x][end.y];
}

int32_t main()
{
  int64_t H, W, T;
  cin >> H >> W >> T;

  vector<vector<char>> matrix(H, vector<char>(W));
  pos_t start, end;
  rep(i, 0, H)
  {
    rep(j, 0, W)
    {
      cin >> matrix[i][j];
      if (matrix[i][j] == 'S') {
        start.x = i;
        start.y = j;
      } else if (matrix[i][j] == 'G') {
        end.x = i;
        end.y = j;
      }
    }
  }

  int64_t ub = T + 1;
  int64_t lb = 1;
  while (ub - lb > 1) {
    int64_t mid = (ub + lb) / 2;
    if (dfs(matrix, start, end, mid) <= T) {
      lb = mid;
    } else {
      ub = mid;
    }
  }

  cout << lb << endl;

  return 0;
}
