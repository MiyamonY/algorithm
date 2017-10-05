///
// File:  alds1_2_d.cpp
// Author: ymiyamoto
//
// Created on Wed Oct  4 23:56:00 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static vector<uint32_t> array;
static vector<uint32_t> G;

uint64_t insersion_sort(int64_t dist)
{
  uint64_t count = 0;
  for (uint32_t i = dist; i < array.size(); i++) {
    int32_t val = array[i];
    int32_t j = i - dist;
    while (j >= 0 && array[j] > val) {
      swap(array[j + dist], array[j]);
      count++;
      j -= dist;
    }
    array[j + dist] = val;
  }

  return count;
}

uint64_t shell_sort()
{
  uint32_t i = 1;
  while (i <= array.size()) {
    G.push_back(i);
    i = 3 * i + 1;
  }

  uint64_t count = 0;

  for (int32_t j = G.size() - 1; j >= 0; j--) {
    count += insersion_sort(G[j]);
  }

  return count;
}

int32_t main()
{
  uint32_t n;
  cin >> n;

  for (uint32_t i = 0; i < n; i++) {
    uint32_t val;
    cin >> val;
    array.push_back(val);
  }

  uint64_t count = shell_sort();
  cout << G.size() << endl;

  for (int32_t i = G.size() - 1; i >= 0; i--) {
    if (i != G.size() - 1) cout << " ";
    cout << G[i];
  }

  cout << endl << count << endl;

  for (uint32_t i = 0; i < array.size(); i++) {
    cout << array[i] << endl;
  }

  return 0;
}
