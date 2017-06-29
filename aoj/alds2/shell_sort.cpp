///
// File:  shell_sort.cpp
// Author: ymiyamoto
//
// Created on Thu Jun 29 09:35:20 2017
//

#include <cstdint>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace std;

vector<uint32_t> gn;

static uint64_t cnt;

static void insersion_sort(int32_t array[], size_t size, uint32_t interval)
{
  for (int32_t i = interval; i < size; i++) {
    int32_t val = array[i];
    int j = i - interval;
    while ((j >= 0) && array[j] > val) {
      array[j + interval] = array[j];
      j -= interval;
      cnt++;
    }
    array[j + interval] = val;
    // for (int32_t j = ((size - 1 - i) / interval) * interval + i; j >= i + interval; j -= interval) {
    //   if (array[j - interval] > array[j]) {
    //     uint32_t val = array[j - interval];
    //     array[j - interval] = array[j];
    //     array[j] = val;
    //     cnt++;
    //   }
    // }
  }
}

void shell_sort(int32_t array[], size_t size, void (*callback)(int32_t array[], uint32_t index, uint32_t index2))
{
  if ((array == nullptr) || (size == 0)) throw runtime_error("arguments error");

  gn.push_back(1);
  for (uint32_t i = 4; i < size; i = 3 * i + 1) {
    gn.push_back(i);
  }

  for (int32_t i = gn.size() - 1; i >= 0; i--) {
    insersion_sort(array, size, gn[i]);
  }
}

#if !defined(TEST)
#include <cstdio>

#define MAX_ARRAY_SIZE 1000000
static int32_t array[MAX_ARRAY_SIZE];

int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);

  for (int32_t i = 0; i < num; i++) {
    scanf("%d", &array[i]);
  }

  shell_sort(array, num, nullptr);

  printf("%lu\n", gn.size());

  for (int32_t i = gn.size() - 1; i >= 0; i--) {
    printf("%d", gn[i]);
    if (i) printf(" ");
  }
  printf("\n");

  printf("%lu\n", cnt);

  for (int32_t i = 0; i < num; i++) {
    printf("%d\n", array[i]);
  }

  return 0;
}
#endif
