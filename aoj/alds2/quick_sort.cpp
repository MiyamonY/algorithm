///
// File:  quick_sort.cpp
// Author: ymiyamoto
//
// Created on Wed Jul  5 19:57:22 2017
//

#include <cstdint>
#include <utility>
#include <vector>

using namespace std;

struct card_t {
  uint32_t num;
  char color;
};

static void merge(card_t vec[], size_t start, size_t mid, size_t end)
{
  uint32_t left_num = mid - start;
  uint32_t right_num = end - mid;
  card_t *left_vec = new card_t[left_num + 1];
  card_t *right_vec = new card_t[right_num + 1];

  for (uint32_t i = 0; i < left_num; i++) {
    left_vec[i] = vec[i + start];
  }
  left_vec[left_num].num = UINT32_MAX;

  for (uint32_t i = 0; i < right_num; i++) {
    right_vec[i] = vec[i + mid];
  }
  right_vec[right_num].num = UINT32_MAX;

  for (uint32_t i = start, right_index = 0, left_index = 0; i < end; i++) {
    if (left_vec[left_index].num < right_vec[right_index].num) {
      vec[i] = left_vec[left_index];
      left_index++;
    } else {
      vec[i] = right_vec[right_index];
      right_index++;
    }
  }

  delete[] left_vec;
  delete[] right_vec;
}

void quick_sort_merge_sort(card_t vec[], size_t start, size_t end)
{
  if (start < end - 1) {
    size_t mid = (start + end) / 2;
    quick_sort_merge_sort(vec, start, mid);
    quick_sort_merge_sort(vec, mid, end);
    merge(vec, start, mid, end);
  }
}

static uint32_t partition(card_t vec[], size_t start, size_t end)
{
  uint32_t mid = vec[end].num;
  uint32_t less_index = start;
  for (uint32_t i = start; i < end; i++) {
    if (vec[i].num <= mid) {
      swap(vec[i], vec[less_index]);
      less_index++;
    }
  }
  swap(vec[end], vec[less_index]);
  return less_index;
}

void quick_sort_sort(card_t vec[], size_t start, size_t end)
{
  if (start < end) {
    uint32_t mid = partition(vec, start, end);

    quick_sort_sort(vec, start, mid - 1);
    quick_sort_sort(vec, mid + 1, end);
  }
}

#if !defined(TEST)
#include <cstdio>

vector<card_t> cards1, cards2;

int32_t main()
{
  uint32_t len;
  scanf("%u", &len);

  for (uint32_t i = 0; i < len; i++) {
    uint32_t num;
    char color[1];
    scanf("%s %d", color, &num);
    card_t c = {.num = num, .color = color[0]};
    cards1.push_back(c);
    cards2.push_back(c);
  }

  quick_sort_sort(&cards1[0], 0, cards1.size() - 1);
  quick_sort_merge_sort(&cards2[0], 0, cards2.size());

  bool issame = true;
  for (uint32_t i = 0; i < cards1.size(); i++) {
    if (cards1[i].color != cards2[i].color) {
      issame = false;
    }
  }

  if (issame) {
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  for (uint32_t i = 0; i < cards1.size(); i++) {
    printf("%c %d\n", cards1[i].color, cards1[i].num);
  }

  return 0;
}
#endif
