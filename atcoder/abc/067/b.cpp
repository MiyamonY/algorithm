///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Wed Jul 19 19:40:45 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<uint32_t> &vec)
{
  for (uint32_t i = 1; i < vec.size(); i++) {
    for (uint32_t j = vec.size() - 1; j >= i; j--) {
      if (vec[j] > vec[j - 1]) {
        swap(vec[j], vec[j - 1]);
      }
    }
  }
}

int32_t main()
{
  uint32_t k, n;

  cin >> n >> k;

  vector<uint32_t> vec;

  for (uint32_t i = 0; i < n; i++) {
    uint32_t val;
    cin >> val;
    vec.push_back(val);
  }

  bubble_sort(vec);

  uint32_t total = 0;
  for (uint32_t i = 0; i < k; i++) {
    total += vec[i];
  }

  cout << total << endl;

  return 0;
}
