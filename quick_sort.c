/**
 * File:  quick_sort.c
 * Author: ymiyamoto
 *
 * Created on Fri May 19 02:47:56 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "problems.h"
#include "util.h"

static size_t _partition(card_t data[], size_t size)
{
  int64_t pivot = data[size - 1].num;

  size_t index = 0;
  uint32_t i;
  for (i = 0; i < size - 1; i++) {
    if (data[i].num <= pivot) {
      UTIL_SWAP(data[i], data[index]);
      index++;
    }
  }
  UTIL_SWAP(data[index], data[size - 1]);
  return index;
}

#include <stdio.h>

void quick_sort(card_t data[], size_t size)
{
  if (data == NULL) return;

  if (size <= 1) return;

  size_t index = _partition(data, size);
  quick_sort(data, index);
  quick_sort(&data[index], size - index);

  return;
}
