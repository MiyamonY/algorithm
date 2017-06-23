/**
 * File:  test_graphe_breadth_first_search.c
 * Author: ymiyamoto
 *
 * Created on Thu Jun 22 09:56:55 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"

static uint32_t count;
static void callback(uint32_t index)
{
  count++;
}

static void setup(void)
{
  count = 0;
}

TestSuite(GraphBreadthFirstSearch, .init = setup);

Test(GraphBreadthFirstSearch, ShouldNotCallCallbackFunc);
{
  graph_breadth_first_search(NULL, 3, callback);
  cr_assert_eq(count, 0);

  graph_vertex_t vertex = {};
  graph_breadth_first_search(&vertex, 0, callback);
  cr_assert_eq(count, 0);
}
