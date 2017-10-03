///
// File:  alds1_2_b.cpp
// Author: ymiyamoto
//
// Created on Wed Oct  4 01:21:55 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static vector<uint32_t> array;

uint32_t selection_sort()
{
  uint32_t count = 0;

  for (uint32_t i = 0; i < array.size(); i++) {
    uint32_t min = array[i];
    uint32_t min_index = i;
    for (uint32_t j = i; j < array.size(); j++) {
      if (array[j] < min) {
        min = array[j];
        min_index = j;
      }
    }
    if (min_index != i) {
      swap(array[i], array[min_index]);
      count++;
    }
  }

  return count;
}

int32_t main()
{
  uint32_t N;
  cin >> N;

  for (uint32_t i = 0; i < N; i++) {
    uint32_t val;
    cin >> val;
    array.push_back(val);
  }

  uint32_t count = selection_sort();

  for (uint32_t i = 0; i < array.size(); i++) {
    if (i != 0) cout << " ";
    cout << array[i];
  }

  cout << endl << count << endl;

  return 0;
}
