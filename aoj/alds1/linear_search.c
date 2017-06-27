/**
 * File:  linear_search.c
 * Author: ymiyamoto
 *
 * Created on Sun May  7 16:25:38 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

size_t linear_search_find(int32_t data[], size_t data_size, int32_t find[], size_t find_size)
{
  if ((data == NULL) || (find == NULL)) {
    return 0;
  }

  size_t found = 0;
  int32_t i = 0;
  for (i = 0; i < find_size; i++) {
    int32_t f = find[i];
    int32_t j;
    for (j = 0; j < data_size; j++) {
      if (data[j] == f) {
        found++;
        break;
      }
    }
  }
  return found;
}

static int32_t data[10000];
static int32_t find[500];

#if !defined(TEST)
int32_t main(void)
{
  int32_t num1, num2;
  scanf("%d", &num1);
  int32_t i;
  for (i = 0; i < num1; i++) {
    scanf("%d", &data[i]);
  }

  scanf("%d", &num2);
  for (i = 0; i < num2; i++) {
    scanf("%d", &find[i]);
  }

  size_t n = linear_search_find(data, num1, find, num2);
  printf("%lu\n", n);

  return 0;
}
#endif
