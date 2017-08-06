///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Wed Aug  2 01:19:54 2017
//

#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

size_t max_len(uint64_t a, uint64_t b)
{
  return max(to_string(a).size(), to_string(b).size());
}

int32_t main()
{
  uint64_t N;
  cin >> N;

  uint64_t n = (uint64_t)sqrt(N);

  uint64_t m = UINT64_MAX;
  for (uint64_t i = 1; i <= n; i++) {
    if ((N % i) == 0) {
      m = min(m, max_len(i, N / i));
    }
  }
  cout << m << endl;

  return 0;
}
