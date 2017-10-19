///
// File:  grl_5_a.cpp
// Author: ymiyamoto
//
// Created on Fri Oct 20 01:48:10 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
#define SIZE 100000

struct route_t {
  uint64_t to;
  uint64_t dist;
};

static vector<route_t> tree[SIZE];
static vector<uint64_t> distances(SIZE, UINT32_MAX);
static vector<bool> visited(SIZE, false);

uint64_t distant(uint64_t n)
{
  uint64_t dist = 0;
  for (uint64_t i = 0; i < n; i++) {
    if (distances[dist] < distances[i]) {
      dist = i;
    }
  }
  return dist;
}

void dfs(uint32_t from)
{
  visited[from] = true;
  for (uint32_t i = 0; i < tree[from].size(); i++) {
    route_t r = tree[from][i];
    if (!visited[r.to]) {
      distances[r.to] = min(distances[r.to], distances[from] + r.dist);
      dfs(r.to);
    }
  }
}

int32_t main()
{
  uint32_t n;
  cin >> n;

  for (uint32_t i = 0; i < n - 1; i++) {
    uint64_t s, t, w;
    cin >> s >> t >> w;
    tree[s].push_back({t, w});
    tree[t].push_back({s, w});
  }

  distances[0] = 0;
  dfs(0);

  uint64_t dist = distant(n);

  for (uint32_t i = 0; i < n; i++) {
    distances[i] = UINT32_MAX;
    visited[i] = false;
  }

  distances[dist] = 0;
  dfs(dist);

  cout << distances[distant(n)] << endl;

  return 0;
}
