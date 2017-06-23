/**
 * File:  test_graph.c
 * Author: ymiyamoto
 *
 * Created on Tue Jun 20 12:15:10 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

static uint32_t matrix[GRAPH_MATRIX_SIZE][GRAPH_MATRIX_SIZE];

static void setup(void)
{
  for (int32_t i = 0; i < GRAPH_MATRIX_SIZE; i++) {
    for (int32_t j = 0; j < GRAPH_MATRIX_SIZE; j++) {
      matrix[i][j] = 0xffffffff;
    }
  }
}

static void assert_matrix(size_t len, const uint32_t const expect[][GRAPH_MATRIX_SIZE])
{
  for (int32_t i = 0; i < len; i++) {
    for (int32_t j = 0; j < len; j++) {
      cr_assert_eq(matrix[i][j], expect[i][j]);
    }
  }
}

TestSuite(Graph, .init = setup);

Test(Graph, ShouldReturnErrorWhenVertexsSizeIs0)
{
  bool ret = graph_converts_to_matrix(NULL, 0, matrix);
  cr_assert_not(ret);
}

Test(Graph, ShouldReturnErrorWhenVertexesArrayIsNull)
{
  bool ret = graph_converts_to_matrix(NULL, 3, matrix);
  cr_assert_not(ret);
}

Test(Graph, ShouldReturnNoEdgeMatrixWhenVertexesHaveNoEdges)
{
  graph_vertex_t vertexes[] = {
      {
          .index = 1, .len = 0, .array = {0},
      },
      {
          .index = 2, .len = 0, .array = {0},
      },
      {
          .index = 3, .len = 0, .array = {0},
      },
  };
  const uint32_t expect[][GRAPH_MATRIX_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  bool ret = graph_converts_to_matrix(vertexes, UTIL_ARRAY_SIZE(vertexes), matrix);

  cr_assert(ret);
  assert_matrix(UTIL_ARRAY_SIZE(vertexes), expect);
}

Test(Graph, ShouldReturnEdgeExistingMatrixWhenVertexesSomeEdges)
{
  graph_vertex_t vertexes[] = {
      {
          .index = 1, .len = 2, .array = {2, 3},
      },
      {
          .index = 2, .len = 1, .array = {1},
      },
      {
          .index = 3, .len = 1, .array = {3},
      },
  };
  const uint32_t expect[][GRAPH_MATRIX_SIZE] = {{0, 1, 1}, {1, 0, 0}, {0, 0, 1}};
  bool ret = graph_converts_to_matrix(vertexes, UTIL_ARRAY_SIZE(vertexes), matrix);

  cr_assert(ret);
  assert_matrix(UTIL_ARRAY_SIZE(vertexes), expect);
}
