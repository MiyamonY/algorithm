///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Fri Jan  5 16:20:20 2018
//

#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node_t {
  uint32_t to;
  uint32_t cost;
};

void dikstra(vector<vector<node_t>> graph, vector<int64_t> &dist)
{
  priority_queue<pair<int32_t, uint32_t>> q;
  vector<bool> visited(graph.size(), false);

  dist[0] = 0;

  q.push({0, 0});
  while (!q.empty()) {
    pair<uint32_t, uint32_t> n = q.top();
    uint32_t d = -n.first;
    uint32_t v = n.second;
    q.pop();

    if (dist[v] < d) continue;

    visited[v] = true;
    for (uint32_t i = 0; i < graph[v].size(); i++) {
      node_t n = graph[v][i];
      if (!visited[n.to] && dist[v] + n.cost < dist[n.to]) {
        dist[n.to] = dist[v] + n.cost;
        q.push({-dist[n.to], n.to});
      }
    }
  }
}

int32_t main()
{
  int64_t N, M, T;
  cin >> N >> M >> T;

  vector<uint32_t> money(N, 0);
  for (uint32_t i = 0; i < N; i++) {
    cin >> money[i];
  }

  vector<vector<node_t>> graph(N, vector<node_t>());
  vector<vector<node_t>> graph2(N, vector<node_t>());

  for (uint32_t i = 0; i < M; i++) {
    uint32_t a, b, c;
    cin >> a >> b >> c;
    graph[a - 1].push_back({b - 1, c});
    graph2[b - 1].push_back({a - 1, c});
  }

  vector<int64_t> dist(N, (uint64_t)1 << 50);
  vector<int64_t> dist2(N, (uint64_t)1 << 50);

  dikstra(graph, dist);
  dikstra(graph2, dist2);

  int64_t max_cost = 0;
  for (uint32_t i = 0; i < N; i++) {
    if (dist[i] + dist2[i] < T) {
      max_cost = max(max_cost, (T - (dist[i] + dist2[i])) * money[i]);
    }
  }

  cout << max_cost << endl;

  return 0;
}
