/**
 * File:  test_depth_first_search.c
 * Author: ymiyamoto
 *
 * Created on Wed Jun 21 10:08:36 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

#define BUF_SIZE 256

static uint32_t called;
static uint32_t buffer[BUF_SIZE];
static uint32_t at;

static void callback(uint32_t val)
{
  called++;
  buffer[at] = val;
  at++;
}

static void setup(void)
{
  called = 0x00;
  at = 0x00;
}

TestSuite(DepthFirstSearch, .init = setup);

Test(DepthFirstSearch, ShouldNotCallCallbackFunc)
{
  graph_depth_first_search(NULL, 0, callback, NULL);
  cr_assert_eq(called, 0);
}

Test(DepthFirstSearch, ShouldCallCallbackFuncWhenVertexIsOne)
{
  graph_vertex_t vertexes[] = {{.index = 1, .len = 0, .array = {0}, .color = WHITE}};

  graph_depth_first_search(vertexes, 1, callback, NULL);
  cr_assert_eq(called, 1);
  cr_assert_eq(buffer[0], 1);
}

Test(DepthFirstSearch, ShouldCallCallbackFuncWhenVertexIsMany)
{
  graph_vertex_t vertexes[] = {
      {.index = 1, .len = 2, .array = {2, 3}, .color = WHITE}, {.index = 2, .len = 2, .array = {3, 4}, .color = WHITE},
      {.index = 3, .len = 1, .array = {5}, .color = WHITE},    {.index = 4, .len = 1, .array = {6}, .color = WHITE},
      {.index = 5, .len = 1, .array = {6}, .color = WHITE},    {.index = 6, .len = 0, .array = {0}, .color = WHITE},
  };

  uint32_t expect[] = {1, 2, 3, 5, 6, 4};
  graph_depth_first_search(vertexes, 6, callback, NULL);
  cr_assert_eq(called, 6);
  for (uint32_t i = 0; i < UTIL_ARRAY_SIZE(expect); i++) {
    cr_assert_eq(buffer[i], expect[i], "%d:%d and %d", i, buffer[i], expect[i]);
  }
}
