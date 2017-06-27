/**
 * File:  graph_breadth_first_search.c
 * Author: ymiyamoto
 *
 * Created on Thu Jun 22 10:00:17 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "problems.h"

typedef struct {
  graph_vertex_t *vertex;
  uint32_t timer;
} graph_bread_first_search_queue_t;

void graph_breadth_first_search(graph_vertex_t *vertexes, size_t num, graph_breadth_first_search_callback_t callback)
{
  graph_bread_first_search_queue_t queue[GRAPH_MATRIX_SIZE];
  int32_t queue_top = 0, queue_bottom = 0;

  if ((vertexes == NULL) || (num == 0)) return;

  vertexes[0].color = GRAY;
  callback(vertexes[0].index, 0);
  queue[queue_top].vertex = &vertexes[0];
  queue[queue_top].timer = 0;
  queue_top++;

  while (queue_top != queue_bottom) {
    graph_vertex_t *vertex = queue[queue_bottom].vertex;
    uint32_t timer = queue[queue_bottom].timer;
    queue_bottom++;
    timer++;
    uint32_t j;
    for (j = 0; j < vertex->len; j++) {
      graph_vertex_t *next = &vertexes[vertex->array[j] - 1];
      if (next->color == WHITE) {
        queue[queue_top].vertex = next;
        queue[queue_top].timer = timer;
        queue_top++;
        next->color = GRAY;
        callback(next->index, timer);
      }
    }
    vertex->color = BLACK;
  }
  return;
}

#if !defined(TEST)
#include <stdio.h>

static graph_vertex_t vertexes[GRAPH_MATRIX_SIZE];

static int32_t timestamp[GRAPH_MATRIX_SIZE];

static void callback(uint32_t index, uint32_t time)
{
  timestamp[index - 1] = time;
}

int32_t main(void)
{
  uint32_t i;
  for (i = 0; i < GRAPH_MATRIX_SIZE; i++) {
    timestamp[i] = -1;
  }

  int32_t num;
  scanf("%d", &num);

  for (i = 0; i < num; i++) {
    scanf("%u", &vertexes[i].index);
    scanf("%lu", &vertexes[i].len);
    uint32_t j;
    for (j = 0; j < vertexes[i].len; j++) {
      scanf("%d", &vertexes[i].array[j]);
    }
  }

  graph_breadth_first_search(vertexes, num, callback);

  for (i = 0; i < num; i++) {
    printf("%d %d\n", i + 1, timestamp[i]);
  }

  return 0;
}
#endif
