///
// File:  alds1_6_d.cpp
// Author: ymiyamoto
//
// Created on Thu Oct 12 23:39:32 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
#define SIZE 10000

static vector<uint32_t> array;
static uint32_t T[SIZE + 1];

static uint32_t solve(uint32_t array_min)
{
  uint32_t count = 0;

  vector<bool> visited(array.size(), false);
  vector<uint32_t> array1(array);

  sort(array1.begin(), array1.end());

  for (uint32_t i = 0; i < array1.size(); i++) {
    T[array1[i]] = i;
  }

  for (uint32_t i = 0; i < visited.size(); i++) {
    if (visited[i]) continue;
    uint32_t index = i;
    uint32_t cycle_weight = 0;
    uint32_t cycle_min = UINT32_MAX;
    uint32_t cycle_len = 0;
    while (true) {
      visited[index] = true;
      cycle_len++;
      uint32_t v = array[index];
      cycle_min = min(cycle_min, v);
      cycle_weight += v;
      index = T[v];
      if (visited[index]) break;
    }
    count += min(cycle_weight + (cycle_len - 2) * cycle_min, cycle_min + cycle_weight + (cycle_len + 1) * array_min);
  }

  return count;
}

int32_t main()
{
  uint32_t n;
  cin >> n;

  uint32_t s = UINT32_MAX;
  for (uint32_t i = 0; i < n; i++) {
    uint32_t val;
    cin >> val;
    array.push_back(val);
    s = min(s, val);
  }

  uint32_t count = solve(s);

  cout << count << endl;

  return 0;
}
