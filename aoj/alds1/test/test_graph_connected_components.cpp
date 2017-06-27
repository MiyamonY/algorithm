/**
 * File:  test_connected_components.cpp
 * Author: ymiyamoto
 *
 * Created on Fri Jun 23 02:47:14 2017
 */

#include <array>
#include <stdbool.h>
#include <stdint.h>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"
#include "util.h"

using namespace std;

static void setup(void)
{
  graph_connected_components_init();
}

static void add_connected_vertexes(const vector<uint32_t> *vertexes, size_t size)
{
  for (uint32_t i = 0; i < size; i++) {
    for (uint32_t j = 0; j < vertexes[i].size(); j++) {
      graph_connected_components_add(i, vertexes[i][j]);
    }
  }
}

static void assert_connected_vertexes(const vector<uint32_t> *expects, size_t size)
{
  for (uint32_t i = 0; i < size; i++) {
    uint32_t *vertexes = graph_connected_components_connected_vertexes(i);
    for (uint32_t j = 0; j < expects[i].size(); j++) {
      cr_assert_eq(vertexes[j], expects[i][j]);
    }
  }
}

TestSuite(ConnectedComponents, .init = setup);

Test(ConnectedComponents, CanCreateSingleGraph)
{
  const array<vector<uint32_t>, 1> expected{vector<uint32_t>{1, 8, 9}};

  add_connected_vertexes(&expected[0], expected.size());
  assert_connected_vertexes(&expected[0], expected.size());
}

Test(ConnectedComponents, CanCreateConnectedGraph)
{
  const array<vector<uint32_t>, 10> expected{
      vector<uint32_t>{1, 8, 9}, // 0
      vector<uint32_t>{},        // 1
      vector<uint32_t>{},        // 2
      vector<uint32_t>{3},       // 3
      vector<uint32_t>{},        // 4
      vector<uint32_t>{},        // 5
      vector<uint32_t>{},        // 6
      vector<uint32_t>{},        // 7
      vector<uint32_t>{4, 5},    // 8
      vector<uint32_t>{3},       // 9
  };

  add_connected_vertexes(&expected[0], expected.size());
  assert_connected_vertexes(&expected[0], expected.size());
}

Test(ConnectedComponents, CheckConnected)
{
  const array<vector<uint32_t>, 17> graph{
      vector<uint32_t>{1, 8, 9}, // 0
      vector<uint32_t>{},        // 1
      vector<uint32_t>{},        // 2
      vector<uint32_t>{2},       // 3
      vector<uint32_t>{},        // 4
      vector<uint32_t>{},        // 5
      vector<uint32_t>{},        // 6
      vector<uint32_t>{10, 16},  // 7
      vector<uint32_t>{4, 5},    // 8
      vector<uint32_t>{3},       // 9
      vector<uint32_t>{},        // 10
      vector<uint32_t>{13},      // 11
      vector<uint32_t>{},        // 12
      vector<uint32_t>{12},      // 13
      vector<uint32_t>{},        // 14
      vector<uint32_t>{},        // 15
      vector<uint32_t>{14}       // 16
  };

  add_connected_vertexes(&graph[0], graph.size());

  graph_connected_components_colorize();
  cr_assert(graph_connected_components_is_connected(0, 2));
  cr_assert(graph_connected_components_is_connected(3, 0));
  cr_assert(graph_connected_components_is_connected(7, 14));
  cr_assert(graph_connected_components_is_connected(10, 14));
  cr_assert(graph_connected_components_is_connected(13, 12));
  cr_assert(graph_connected_components_is_connected(12, 11));

  cr_assert_not(graph_connected_components_is_connected(7, 0));
  cr_assert_not(graph_connected_components_is_connected(10, 13));
  cr_assert_not(graph_connected_components_is_connected(15, 5));
  cr_assert_not(graph_connected_components_is_connected(15, 16));
  cr_assert_not(graph_connected_components_is_connected(15, 13));
}
