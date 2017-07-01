///
// File:  binary_search.cpp
// Author: ymiyamoto
//
// Created on Sat Jul  1 22:02:49 2017
//

#include <cstdint>
#include <vector>

using namespace std;

size_t binary_search(uint32_t array[], size_t size, uint32_t v)
{
  uint32_t lindex = 0;
  uint32_t rindex = size;

  while (lindex < rindex) {
    uint32_t half = (lindex + rindex) / 2;
    uint32_t pivot = array[half];
    if (v == pivot)
      return true;
    else if (v < pivot)
      rindex = half;
    else
      lindex = half + 1;
  }
  return false;
}

#if !defined(TEST)
#include <iostream>

static vector<uint32_t> s, t;

int32_t main(void)
{
  uint32_t n, m;
  cin >> n;
  for (uint32_t i = 0; i < n; i++) {
    uint32_t val;
    cin >> val;
    s.push_back(val);
  }

  uint32_t cnt = 0;

  cin >> m;
  for (uint32_t i = 0; i < m; i++) {
    uint32_t val;
    cin >> val;
    if (binary_search(&s[0], s.size(), val)) {
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}
#endif
