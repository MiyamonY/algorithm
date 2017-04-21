/**
 * File:  insertion.c
 * Author: ymiyamoto
 *
 * Created on Fri Apr 21 15:42:44 2017
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 100

#define SWAP(a, b)                                                                                                                         \
  {                                                                                                                                        \
    typeof(a) _x = a;                                                                                                                      \
    a = b;                                                                                                                                 \
    b = _x;                                                                                                                                \
  }

void print_arr(int32_t buf[], size_t size)
{
  int32_t i;
  for (i = 0; (size_t)i < size; i++) {
    if (i != 0) {
      printf(" ");
    }
    printf("%d", buf[i]);
  }
  printf("\n");

  return;
}

void insertion_sort(int32_t buf[], size_t size)
{
  uint8_t i;
  for (i = 0; i < size; i++) {
    uint8_t j;
    for (j = i; 0 < j; j--) {
      if (buf[j - 1] > buf[j]) {
        SWAP(buf[j - 1], buf[j]);
      }
    }
    print_arr(buf, size);
  }

  return;
}

#if !defined(TEST)
int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);

  int32_t buf[BUF_SIZE];

  uint8_t i;
  for (i = 0; i < num; i++) {
    scanf("%d", &buf[i]);
  }

  insertion_sort(buf, (size_t)num);

  return 0;
}
#endif
