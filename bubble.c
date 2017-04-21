/**
 * File:  bubble.c
 * Author: ymiyamoto
 *
 * Created on Sat Apr 22 04:35:20 2017
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "util.h"

#define BUF_SIZE 100

uint32_t bubble_sort(int32_t buf[], size_t size)
{
  uint32_t num = 0;
  uint16_t i = size;
  while (i--) {
    uint16_t j;
    for (j = 0; j < i; j++) {
      if (buf[j] > buf[j + 1]) {
        UTIL_SWAP(buf[j], buf[j + 1]);
        num++;
      }
    }
  }

  return num;
}

#if !defined(TEST)
int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);
  int32_t buf[BUF_SIZE];
  uint16_t i;
  for (i = 0; i < num; i++) {
    scanf("%d", &buf[i]);
  }

  uint32_t cnt = bubble_sort(buf, num);

  UTIL_PRINT_ARRAY(buf, num);
  printf("%d\n", cnt);

  return 0;
}
#endif
