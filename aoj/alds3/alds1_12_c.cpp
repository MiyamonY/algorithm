///
// File:  alds1_12_c.cpp
// Author: ymiyamoto
//
// Created on Wed Oct 18 22:36:29 2017
//

#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define SIZE 10000

struct route_t {
  uint32_t node;
  int64_t weight;

  bool operator<(const route_t &r) const
  {
    return weight > r.weight;
  }
};

static vector<route_t> graph[SIZE];
static int64_t costs[SIZE];
static bool visited[SIZE];
static priority_queue<route_t> q;

static void dikstra()
{
  q.push({0, 0});
  costs[0] = 0;

  while (!q.empty()) {
    route_t r = q.top();
    q.pop();

    if (!visited[r.node]) {
      visited[r.node] = true;
      for (uint32_t i = 0; i < graph[r.node].size(); i++) {
        int64_t cost = graph[r.node][i].weight;
        uint32_t node = graph[r.node][i].node;
        if (cost != -1) {
          if (costs[r.node] + cost < costs[node]) {
            costs[node] = costs[r.node] + cost;
            q.push({node, costs[node]});
          }
        }
      }
    }
  }
}

int32_t main()
{
  uint32_t n;
  cin >> n;

  for (uint32_t i = 0; i < n; i++) {
    costs[i] = INT32_MAX;
  }

  for (uint32_t i = 0; i < n; i++) {
    uint32_t id, k;
    cin >> id >> k;
    for (uint32_t j = 0; j < k; j++) {
      route_t r;
      cin >> r.node >> r.weight;
      graph[id].push_back(r);
    }
  }

  dikstra();

  for (uint32_t i = 0; i < n; i++) {
    cout << i << " " << costs[i] << endl;
  }

  return 0;
}
