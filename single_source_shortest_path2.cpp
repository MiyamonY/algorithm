#include <queue>
#include <stdint.h>
#include <vector>

#include "problems.hpp"

using namespace std;

enum color_t { WHITE, GRAY, BLACK };

static int32_t weights[GRAPH_MAX_SIZE];
static color_t colors[GRAPH_MAX_SIZE];

bool single_source_shortest_path(vector<pair<int32_t, int32_t>> *graph, size_t size, single_source_shortest_path_callback_t callback)
{
  if ((graph == nullptr) || (size == 0)) return false;

  int32_t i;
  for (i = 0; i < GRAPH_MAX_SIZE; i++) {
    weights[i] = INT32_MAX;
    colors[i] = WHITE;
  }

  weights[0] = 0;
  priority_queue<pair<int32_t, int32_t>> que;
  que.push(make_pair(-1 * weights[0], 0));

  while (!que.empty()) {
    pair<int, int> top = que.top();
    que.pop();
    int32_t top_index = top.second;
    int32_t top_weights = (-1) * top.first;
    if (top_weights > weights[top_index]) continue;

    callback(top_index, top_weights);
    colors[top_index] = BLACK;

    vector<pair<int32_t, int32_t>> vertex = graph[top_index];
    for (auto connect_to = vertex.begin(); connect_to != vertex.end(); connect_to++) {
      int32_t index = (*connect_to).first;
      if (colors[index] != BLACK) {
        int32_t new_weight = weights[top_index] + (*connect_to).second;

        if (new_weight < weights[index]) {
          weights[index] = new_weight;
          colors[index] = GRAY;
          que.push(make_pair(-1 * weights[index], index));
        }
      }
    }
  }
  return true;
}

#if !defined(TEST)
static vector<pair<int32_t, int32_t>> graph[GRAPH_MAX_SIZE];
static int32_t routes[GRAPH_MAX_SIZE];

void callback(int32_t index, int32_t weight)
{
  routes[index] = weight;
}

int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);

  uint32_t i;
  for (i = 0; i < num; i++) {
    int32_t index, len;
    scanf("%d", &index);
    scanf("%d", &len);
    uint32_t j;
    for (j = 0; j < len; j++) {
      int32_t k, v;
      scanf("%d %d", &k, &v);
      graph[i].push_back(make_pair(k, v));
    }
  }
  single_source_shortest_path(graph, num, callback);

  for (i = 0; i < num; i++) {
    printf("%d %d\n", i, routes[i]);
  }

  return 0;
}
#endif
