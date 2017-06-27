/**
 * File:  partition.c
 * Author: ymiyamoto
 *
 * Created on Tue May 16 03:12:15 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "problems.h"
#include "util.h"

size_t partition(int32_t data[], size_t len)
{
  size_t index = 0;

  if (data == NULL) return index;

  int32_t pivot = data[len - 1];

  uint32_t i;
  for (i = 0; i < len - 1; i++) {
    if (data[i] <= pivot) {
      UTIL_SWAP(data[index], data[i]);
      index++;
    }
  }

  UTIL_SWAP(data[index], data[len - 1]);
  return index;
}

#if !defined(TEST)
#include <stdio.h>
static int32_t data[1000000];

int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);

  int32_t i;
  for (i = 0; i < num; i++) {
    scanf("%d", &data[i]);
  }

  size_t index = partition(data, num);

  for (i = 0; i < num; i++) {
    if (i != 0) printf(" ");

    if (i == index) {
      printf("[%d]", data[i]);
    } else {
      printf("%d", data[i]);
    }
  }

  printf("\n");

  return 0;
}

#endif
