///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Tue May 22 01:17:44 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(_n, _init, _N) for (int32_t _n = _init; _n < (int32_t)(_N); _n++)
#define rrep(_n, _N, _end) for (int32_t _n = (int32_t)(_N); _n >= _end; _n--)
#define iceil(_x, _y) (((_x) + (_y)-1) / (_y))
#define ifloor(_x, _y) ((_x) / (_y))

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

struct node_t {
  int32_t to;
  int32_t weight;
};

static int32_t N, M;
static vector<vector<node_t>> graph;
static vector<int32_t> vals;

static bool dfs(int root, int val)
{
  if (vals[root] == -(1 << 30)) {
    vals[root] = val;
  } else {
    return vals[root] == val;
  }

  for (auto node : graph[root]) {
    int32_t to = node.to;
    int32_t weight = node.weight;
    if (!dfs(to, val + weight)) {
      return false;
    }
  }
  return true;
}

int32_t main()
{
  cin >> N >> M;

  graph.resize(N + 1, vector<node_t>());
  for (int32_t i = 0; i < M; i++) {
    int32_t L, R, D;
    cin >> L >> R >> D;
    graph[L].push_back(node_t{R, D});
    graph[R].push_back(node_t{L, -D});
  }

  vals.resize(N + 1, -(1 << 30));
  for (int32_t i = 1; i < graph.size(); i++) {
    if (vals[i] == -(1 << 30) && !dfs(i, 0)) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
