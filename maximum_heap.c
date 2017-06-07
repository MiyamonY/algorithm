/**
 * File:  maximum_heap.c
 * Author: ymiyamoto
 *
 * Created on Thu Jun  8 03:39:55 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "problems.h"
#include "util.h"

static int64_t left_node_value(int64_t arr[], int32_t index, size_t len)
{
  if ((index * 2) <= len) {
    return arr[index * 2 - 1];
  } else {
    return INT64_MIN;
  }
}

static int64_t right_node_value(int64_t arr[], int32_t index, size_t len)
{
  if (((index * 2) + 1) <= len) {
    return arr[(index * 2) + 1 - 1];
  } else {
    return INT64_MIN;
  }
}

static void max_heapfy(int64_t arr[], size_t len, int32_t index)
{
  int64_t current = arr[index - 1];
  int64_t left = left_node_value(arr, index, len);
  int64_t right = right_node_value(arr, index, len);

  int32_t max = UTIL_MAX(current, UTIL_MAX(left, right));
  int32_t not_heapfy_index = index;
  if (max == current) {
    return;
  } else if (max == left) {
    not_heapfy_index = index * 2;
    UTIL_SWAP(arr[index - 1], arr[not_heapfy_index - 1]);
  } else {
    not_heapfy_index = index * 2 + 1;
    UTIL_SWAP(arr[index - 1], arr[not_heapfy_index - 1]);
  }
  max_heapfy(arr, len, not_heapfy_index);
}

void maximum_heap_build(int64_t arr[], size_t len)
{
  int32_t i;
  for (i = (len + 1) / 2; 0 < i; i--) {
    max_heapfy(arr, len, i);
  }
}

#if !defined(TEST)
#include <stdio.h>
int64_t buf[2 ^ 500000];

int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);

  uint32_t i;
  for (i = 0; i < num; i++) {
    scanf("%ld", &buf[i]);
  }

  maximum_heap_build(buf, num);

  for (i = 0; i < num; i++) {
    printf(" %ld", buf[i]);
  }
  printf("\n");

  return 0;
}
#endif
