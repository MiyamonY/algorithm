/**
 * File:  test_single_source_shortest_path2.c
 * Author: ymiyamoto
 *
 * Created on Mon Jun 26 02:02:49 2017
 */

#include <array>
#include <stdbool.h>
#include <stdint.h>
#include <utility>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

static uint32_t cnt;
static int32_t weights[GRAPH_MAX_SIZE];

static void callback(int32_t index, int32_t weight)
{
  weights[index] = weight;
  cnt++;
}

static void setup(void)
{
  cnt = 0;
}

TestSuite(SingleSourceShortestPath2, .init = setup);

Test(SingleSourceShortestPath2, WhenGraphIsNull)
{
  cr_assert_not(single_source_shortest_path(nullptr, 5, callback));
  cr_assert_eq(cnt, 0);
}

Test(SingleSourceShortestPath2, WhenGraphSizeIs0)
{
  array<vector<pair<int32_t, int32_t>>, 0> graph;

  cr_assert_not(single_source_shortest_path(&graph[0], graph.size(), callback));
  cr_assert_eq(cnt, 0);
}

Test(SingleSourceShortestPath2, WhenGraphSizeIs1)
{
  array<vector<pair<int32_t, int32_t>>, 1> graph{
      {
          {{0, 1}},
      },
  };

  cr_assert(single_source_shortest_path(&graph[0], graph.size(), callback));
  cr_assert_eq(cnt, 1);
}

Test(SingleSourceShortestPath2, WhenGraphSizeIsN)
{
  vector<pair<int32_t, int32_t>> graph[] = {
      {{{1, 1}, {2, 20}, {3, 10}, {5, 3}}}, {{}}, {{}}, {{{2, 4}}}, {{{0, 6}, {2, 9}}}, {{{4, 2}}},
  };

  cr_assert(single_source_shortest_path(&graph[0], sizeof(graph) / sizeof(graph[0]), callback));
  array<int32_t, 6> expects{0, 1, 14, 10, 5, 3};

  for (uint32_t i = 0; i < expects.size(); i++) {
    cr_assert_eq(weights[i], expects[i]);
  }
}
