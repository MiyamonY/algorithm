/**
 * File:  graph_depth_first_search.c
 * Author: ymiyamoto
 *
 * Created on Wed Jun 21 10:41:36 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "problems.h"

static void aux(graph_vertex_t *vertexes, uint32_t index, graph_depth_first_search_callback_t callback_pre,
                graph_depth_first_search_callback_t callback_post)
{
  graph_vertex_t *vertex = &vertexes[index - 1];
  vertex->color = GRAY;
  if (callback_pre) callback_pre(vertex->index);

  if (vertex->len > 0) {
    uint32_t i;
    for (i = 0; i < vertex->len; i++) {
      uint32_t next_vertex_index = vertex->array[i];
      if (vertexes[next_vertex_index - 1].color == WHITE) {
        aux(vertexes, next_vertex_index, callback_pre, callback_post);
      }
    }
  }
  if (callback_post) callback_post(vertex->index);
}

void graph_depth_first_search(graph_vertex_t *vertexes, size_t num, graph_depth_first_search_callback_t callback_pre,
                              graph_depth_first_search_callback_t callback_post)
{
  if ((vertexes == NULL) || (num == 0)) return;

  uint32_t i;
  for (i = 0; i < num; i++) {
    if (vertexes[i].color == WHITE) {
      aux(vertexes, i + 1, callback_pre, callback_post);
    }
  }

  return;
}

#if !defined(TEST)
#include <stdio.h>
#define VERTEXES 256
static graph_vertex_t vertexes[VERTEXES];
static uint32_t cnt = 0;
static uint32_t timestamp[VERTEXES][2];

static void callback_pre(uint32_t index)
{
  cnt++;
  timestamp[index - 1][0] = cnt;
}

static void callback_post(uint32_t index)
{
  cnt++;
  timestamp[index - 1][1] = cnt;
}

int32_t main(void)
{
  uint32_t num;
  scanf("%u", &num);

  uint32_t i, j;
  for (i = 0; i < num; i++) {
    scanf("%u", &vertexes[i].index);
    scanf("%lu", &vertexes[i].len);
    for (j = 0; j < vertexes[i].len; j++) {
      scanf("%u", &vertexes[i].array[j]);
    }
    vertexes[i].color = WHITE;
  }

  graph_depth_first_search(vertexes, num, callback_pre, callback_post);

  for (i = 0; i < num; i++) {
    printf("%u %u %u\n", i + 1, timestamp[i][0], timestamp[i][1]);
  }
  return 0;
}
#endif
