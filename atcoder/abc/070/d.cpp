///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Mon Aug 14 02:17:15 2017
//

#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define GRAPH_SIZE (100000 + 1)
static vector<pair<int64_t, int64_t>> graph[GRAPH_SIZE];
static int64_t distances[GRAPH_SIZE];
static bool status[GRAPH_SIZE];
static priority_queue<pair<int64_t, int64_t>> q;

void init_graph()
{
  for (int64_t i = 0; i < GRAPH_SIZE; i++) {
    distances[i] = INT64_MAX;
    status[i] = false;
  }
}

void calc_distances(int64_t K)
{
  distances[K] = 0;
  q.push(make_pair(0, K));

  while (!q.empty()) {
    int64_t dist = -q.top().first;
    int64_t vertex = q.top().second;
    q.pop();

    status[vertex] = true;
    if (distances[vertex] < dist) continue;

    for (int64_t i = 0; i < graph[vertex].size(); i++) {
      int64_t to = graph[vertex][i].first;
      int64_t w = graph[vertex][i].second;
      if (!status[to]) {
        if ((distances[vertex] + w) < distances[to]) {
          distances[to] = distances[vertex] + w;
          q.push(make_pair(-distances[to], to));
        }
      }
    }
  }
}

// while (true) {
//   int64_t min_index;
//   uint64_t min_distance = UINT64_MAX;

//   for (int64_t i = 0; i < N; i++) {
//     if ((distances[i] < min_distance) && (!status[i])) {
//       min_index = i;
//       min_distance = distances[i];
//     }
//   }

//   if (min_distance == UINT64_MAX) break;
//   status[min_index] = true;

//   for (int64_t i = 0; i < graph[min_index].size(); i++) {
//     pair<int64_t, int64_t> vertex = graph[min_index][i];
//     int64_t to = vertex.first;
//     int64_t weight = vertex.second;
//     distances[to] = min(distances[to], min_distance + weight);
//   }
// }
//}

int32_t main()
{
  init_graph();

  int64_t N;
  cin >> N;

  for (int64_t i = 0; i < (N - 1); i++) {
    int64_t a, b;
    int64_t c;
    cin >> a >> b >> c;
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }

  int64_t Q, K;
  cin >> Q >> K;

  calc_distances(K);

  for (int64_t i = 0; i < Q; i++) {
    int64_t x, y;
    cin >> x >> y;
    cout << distances[x] + distances[y] << endl;
  }

  return 0;
}
