///
// File:  0009.cpp
// Author: ymiyamoto
//
// Created on Wed Nov  8 23:17:22 2017
//

#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

static int32_t primes[1000000];

bool is_prime(uint32_t val)
{
  if (primes[val] == 1) return true;
  if (primes[val] == -1) return false;

  for (uint32_t i = 2; i <= sqrt(val); i++) {
    if (val % i == 0) {
      primes[val] = -1;
      return false;
    }
  }

  primes[val] = 1;
  return true;
}

int32_t main()
{
  while (true) {
    uint64_t n;
    cin >> n;
    if (cin.eof()) break;

    uint32_t count = 0;
    for (uint32_t i = 2; i <= n; i++) {
      if (is_prime(i)) count++;
    }
    cout << count << endl;
  }

  return 0;
}
