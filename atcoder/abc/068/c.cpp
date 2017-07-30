///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sat Jul 29 21:17:47 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
#define GRAPH_SIZE 200001

static vector<uint64_t> graph[GRAPH_SIZE];

int32_t main()
{
  uint64_t N, M;

  cin >> N >> M;

  for (uint32_t i = 0; i < M; i++) {
    uint64_t from, to;
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  for (uint32_t i = 0; i < graph[1].size(); i++) {
    uint64_t to = graph[1][i];
    for (uint32_t j = 0; j < graph[to].size(); j++) {
      if (graph[to][j] == N) {
        cout << "POSSIBLE" << endl;
        return 0;
      }
    }
  }

  cout << "IMPOSSIBLE" << endl;

  return 0;
}
