///
// File:  singile_source_shortest_path1.cpp
// Author: ymiyamoto
//
// Created on Tue Jul 18 07:05:32 2017
//

#include <cstdint>
#include <vector>

using namespace std;

#define GRAPH_SIZE 100

enum state_t {
  WHITE,
  GRAY,
  BLACK,
};

static uint32_t graph[GRAPH_SIZE][GRAPH_SIZE];
static state_t state[GRAPH_SIZE];
static uint32_t dist[GRAPH_SIZE];

size_t single_source_shotest_path(size_t num)
{
  size_t cost = 0;
  for (uint32_t i = 0; i < num; i++) {
    state[i] = WHITE;
    dist[i] = UINT32_MAX;
  }

  state[0] = GRAY;
  dist[0] = 0;

  while (true) {
    size_t minimum_cost = UINT32_MAX;
    uint32_t to = 0;
    for (uint32_t i = 0; i < num; i++) {
      if (dist[i] < minimum_cost) {
        minimum_cost = dist[i];
        to = i;
      }
    }

    if (minimum_cost == UINT32_MAX) break;

    cost += dist[to];

    for (uint32_t i = 0; i < num; i++) {
      if (((dist[to] + graph[to][i]) < dist[i]) && state[i] != BLACK) {
        state[i] = GRAY;
        dist[i] = dist[to] + graph[to][i];
      }
    }
    state[to] = BLACK;
  }

  return cost;
}

#include <iostream>

int32_t main()
{
  uint32_t num;
  cin >> num;

  for (uint32_t i = 0; i < num; i++) {
    for (uint32_t j = 0; j < num; j++) {
      graph[i][j] = UINT32_MAX;
    }
  }

  for (uint32_t i = 0; i < num; i++) {
    uint32_t index, len;
    cin >> index >> len;
    for (uint32_t j = 0; j < len; j++) {
      uint32_t v, c;
      cin >> v >> c;
      graph[index][v] = c;
    }
  }

  cout << single_source_shotest_path(num) << endl;

  return 0;
}
