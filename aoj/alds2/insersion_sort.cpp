///
// File:  insersion_sort.cpp
// Author: ymiyamoto
//
// Created on Wed Jun 28 02:26:26 2017
//

#include <cassert>
#include <cstdint>
#include <stdexcept>
#include <utility>

#include "problems.hpp"

using namespace std;

void insersion_sort(int32_t array[], size_t size, void (*callback)(int32_t arrary[], size_t size))
{
  if (array == nullptr) throw runtime_error("array is null");

  for (int32_t i = 0; i < size; i++) {
    for (int32_t j = i; j >= 1; j--) {
      if (array[j - 1] > array[j]) {
        swap(array[j - 1], array[j]);
      }
    }
    if (callback != nullptr) {
      callback(array, size);
    }
  }
}

#if !defined(TEST)
#include <iostream>
static void callback(int32_t array[], size_t size)
{
  for (uint32_t i = 0; i < size; i++) {
    if (i != 0) cout << " ";
    cout << array[i];
  }
  cout << endl;
}

int32_t main(void)
{
  int32_t num;
  cin >> num;

  int32_t array[1024];
  for (uint32_t i = 0; i < num; i++) {
    cin >> array[i];
  }
  insersion_sort(array, num, callback);

  return 0;
}
#endif
