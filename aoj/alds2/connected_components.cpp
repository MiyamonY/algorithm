///
// File:  connected_components.cpp
// Author: ymiyamoto
//
// Created on Tue Jul 18 00:00:34 2017
//

#include <cstdint>
#include <vector>

using namespace std;

#define GRAPH_SIZE 100000

enum state_t {
  WHITE,
  GRAY,
  BLACK,
};

struct vertex_t {
  uint32_t color;
  vector<uint32_t> connections;
};

static vertex_t graph[GRAPH_SIZE];
static state_t state[GRAPH_SIZE];

static void colorize(uint32_t index, uint32_t color)
{
  if (state[index] == WHITE) {
    state[index] = GRAY;
    graph[index].color = color;
    for (uint32_t i = 0; i < graph[index].connections.size(); i++) {
      colorize(graph[index].connections[i], color);
    }
    state[index] = BLACK;
  }
}

void check_connection(size_t num)
{
  for (uint32_t i = 0; i < num; i++) {
    state[i] = WHITE;
  }

  uint32_t color = 1;
  for (uint32_t i = 0; i < num; i++) {
    colorize(i, color);
    color++;
  }
}

#include <iostream>

int32_t main()
{
  uint32_t n, m;
  cin >> n >> m;

  for (uint32_t i = 0; i < m; i++) {
    uint32_t index, to;
    cin >> index >> to;
    graph[index].connections.push_back(to);
    graph[to].connections.push_back(index);
  }

  check_connection(n);

  uint32_t qs;
  cin >> qs;

  for (uint32_t i = 0; i < qs; i++) {
    uint32_t from, to;
    cin >> from >> to;

    if (graph[from].color == graph[to].color) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }

  return 0;
}
