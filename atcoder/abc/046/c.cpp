///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Fri Sep 29 20:50:02 2017
//
#include <cstdint>
#include <iostream>

using namespace std;

static inline int64_t ceil(int64_t a, int64_t b)
{
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}

int32_t main()
{
  uint32_t N;
  cin >> N;

  int64_t t = 1, a = 1;
  for (uint32_t i = 0; i < N; i++) {
    int64_t T, A;
    cin >> T >> A;
    int64_t n = max(ceil(t, T), ceil(a, A));
    t = n * T;
    a = n * A;
  }

  cout << t + a << endl;

  return 0;
}
