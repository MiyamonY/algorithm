///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Tue Aug  8 23:09:59 2017
//

#include <cstdint>
#include <iostream>

using namespace std;
#define GRAPH_SIZE 8
static bool graph[GRAPH_SIZE][GRAPH_SIZE];
static bool visited[GRAPH_SIZE];

static void init_graph()
{
  for (uint32_t i = 0; i < GRAPH_SIZE; i++) {
    for (uint32_t j = 0; j < GRAPH_SIZE; j++) {
      graph[i][j] = false;
    }
    visited[i] = false;
  }
}

static bool is_visited_all(uint32_t N)
{
  bool ret = true;

  for (uint32_t i = 0; i < N; i++) {
    ret &= visited[i];
  }

  return ret;
}

static size_t dfs(uint32_t N, uint32_t node)
{
  if (is_visited_all(N)) {
    return 1;
  }

  uint32_t count = 0;
  for (uint32_t i = 0; i < N; i++) {
    if ((!visited[i]) && graph[node][i]) {
      visited[i] = true;
      count += dfs(N, i);
      visited[i] = false;
    }
  }

  return count;
}

int32_t main()
{
  init_graph();

  uint32_t N, M;
  cin >> N >> M;

  for (uint32_t i = 0; i < M; i++) {
    uint32_t from, to;
    cin >> from >> to;
    graph[from - 1][to - 1] = true;
    graph[to - 1][from - 1] = true;
  }

  visited[0] = true;
  cout << dfs(N, 0) << endl;

  return 0;
}
