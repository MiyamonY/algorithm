/**
 * File:  test_connected_components.cpp
 * Author: ymiyamoto
 *
 * Created on Fri Jun 23 02:47:14 2017
 */

#include <stdint.h>
#include <stdbool.h>

#include <criterion/criterion.h>

#include "problems.hpp"

TestSuite(ConnectedComponents);

Test(ConnectedComponents, CanCreateSingleGraph)
{
  graph_connected_components_init();
  graph_connected_components_add(0, 1);
  graph_connected_components_add(0, 8);
  graph_connected_components_add(0, 9);
  uint32_t *vertexes = graph_connected_components_connected_vertexes(0);
  uint32_t expected[] = {1,8,9};
  for(uint32_t i = 0; i < 3; i++){
    cr_assert_eq(vertexes[i], expected[i]);
  }
}
