///
// File:  stable_sort.cpp
// Author: ymiyamoto
//
// Created on Thu Jun 29 08:27:13 2017
//

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

void stable_sort_bubble_sort(pair<int32_t, uint8_t> array[], size_t size)
{
  if ((array == nullptr) || (size == 0)) throw runtime_error("array is null");

  for (uint32_t i = 0; i < size; i++) {
    for (uint32_t j = size - 1; j > i; j--) {
      if (array[j - 1].first > array[j].first) {
        swap(array[j - 1], array[j]);
      }
    }
  }
}

void stable_sort_selection_sort(pair<int32_t, uint8_t> array[], size_t size)
{
  if ((array == nullptr) || (size == 0)) throw runtime_error("array is null");

  for (uint32_t i = 0; i < size; i++) {
    uint32_t min = i;
    for (uint32_t j = i; j < size; j++) {
      if (array[j].first < array[min].first) {
        min = j;
      }
    }
    swap(array[i], array[min]);
  }
}

#if !defined(TEST)
#include <iostream>
static void print_vec(vector<pair<int32_t, uint8_t>> &vec)
{
  for (uint32_t i = 0; i < vec.size(); i++) {
    if (i != 0) cout << ' ';
    cout << vec[i].second << vec[i].first;
  }
  cout << endl;
}

int32_t main(void)
{
  vector<pair<int32_t, uint8_t>> vec1;
  vector<pair<int32_t, uint8_t>> vec2;

  uint32_t len;
  cin >> len;

  for (uint32_t i = 0; i < len; i++) {
    char c;
    int32_t val;
    cin >> c >> val;
    vec1.push_back(make_pair(val, c));
    vec2.push_back(make_pair(val, c));
  }

  stable_sort_bubble_sort(&vec1[0], vec1.size());
  stable_sort_selection_sort(&vec2[0], vec2.size());

  print_vec(vec1);
  cout << "Stable" << endl;

  print_vec(vec2);
  if (vec1 == vec2) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }

  return 0;
}
#endif
