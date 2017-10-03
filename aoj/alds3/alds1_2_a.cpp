///
// File:  alds1_2_a.cpp
// Author: ymiyamoto
//
// Created on Wed Oct  4 01:16:26 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
static vector<uint32_t> array;

static uint32_t bubble_sort()
{
  uint32_t count = 0;
  for (uint32_t i = 0; i < array.size(); i++) {
    for (uint32_t j = array.size() - 1; j > i; j--) {
      if (array[j - 1] > array[j]) {
        swap(array[j - 1], array[j]);
        count++;
      }
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

  uint32_t count = bubble_sort();

  for (uint32_t i = 0; i < array.size(); i++) {
    if (i != 0) cout << " ";
    cout << array[i];
  }

  cout << endl << count << endl;

  return 0;
}
