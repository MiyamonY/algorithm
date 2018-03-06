///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Tue Mar  6 21:51:23 2018
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
};

static int32_t H, W;
static vector<string> graph;
static pos_t start, goal;

bool bfs(pos_t start)
{
  vector<vector<int32_t>> visited(H, vector<int32_t>(W, -1));
  visited[start.x][start.y] = 0;
  deque<pos_t> q;
  q.push_back(start);

  while (q.size() > 0) {
    pos_t p = q.front();
    q.pop_front();
    pos_t ds[] = {pos_t{-1, 0}, pos_t{1, 0}, pos_t{0, -1}, pos_t{0, 1}};
    for (auto d : ds) {
      int32_t dx = p.x + d.x;
      int32_t dy = p.y + d.y;
      if (0 <= dx && dx < H && 0 <= dy && dy < W && visited[dx][dy] == -1) {
        if (graph[dx][dy] == '#') {
          visited[dx][dy] = visited[p.x][p.y] + 1;
          q.push_back(pos_t{dx, dy});
        } else {
          visited[dx][dy] = visited[p.x][p.y];
          q.push_front(pos_t{dx, dy});
        }
      }
    }
  }

  return visited[goal.x][goal.y] <= 2;
}

int32_t main()
{
  cin >> H >> W;

  rep(i, 0, H)
  {
    string s;
    cin >> s;
    graph.push_back(s);
    rep(j, 0, W)
    {
      if (graph[i][j] == 's') {
        start.x = i;
        start.y = j;
      } else if (graph[i][j] == 'g') {
        goal.x = i;
        goal.y = j;
      }
    }
  }

  if (bfs(start)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
