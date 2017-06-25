/**
 * File:  minimum_spanning_tree.c
 * Author: ymiyamoto
 *
 * Created on Sun Jun 25 04:55:09 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "problems.h"

static color_t colors[MINIMUM_SPANNING_TREE_GRAPH_SIZE];
static int32_t minimum_costs[MINIMUM_SPANNING_TREE_GRAPH_SIZE];

bool minimum_spannig_tree(int32_t graph[][MINIMUM_SPANNING_TREE_GRAPH_SIZE], size_t size, size_t *weight)
{
  if (graph == NULL) {
    *weight = 0;
    return false;
  }

  uint32_t i;
  for (i = 0; i < size; i++) {
    colors[i] = WHITE;
    minimum_costs[i] = INT32_MAX;
  }

  minimum_costs[0] = 0;
  *weight = 0;

  while (true) {
    int32_t mincost = INT32_MAX;
    uint32_t minimum_vertex;
    for (i = 0; i < size; i++) {
      if ((colors[i] != BLACK) && (minimum_costs[i] < mincost)) {
        mincost = minimum_costs[i];
        minimum_vertex = i;
      }
    }

    if (mincost == INT32_MAX) break;
    *weight += mincost;
    colors[minimum_vertex] = BLACK;

    for (i = 0; i < size; i++) {
      if ((colors[i] != BLACK) && (graph[minimum_vertex][i] < INT32_MAX)) {
        if (graph[minimum_vertex][i] < minimum_costs[i]) {
          minimum_costs[i] = graph[minimum_vertex][i];
          colors[i] = GRAY;
        }
      }
    }
  }

  return true;
}

#if !defined(TEST)
int32_t graph[MINIMUM_SPANNING_TREE_GRAPH_SIZE][MINIMUM_SPANNING_TREE_GRAPH_SIZE];

int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);

  uint32_t i;
  for (i = 0; i < num; i++) {
    uint32_t j;
    for (j = 0; j < num; j++) {
      int32_t d;
      scanf("%d", &d);
      graph[i][j] = (d == -1) ? INT32_MAX : d;
    }
  }

  size_t weight;
  minimum_spannig_tree(graph, num, &weight);
  printf("%lu\n", weight);

  return 0;
}
#endif
