/**
 * File:  selection.c
 * Author: ymiyamoto
 *
 * Created on Sun Apr 23 12:58:10 2017
 */

#include <stdint.h>
#include <stdio.h>

#include "util.h"

#define BUF_SIZE 256

uint32_t selection_sort(int32_t buf[], size_t size)
{
  uint32_t count = 0;

  uint32_t i;
  for (i = 0; i < size; i++) {
    uint32_t min_idx = i;
    uint32_t j;
    for (j = i + 1; j < size; j++) {
      if (buf[j] < buf[min_idx]) {
        min_idx = j;
      }
    }

    if (i != min_idx) {
      UTIL_SWAP(buf[i], buf[min_idx]);
      count++;
    }
  }

  return count;
}

#if !defined(TEST)
int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);
  int32_t buf[BUF_SIZE];
  uint32_t i;
  for (i = 0; i < num; i++) {
    scanf("%d", &buf[i]);
  }

  uint32_t count = selection_sort(buf, num);

  UTIL_PRINT_ARRAY(buf, num);
  printf("%d\n", count);

  return 0;
}
#endif
