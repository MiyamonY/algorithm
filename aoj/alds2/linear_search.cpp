///
// File:  linear_search.cpp
// Author: ymiyamoto
//
// Created on Sat Jul  1 21:30:18 2017
//

#include <cstdint>
#include <stdexcept>
#include <vector>

#include "problems.hpp"

using namespace std;

size_t linear_search(uint32_t s[], size_t s_size, uint32_t t[], size_t t_size)
{
  if (s == nullptr) throw runtime_error("s is null");
  if (t == nullptr) throw runtime_error("t is null");

  size_t cnt = 0;

  for (uint32_t i = 0; i < t_size; i++) {
    for (uint32_t j = 0; j < s_size; j++) {
      if (t[i] == s[j]) {
        cnt++;
        break;
      }
    }
  }

  return cnt;
}

#if !defined(TEST)
#include <iostream>
static vector<uint32_t> s, t;

int32_t main()
{
  uint32_t n, m;
  cin >> n;
  for (uint32_t i = 0; i < n; i++) {
    uint32_t val;
    cin >> val;
    s.push_back(val);
  }

  cin >> m;
  for (uint32_t i = 0; i < m; i++) {
    uint32_t val;
    cin >> val;
    t.push_back(val);
  }

  cout << linear_search(&s[0], s.size(), &t[0], t.size()) << endl;

  return 0;
}
#endif
