///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sat Apr 14 20:18:39 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(_n, _init, _N) for (int32_t _n = _init; _n < (int32_t)(_N); _n++)
#define rrep(_n, _N, _end) for (int32_t _n = (int32_t)(_N); _n >= _end; _n--)
#define iceil(_x, _y) (((_x) + (_y)-1) / (_y))
#define ifloor(_x, _y) ((_x) / (_y))

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

struct route_t {
  int32_t to, weight;
  route_t(int32_t t, int32_t w)
  {
    to = t;
    weight = w;
  }
};

vector<vector<route_t>> graph;

int32_t wfs()
{
  deque<int32_t> q;
  vector<int32_t> weights(graph.size(), 1 << 30);

  q.push_back(1);
  weights[1] = 0;
  while (!q.empty()) {
    auto from = q.front();
    q.pop_front();
    for (auto r : graph[from]) {
      auto to = r.to;
      auto weight = r.weight;
      if (weights[from] + weight < weights[to]) {
        weights[to] = weights[from] + weight;
        if (weight == 0) {
          q.push_front(to);
        } else {
          q.push_back(to);
        }
      }
    }
  }

  return weights[0];
}

int32_t main()
{
  int64_t K;
  cin >> K;

  graph = vector<vector<route_t>>(K + 1, vector<route_t>{});

  for (int32_t i = 1; i <= K; i++) {
    route_t route((i + 1) % K, 1);
    graph[i].push_back(route);
    route_t route1((10 * i) % K, 0);
    graph[i].push_back(route1);
  }

  cout << wfs() + 1 << endl;
  return 0;
}
