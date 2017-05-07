/**
 * File:  binary_search.c
 * Author: ymiyamoto
 *
 * Created on Sun May  7 17:08:32 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "problems.h"

static bool binary_search(int32_t data[], size_t size, int32_t f)
{
  if (size == 0) {
    return false;
  } else if (size == 1) {
    return data[0] == f;
  } else {
    int32_t mid = size / 2;
    int32_t pivot = data[mid];
    if (f < pivot) {
      return binary_search(data, mid, f);
    } else if (pivot < f) {
      return binary_search(&data[mid], size - mid, f);
    } else {
      return true;
    }
  }

  return false;
}
size_t binary_search_find(int32_t data[], size_t data_size, int32_t find[], size_t find_size)
{
  if ((data == NULL) || (find == NULL)) {
    return 0;
  }

  size_t found = 0;
  int32_t i;
  for (i = 0; i < find_size; i++) {
    int32_t f = find[i];
    if (binary_search(data, data_size, f)) {
      found++;
    }
  }

  return found;
}

#if !defined(TEST)

#include <stdio.h>
static int32_t data[100000];
static int32_t find[50000];

int32_t main(void)
{
  int32_t num1;
  scanf("%d", &num1);
  int32_t i;
  for (i = 0; i < num1; i++) {
    scanf("%d", &data[i]);
  }

  int32_t num2;
  scanf("%d", &num2);

  for (i = 0; i < num2; i++) {
    scanf("%d", &find[i]);
  }

  size_t n = binary_search_find(data, num1, find, num2);

  printf("%lu\n", n);

  return 0;
}
#endif
