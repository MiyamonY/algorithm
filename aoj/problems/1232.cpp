///
// File:  1232.cpp
// Author: ymiyamoto
//
// Created on Sat Nov 25 19:23:48 2017
//

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(uint32_t n)
{
  for (uint32_t i = 2; i <= (uint32_t)sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

vector<uint32_t> primes_up_to(uint32_t n)
{
  vector<uint32_t> primes;
  for (uint32_t i = 2; i <= n; i++) {
    if (is_prime(i)) {
      primes.push_back(i);
    }
  }

  return primes;
}

int32_t main()
{
  vector<uint32_t> primes = primes_up_to(100000);

  while (true) {
    uint32_t m, a, b;
    cin >> m >> a >> b;
    if (m == 0 && a == 0 && b == 0) break;

    uint32_t max_p = 0;
    uint32_t max_q = 0;
    for (uint32_t i = 0; i < primes.size(); i++) {
      uint32_t q = primes[i];
      if (q > m) break;
      auto start = lower_bound(primes.begin(), primes.end(), ceil((double)a * q / b));
      auto end = upper_bound(primes.begin(), primes.end(), min(q, m / q));
      for (auto iter = start; iter < end; iter++) {
        uint32_t p = *iter;
        if (max_p * max_q < p * q) {
          max_p = p;
          max_q = q;
        }
      }
    }
    cout << max_p << " " << max_q << endl;
  }

  return 0;
}
