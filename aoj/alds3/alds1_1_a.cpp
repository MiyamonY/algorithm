///
// File:  alds1_1_a.cpp
// Author: ymiyamoto
//
// Created on Wed Oct  4 01:04:46 2017
//

#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

static vector<uint32_t> array;

void insersion_sort()
{
  for (uint32_t i = 0; i < array.size(); i++) {
    for (uint32_t j = i; j > 0; j--) {
      if (array[j - 1] > array[j]) {
        swap(array[j - 1], array[j]);
      }
    }

    for (uint32_t k = 0; k < array.size(); k++) {
      if (k != 0) {
        cout << " ";
      }
      cout << array[k];
    }
    cout << endl;
  }
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

  insersion_sort();

  return 0;
}
