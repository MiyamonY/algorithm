///
// File:  selection_sort.cpp
// Author: ymiyamoto
//
// Created on Wed Jun 28 13:06:24 2017
//

#include <cstdint>
#include <stdexcept>
#include <utility>

#include "problems.hpp"

using namespace std;

void selection_sort(int32_t array[], size_t size, void (*callback)(int32_t arrary[], size_t size))
{
  if (size == 0) throw runtime_error("array size is 0");
  if (array == nullptr) throw runtime_error("array is null");

  for (uint32_t i = 0; i < size; i++) {
    uint32_t min = i;
    for (uint32_t j = i; j < size; j++) {
      if (array[j] < array[min]) {
        min = j;
      }
    }
    if (i != min) {
      swap(array[i], array[min]);
      if (callback != nullptr) {
        callback(array, size);
      }
    }
  }
}

#if !defined(TEST)
#include <iostream>
static uint32_t cnt;

static void callback(int32_t arrary[], size_t size)
{
  cnt++;
}

int32_t main(void)
{
  int32_t len;

  cin >> len;

  int32_t array[128];
  for (uint32_t i = 0; i < len; i++) {
    cin >> array[i];
  }

  selection_sort(array, len, callback);

  for (uint32_t i = 0; i < len; i++) {
    if (i != 0) cout << " ";
    cout << array[i];
  }
  cout << endl;

  cout << cnt << endl;
  return 0;
}
#endif
