///
// File:  grl_4_b.cpp
// Author: ymiyamoto
//
// Created on Fri Oct 20 01:00:42 2017
//

#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define SIZE 10000

static vector<uint32_t> graph[SIZE];
static vector<uint32_t> connected_num(SIZE, 0);
static queue<uint32_t> q;
static vector<uint32_t> sorted;

int32_t main()
{
  uint32_t V, E;
  cin >> V >> E;

  for (uint32_t i = 0; i < E; i++) {
    uint32_t s, t;
    cin >> s >> t;
    graph[s].push_back(t);
    connected_num[t]++;
  }

  for (uint32_t i = 0; i < V; i++) {
    if (connected_num[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    uint32_t index = q.front();
    q.pop();

    sorted.push_back(index);
    for (uint32_t i = 0; i < graph[index].size(); i++) {
      connected_num[graph[index][i]]--;
      if (connected_num[graph[index][i]] == 0) {
        q.push(graph[index][i]);
      }
    }
  }

  for (uint32_t i = 0; i < sorted.size(); i++) {
    if (i != 0) cout << " ";
    cout << sorted[i];
  }
  cout << endl;

  return 0;
}
