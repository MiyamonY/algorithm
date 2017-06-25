/**
 * File:  test_minimum_spanning_tree.c
 * Author: ymiyamoto
 *
 * Created on Sun Jun 25 04:41:42 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"

static size_t weight = 0xff;

static void setup(void)
{
  weight = 0xff;
}

TestSuite(MinimumSpanningTree, .init = setup);

Test(MinimumSpanningTree, WhenGraphIsNull)
{
  cr_assert_not(minimum_spannig_tree(NULL, 1, &weight));
  cr_assert_eq(weight, 0);
}

Test(MinimumSpanningTree, WhenVertexSizeIs1ThenReturns1)
{
  int32_t graph[MINIMUM_SPANNING_TREE_GRAPH_SIZE][MINIMUM_SPANNING_TREE_GRAPH_SIZE] = {
      {1},
  };

  cr_assert(minimum_spannig_tree(graph, 1, &weight));
  cr_assert_eq(weight, 0);
}

Test(MinimumSpanningTree, WhenVertexSizeIsNThenReturnsMinimumWeight)
{
  int32_t graph[MINIMUM_SPANNING_TREE_GRAPH_SIZE][MINIMUM_SPANNING_TREE_GRAPH_SIZE] = {
      {INT32_MAX, 4, 3, INT32_MAX, 1, 10},                 /* 0 */
      {4, INT32_MAX, 5, INT32_MAX, INT32_MAX, INT32_MAX},  /* 1 */
      {3, 5, INT32_MAX, 5, 2, INT32_MAX},                  /* 2 */
      {INT32_MAX, INT32_MAX, 5, INT32_MAX, 6, INT32_MAX},  /* 3 */
      {1, INT32_MAX, 2, 6, INT32_MAX, 3},                  /* 4 */
      {10, INT32_MAX, INT32_MAX, INT32_MAX, 3, INT32_MAX}, /* 5 */
  };

  cr_assert(minimum_spannig_tree(graph, 6, &weight));
  cr_assert_eq(weight, 15);
}
