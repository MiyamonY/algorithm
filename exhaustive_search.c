/**
 * File:  exhaustive_search.c
 * Author: ymiyamoto
 *
 * Created on Wed May 10 12:41:50 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "problems.h"

bool exhaustive_search_search(int32_t data[], size_t size, int32_t find)
{
  uint32_t i;

  if (find == 0) return true;

  if ((data == NULL) || (size == 0)) return false;

  if (exhaustive_search_search(&data[1], size - 1, find)) {
    return true;
  }

  if (((find - data[0]) >= 0) && exhaustive_search_search(&data[1], size - 1, find - data[0])) {
    return true;
  }

  return false;
}

#if !defined(TEST)
#include <stdio.h>
int32_t main(void)
{
  int32_t buf1[20];
  int32_t num1;
  scanf("%d", &num1);

  int32_t i;
  for (i = 0; i < num1; i++) {
    scanf("%d", &buf1[i]);
  }

  int32_t num2;
  scanf("%d", &num2);
  int32_t buf2[200];

  for (i = 0; i < num2; i++) {
    scanf("%d", &buf2[i]);
  }

  for (i = 0; i < num2; i++) {
    if (exhaustive_search_search(buf1, num1, buf2[i])) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }

  return 0;
}
#endif
