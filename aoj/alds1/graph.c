/**
 * File:  graph.c
 * Author: ymiyamoto
 *
 * Created on Tue Jun 20 12:28:10 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "problems.h"

bool graph_converts_to_matrix(graph_vertex_t vertexes[], size_t len, uint32_t matrix[][100])
{
  if ((vertexes == NULL) || (len == 0)) return false;
  uint32_t i, j;
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++) {
      matrix[i][j] = 0;
    }
  }

  uint32_t n, m;
  for (n = 0; n < len; n++) {
    graph_vertex_t v = vertexes[n];
    for (m = 0; m < v.len; m++) {
      matrix[v.index - 1][v.array[m] - 1] = 1;
    }
  }

  return true;
}

#if !defined(TEST)
#include <stdio.h>
static graph_vertex_t vertexes[GRAPH_MATRIX_SIZE];
int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);
  uint32_t i;
  for (i = 0; i < num; i++) {
    graph_vertex_t *v = &vertexes[i];

    scanf("%d", &v->index);
    scanf("%lu", &v->len);
    uint32_t j;
    for (j = 0; j < v->len; j++) {
      scanf("%d", &v->array[j]);
    }
  }

  uint32_t matrix[GRAPH_MATRIX_SIZE][GRAPH_MATRIX_SIZE];
  graph_converts_to_matrix(vertexes, num, matrix);
  for (i = 0; i < num; i++) {
    uint32_t j;
    for (j = 0; j < num; j++) {
      if (j != 0) printf(" ");
      printf("%d", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
#endif
