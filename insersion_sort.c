/**
 * File:  insersion_sort.c
 * Author: ymiyamoto
 *
 * Created on Sun Apr  2 21:50:11 2017
 */

#include <stdint.h>
#include <stdio.h>

#define MAX_DATA_NUM 100

void dump_array(int32_t num, int32_t *array)
{
  int i = 0;
  for (i = i; i < num; i++) {
    if (i > 0) printf(" ");
    printf("%d", array[i]);
  }

  printf("\n");
  return;
}

void insertion_sort(int32_t num, int32_t *data)
{
  int i;
  for (i = 0; i < num; i++) {
    int32_t v = data[i];
    int j = i - 1;
    while ((j >= 0) && data[j] > v) {
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = v;
    dump_array(num, data);
  }

  return;
}

int main(void)
{
  int32_t num;
  int32_t data[MAX_DATA_NUM];

#if defined(TEST)
  int32_t test[] = {5, 2, 4, 6, 1, 3};
  insertion_sort(6, test);
#else
  scanf("%d", &num);
  int i;
  for (i = 0; i < num; i++) {
    scanf("%d ", &data[i]);
  }

  insertion_sort(num, data);
#endif

  return 0;
}
