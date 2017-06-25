/**
 * File:  single_source_shortest_path1.c
 * Author: ymiyamoto
 *
 * Created on Mon Jun 26 00:56:08 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "problems.h"

static int32_t weights[MINIMUM_SPANNING_TREE_GRAPH_SIZE];
static color_t colors[MINIMUM_SPANNING_TREE_GRAPH_SIZE];

bool single_source_shortest_path(int32_t graph[][MINIMUM_SPANNING_TREE_GRAPH_SIZE], size_t size,
                                 single_source_shortest_path_callback_t callback)
{
  if ((graph == NULL) || (size == 0)) return false;

  uint32_t i;
  for (i = 0; i < size; i++) {
    weights[i] = INT32_MAX;
    colors[i] = WHITE;
  }

  weights[0] = 0;

  while (true) {
    int32_t mincost = INT32_MAX;
    uint32_t min_idx;
    for (i = 0; i < size; i++) {
      if ((colors[i] != BLACK) && (weights[i] < mincost)) {
        mincost = weights[i];
        min_idx = i;
      }
    }

    if (mincost == INT32_MAX) break;
    callback(min_idx, mincost);
    colors[min_idx] = BLACK;

    for (i = 0; i < size; i++) {
      if ((colors[i] != BLACK) && (graph[min_idx][i] != INT32_MAX)) {
        int32_t new_weight = weights[min_idx] + graph[min_idx][i];
        if (new_weight < weights[i]) {
          weights[i] = new_weight;
          colors[i] = GRAY;
        }
      }
    }
  }
  return true;
}

#if !defined(TEST)
#include <stdio.h>
int32_t graph[MINIMUM_SPANNING_TREE_GRAPH_SIZE][MINIMUM_SPANNING_TREE_GRAPH_SIZE];
int32_t lengths[MINIMUM_SPANNING_TREE_GRAPH_SIZE];

static void callback(uint32_t index, int32_t weight)
{
  lengths[index] = weight;
}

int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);

  uint32_t i, j;

  for (i = 0; i < num; i++) {
    for (j = 0; j < num; j++) {
      graph[i][j] = INT32_MAX;
    }
  }

  for (i = 0; i < num; i++) {
    int32_t index, len;
    scanf("%d %d", &index, &len);

    for (j = 0; j < len; j++) {
      int32_t v, c;
      scanf("%d %d", &v, &c);
      graph[index][v] = c;
    }
  }

  single_source_shortest_path(graph, num, callback);

  for (i = 0; i < num; i++) {
    printf("%d %d\n", i, lengths[i]);
  }

  return 0;
}
#endif
