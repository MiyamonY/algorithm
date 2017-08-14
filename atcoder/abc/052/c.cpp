///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Mon Aug 14 09:30:11 2017
//

#include <cstdint>
#include <iostream>

using namespace std;
#define MAX_NUM 1001
#define MOD (1000000000 + 7)
static uint32_t nums[MAX_NUM];

void prime_factorize(uint32_t n)
{
  uint32_t i = 2;
  for (; i * i <= n; i++) {
    while (n % i == 0) {
      nums[i]++;
      n /= i;
      nums[i] %= MOD;
    }
  }

  nums[n]++;
}

int32_t main()
{
  uint32_t N;
  cin >> N;

  for (uint32_t n = 2; n <= N; n++) {
    prime_factorize(n);
  }

  uint64_t count = 1;
  for (uint32_t n = 2; n <= N; n++) {
    count *= (nums[n] + 1);
    count %= MOD;
  }
  cout << count << endl;

  return 0;
}
