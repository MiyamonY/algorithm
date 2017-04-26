/**
 * File:  stable.c
 * Author: ymiyamoto
 *
 * Created on Wed Apr 26 09:17:24 2017
 */

#include <stdint.h>
#include <stdlib.h>

#include "util.h"

uint32_t stable_bubble_sort(char *buf[], const size_t size)
{
  if (buf == NULL) return 0;

  uint32_t i;
  uint32_t cnt = 0;
  for (i = 0; i < size; i++) {
    uint32_t j;
    for (j = i; j < size; j++) {
      if (buf[i][1] > buf[j][1]) {
        UTIL_SWAP(buf[i], buf[j]);
        cnt++;
      }
    }
  }
  return cnt;
}

uint32_t stable_selection_sort(char *buf[], const size_t size)
{
  if (buf == NULL) return 0;

  uint32_t cnt = 0;
  uint32_t i;
  for (i = 0; i < size; i++) {
    uint32_t min = i;
    uint32_t j;
    for (j = i; j < size; j++) {
      if (buf[j][1] < buf[min][1]) {
        min = j;
      }
    }
    UTIL_SWAP(buf[i], buf[min]);
    if (i != min) {
      cnt++;
    }
  }

  return cnt;
}
