///
// File:  bubble_sort.cpp
// Author: ymiyamoto
//
// Created on Wed Jun 28 12:13:46 2017
//

#include <cstdint>
#include <stdexcept>
#include <utility>

#include "problems.hpp"

using namespace std;

void bubble_sort(int32_t array[], size_t size, void (*callback)(int32_t arrary[], size_t size))
{
  if (array == nullptr) throw runtime_error("array is null");

  for (uint32_t i = 0; i < size; i++) {
    for (uint32_t j = size - 1; j > i; j--) {
      if (array[j] < array[j - 1]) {
        swap(array[j - 1], array[j]);
        if (callback != nullptr) {
          callback(array, size);
        }
      }
    }
  }
}

#if !defined(TEST)
#include <iostream>
static int32_t count;
void callback(int32_t array[], size_t size)
{
  count++;
}

int32_t main(void)
{
  int32_t len;
  cin >> len;

  int32_t array[128];

  for (int32_t i = 0; i < len; i++) {
    cin >> array[i];
  }

  bubble_sort(array, len, callback);

  for (uint32_t i = 0; i < len; i++) {
    if (i != 0) cout << " ";
    cout << array[i];
  }
  cout << endl;

  cout << count << endl;

  return 0;
}
#endif
