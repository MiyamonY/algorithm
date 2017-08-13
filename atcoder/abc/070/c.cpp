///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Mon Aug 14 02:03:17 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

uint64_t gcd(uint64_t a, uint64_t b)
{
  if (b == 0) {
    return a;
  }

  return gcd(b, a % b);
}

int32_t main()
{
  uint64_t N;
  cin >> N;

  uint64_t l = 1;
  for (uint64_t i = 0; i < N; i++) {
    uint64_t val;
    cin >> val;
    l = l / gcd(l, val) * val;
  }

  cout << l << endl;

  return 0;
}
