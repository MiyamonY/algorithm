/**
 * File:  counting_sort.c
 * Author: ymiyamoto
 *
 * Created on Sun May 21 07:07:54 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problems.h"

struct counting_sort_t {
  uint32_t *counting_arr;
  size_t counting_arr_len;
};

static void free_counting_sort_object(counting_sort_t c)
{
  if (c != NULL) {
    free(c->counting_arr);
  }
  free(c);
}

counting_sort_t counting_sort_create(size_t n)
{
  counting_sort_t c = (counting_sort_t)malloc(sizeof(counting_sort_t));
  if (c == NULL) goto err;

  c->counting_arr_len = n;
  c->counting_arr = (uint32_t *)calloc(sizeof(uint32_t), n);
  if (c->counting_arr == NULL) goto err;

  return c;

err:
  free_counting_sort_object(c);
  perror("malloc error");
  exit(1);
}

void counting_sort_destroy(counting_sort_t c)
{
  free_counting_sort_object(c);
}

static void count_incidence(counting_sort_t c, uint64_t data[], size_t len)
{
  uint32_t i;
  for (i = 0; i < len; i++) {
    c->counting_arr[data[i]]++;
  }
}

static void calc_cumulative_sum(counting_sort_t c)
{
  uint32_t i;
  for (i = 1; i < c->counting_arr_len; i++) {
    c->counting_arr[i] += c->counting_arr[i - 1];
  }
}

static bool copy_array(uint64_t data[], size_t len, uint64_t **p)
{
  *p = (uint64_t *)malloc(sizeof(data[0]) * len);
  if (*p == NULL) return false;

  memcpy(*p, data, sizeof(data[0]) * len);

  return true;
}

void counting_sort(counting_sort_t c, uint64_t data[], size_t len)
{
  if (data == NULL) return;

  count_incidence(c, data, len);

  calc_cumulative_sum(c);

  uint64_t *aux;
  if (!copy_array(data, len, &aux)) goto err;

  int32_t i;
  for (i = len - 1; 0 <= i; i--) {
    uint32_t index = c->counting_arr[aux[i]];
    data[index - 1] = aux[i];
    c->counting_arr[aux[i]]--;
  }

  return;
err:
  counting_sort_destroy(c);
  perror("malloc error");
  exit(1);
}

#if !defined(TEST)
uint64_t data[2000000];
int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);

  counting_sort_t c = counting_sort_create(10001);

  int32_t i;
  for (i = 0; i < num; i++) {
    uint64_t val;
    scanf("%ld", &val);
    data[i] = val;
  }

  counting_sort(c, data, num);

  for (i = 0; i < num; i++) {
    if (i != 0) printf(" ");
    printf("%lu", data[i]);
  }
  printf("\n");

  counting_sort_destroy(c);

  return 0;
}
#endif
