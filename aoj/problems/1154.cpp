///
// File:  1154.cpp
// Author: ymiyamoto
//
// Created on Sat Nov 18 22:38:43 2017
//

#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

static array<int32_t, 300000> primes;

int32_t is_prime(uint32_t n)
{
  if (primes[n] != 0) return primes[n];

  for (uint32_t i = 0; i + 6 < n; i += 7) {
    if (i != 0 && (n % (i + 1) == 0)) {
      return primes[n] = 2;
    }
    if (n % (i + 6) == 0) {
      return primes[n] = 2;
    }
  }
  return primes[n] = 1;
}

int32_t main()
{
  for (uint32_t i = 0; i < primes.size(); i++) {
    primes[i] = 0;
  }

  while (true) {
    uint32_t n;
    cin >> n;
    if (n == 1) break;

    cout << n << ":";
    for (uint32_t i = 0; i < n; i += 7) {
      if (i + 1 != 1) {
        if (n % (i + 1) == 0) {
          if (is_prime(i + 1) == 1) {
            cout << " " << i + 1;
          }
        }
      }
      if (n % (i + 6) == 0) {
        if (is_prime(i + 6) == 1) {
          cout << " " << i + 6;
        }
      }
    }
    cout << endl;
  }

  return 0;
}
