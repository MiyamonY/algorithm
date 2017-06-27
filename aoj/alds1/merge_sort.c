/**
 * File:  merge_sort.c
 * Author: ymiyamoto
 *
 * Created on Sun May 14 00:34:08 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static size_t merge(int64_t left[], size_t size_left, int64_t right[], size_t size_right)
{
  size_t len = size_left + size_right;
  int64_t *buf = (int64_t *)malloc(sizeof(int64_t) * len);

  size_t count = 0;
  size_t left_count = 0;
  size_t right_count = 0;

  uint32_t i;
  for (i = 0; i < len; i++) {
    if ((left_count < size_left) && (right_count < size_right)) {
      if (left[left_count] < right[right_count]) {
        buf[i] = left[left_count];
        left_count++;
      } else {
        buf[i] = right[right_count];
        right_count++;
      }
    } else if (left_count < size_left) {
      buf[i] = left[left_count];
      left_count++;
    } else {
      buf[i] = right[right_count];
      right_count++;
    }
    count++;
  }

  memcpy(left, buf, sizeof(int64_t) * len);
  free(buf);
  return count;
}

size_t merge_sort(int64_t data[], size_t len)
{
  if (data == NULL) return 0;

  if (len <= 1) {
    return 0;
  } else {
    size_t half = len / 2;
    size_t left = merge_sort(data, half);
    size_t right = merge_sort(&data[half], len - half);
    size_t num = merge(data, half, &data[half], len - half);
    return left + right + num;
  }
}

#if !defined(TEST)
#include <stdio.h>
static int64_t data[524288];

int32_t main(void)
{
  size_t len;
  scanf("%lu", &len);
  uint32_t i;
  for (i = 0; i < len; i++) {
    scanf("%ld", &data[i]);
  }

  size_t num = merge_sort(data, len);
  for (i = 0; i < len; i++) {
    if (i != 0) printf(" ");
    printf("%ld", data[i]);
  }
  printf("\n");

  printf("%lu\n", num);
  return 0;
}
#endif
