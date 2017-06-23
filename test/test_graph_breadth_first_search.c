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
#include "util.h"

static uint32_t count;

static uint32_t timestamp[GRAPH_MATRIX_SIZE];

static void callback(uint32_t index, uint32_t time)
{
  count++;
  printf("%d: time is %d\n", index, time);
  timestamp[index - 1] = time;
}

static void setup(void)
{
  count = 0;
  for (uint32_t i = 0; i < GRAPH_MATRIX_SIZE; i++) {
    timestamp[i] = 0;
  }
}

TestSuite(GraphBreadthFirstSearch, .init = setup);

Test(GraphBreadthFirstSearch, ShouldNotCallCallbackFunc)
{
  graph_breadth_first_search(NULL, 3, callback);
  cr_assert_eq(count, 0);

  graph_vertex_t vertex = {};
  graph_breadth_first_search(&vertex, 0, callback);
  cr_assert_eq(count, 0);
}

Test(GraphBreadthFirstSearch, ShouldCallCallbackFuncOnce)
{
  graph_vertex_t vertexes[] = {{.index = 1, .len = 0, .array = {0}, .color = WHITE}};
  graph_breadth_first_search(vertexes, UTIL_ARRAY_SIZE(vertexes), callback);
  cr_assert_eq(count, 1);
}

Test(GraphBreadthFirstSearch, ShouldCallCallbackFuncMany)
{
  graph_vertex_t vertexes[] = {{.index = 1, .len = 2, .array = {2, 4}, .color = WHITE},
                               {.index = 2, .len = 1, .array = {4}, .color = WHITE},
                               {.index = 3, .len = 0, .array = {0}, .color = WHITE},
                               {.index = 4, .len = 1, .array = {3}, .color = WHITE}};
  uint32_t expect[] = {0, 1, 2, 1};
  graph_breadth_first_search(vertexes, UTIL_ARRAY_SIZE(vertexes), callback);
  cr_assert_eq(count, 4);

  for (uint32_t i = 0; i < UTIL_ARRAY_SIZE(expect); i++) {
    cr_assert_eq(timestamp[i], expect[i], "%d:%d is not %d", i + 1, timestamp[i], expect[i]);
  }
}

Test(GraphBreadthFirstSearch, ShouldCallCallbackFuncManyWhenIsolatedVertexExists)
{
  graph_vertex_t vertexes[] = {{.index = 1, .len = 2, .array = {2, 4}, .color = WHITE},
                               {.index = 2, .len = 1, .array = {4}, .color = WHITE},
                               {.index = 3, .len = 0, .array = {0}, .color = WHITE},
                               {.index = 4, .len = 1, .array = {3}, .color = WHITE},
                               {.index = 5, .len = 0, .array = {0}, .color = WHITE}};

  uint32_t expect[] = {0, 1, 2, 1, 3};
  graph_breadth_first_search(vertexes, UTIL_ARRAY_SIZE(vertexes), callback);
  cr_assert_eq(count, 5);

  for (uint32_t i = 0; i < UTIL_ARRAY_SIZE(expect); i++) {
    cr_assert_eq(timestamp[i], expect[i], "%d:%d is not %d", i + 1, timestamp[i], expect[i]);
  }
}
