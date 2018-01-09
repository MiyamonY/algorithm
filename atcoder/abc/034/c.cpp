///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Fri Jan  5 17:07:04 2018
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

int64_t pow(int64_t x, int64_t n)
{
  if (n == 0) return 1;
  if (n % 2 == 1)
    return x * pow(x, n - 1) % MOD;
  else
    return pow((x * x) % MOD, n / 2);
}

int64_t comb(int64_t n, int64_t k)
{
  int64_t t = 1;
  for (int64_t i = n - k + 1; i <= n; i++) {
    t *= i;
    t %= MOD;
  }

  int64_t s = 1;
  for (int64_t i = 1; i <= k; i++) {
    s *= i;
    s %= MOD;
  }

  return t * pow(s, MOD - 2) % MOD;
}

int32_t main()
{
  uint32_t W, H;
  cin >> W >> H;

  cout << comb(W - 1 + H - 1, min(W - 1, H - 1)) << endl;

  return 0;
}
