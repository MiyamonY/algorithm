/**
 * File:  quick_sort.c
 * Author: ymiyamoto
 *
 * Created on Fri May 19 02:47:56 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

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

static void merge(card_t cards1[], card_t cards2[], size_t cards1_len, size_t cards2_len)
{
  uint32_t i;
  card_t *data1 = malloc(sizeof(card_t) * (cards1_len + 1));
  card_t *data2 = malloc(sizeof(card_t) * (cards2_len + 1));

  if ((data1 == NULL) || (data2 == NULL)) goto err;

  for (i = 0; i < cards1_len; i++) {
    data1[i] = cards1[i];
  }
  data1[cards1_len].num = INT64_MAX;

  for (i = 0; i < cards2_len; i++) {
    data2[i] = cards2[i];
  }
  data2[cards2_len].num = INT64_MAX;

  size_t len = cards1_len + cards2_len;
  size_t index1 = 0, index2 = 0;

  for (i = 0; i < len; i++) {
    if (data1[index1].num <= data2[index2].num) {
      cards1[i] = data1[index1];
      index1++;
    } else {
      cards1[i] = data2[index2];
      index2++;
    }
  }

  free(data1);
  free(data2);
  return;

err:
  perror("malloc error");
  exit(1);
}

static void quick_sort_merge_sort(card_t data[], size_t size)
{
  if (size <= 1) return;

  size_t index = size / 2;
  quick_sort_merge_sort(data, index);
  quick_sort_merge_sort(&data[index], size - index);
  merge(data, &data[index], index, size - index);
}

void quick_sort(card_t data[], size_t size)
{
  if (data == NULL) return;

  if (size <= 1) return;

  size_t index = _partition(data, size);
  quick_sort(data, index);
  quick_sort(&data[index], size - index);

  return;
}

bool quick_sort_is_stable(card_t cards[], size_t len)
{
  card_t *cards2 = malloc(sizeof(card_t) * len);
  memcpy(cards2, cards, sizeof(card_t) * len);

  quick_sort(cards, len);
  quick_sort_merge_sort(cards2, len);

  uint32_t i;
  for (i = 0; i < len; i++) {
    if ((cards[i].num != cards2[i].num) || (cards[i].design != cards2[i].design)) {
      return false;
    }
  }

  return true;
}

#if !defined(TEST)
#include <stdio.h>

static card_t cards[100000];

int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);

  uint32_t i;
  for (i = 0; i < num; i++) {
    uint8_t design[1];
    int64_t number;
    scanf("%s %ld", design, &number);
    cards[i].num = number;
    cards[i].design = design[0];
  }

  bool ret = quick_sort_is_stable(cards, num);

  if (ret) {
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  for (i = 0; i < num; i++) {
    printf("%c %ld\n", cards[i].design, cards[i].num);
  }

  return 0;
}
#endif
