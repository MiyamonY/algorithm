/**
 * File:  test_single_source_shortest_path1.c
 * Author: ymiyamoto
 *
 * Created on Mon Jun 26 00:48:43 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"

static uint32_t indices[MINIMUM_SPANNING_TREE_GRAPH_SIZE];
static uint32_t weights[MINIMUM_SPANNING_TREE_GRAPH_SIZE];

static size_t count = 0;

static void callback(uint32_t index, int32_t weight)
{
  indices[count] = index;
  weights[count] = weight;
  count++;
}

static void setup(void)
{
  count = 0;
}

TestSuite(SingleSourceShortestPath, .init = setup);

Test(SingleSourceShortestPath, WhenGraphIsNull)
{
  cr_assert_not(single_source_shortest_path(NULL, 5, callback));
  cr_assert_eq(count, 0);
}

Test(SingleSourceShortestPath, WhenGraphSizeIs0)
{
  int32_t graph[MINIMUM_SPANNING_TREE_GRAPH_SIZE][MINIMUM_SPANNING_TREE_GRAPH_SIZE] = {};

  cr_assert_not(single_source_shortest_path(graph, 0, callback));
  cr_assert_eq(count, 0);
}

Test(SingleSourceShortestPath, WhenGraphSizeIs1)
{
  int32_t graph[MINIMUM_SPANNING_TREE_GRAPH_SIZE][MINIMUM_SPANNING_TREE_GRAPH_SIZE] = {
      {INT32_MAX},
  };

  cr_assert(single_source_shortest_path(graph, 1, callback));
  cr_assert_eq(count, 1);
}

Test(SingleSourceShortestPath, WhenGraphSizeIsN)
{
  int32_t graph[MINIMUM_SPANNING_TREE_GRAPH_SIZE][MINIMUM_SPANNING_TREE_GRAPH_SIZE] = {
      {INT32_MAX, 4, 3, 2, INT32_MAX, 1}, {4, INT32_MAX, INT32_MAX, 7, 7, 5},          {3, INT32_MAX, INT32_MAX, 4, INT32_MAX, INT32_MAX},
      {2, 7, 4, INT32_MAX, 8, INT32_MAX}, {INT32_MAX, 7, INT32_MAX, 8, INT32_MAX, 11}, {1, 5, INT32_MAX, INT32_MAX, 11, INT32_MAX},
  };

  uint32_t expect[][2] = {
      {0, 0}, {5, 1}, {3, 2}, {2, 3}, {1, 4}, {4, 10},
  };

  cr_assert(single_source_shortest_path(graph, 6, callback));
  for (uint32_t i = 0; i < 6; i++) {
    cr_assert_eq(indices[i], expect[i][0]);
    cr_assert_eq(weights[i], expect[i][1]);
  }
}
