///
// File:  single_source_shortest_path2.cpp
// Author: ymiyamoto
//
// Created on Tue Jul 18 21:26:15 2017
//

#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define GRAPH_SIZE 10000
#define WEIGHT_MAX UINT32_MAX

enum state_t { WHITE, GRAY, BLACK };

static state_t state[GRAPH_SIZE];
static priority_queue<pair<uint32_t, uint32_t>, vector<pair<uint32_t, uint32_t>>, greater<pair<uint32_t, uint32_t>>> min_queue;
static vector<pair<uint32_t, uint32_t>> graph[GRAPH_SIZE];
static uint64_t dist[GRAPH_SIZE];

void single_source_shortest_path(size_t num)
{
  for (uint32_t i = 0; i < num; i++) {
    dist[i] = WEIGHT_MAX;
    state[i] = WHITE;
  }

  state[0] = GRAY;
  dist[0] = 0;
  min_queue.push(make_pair(dist[0], 0));

  while (!min_queue.empty()) {
    pair<uint32_t, uint32_t> min = min_queue.top();
    min_queue.pop();
    uint32_t min_index = min.second;
    if (state[min_index] != BLACK) {
      state[min_index] = BLACK;
      for (uint32_t i = 0; i < graph[min_index].size(); i++) {
        pair<uint32_t, uint32_t> to = graph[min_index][i];
        uint32_t to_index = to.first;
        uint32_t to_weight = to.second;
        if (((dist[min_index] + to_weight) < dist[to_index]) && (state[to_index] != BLACK)) {
          dist[to_index] = dist[min_index] + to_weight;
          min_queue.push(make_pair(dist[to_index], to_index));
          state[to_index] = GRAY;
        }
      }
    }
  }
}

int32_t main()
{
  uint32_t num;
  cin >> num;

  for (uint32_t i = 0; i < num; i++) {
    uint32_t index, len;
    cin >> index >> len;
    for (uint32_t j = 0; j < len; j++) {
      uint32_t connect, weight;
      cin >> connect >> weight;
      graph[index].push_back(make_pair(connect, weight));
    }
  }

  single_source_shortest_path(num);

  for (uint32_t i = 0; i < num; i++) {
    cout << i << " " << dist[i] << endl;
  }

  return 0;
}
