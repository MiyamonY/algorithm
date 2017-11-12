///
// File:  1172.cpp
// Author: ymiyamoto
//
// Created on Sun Nov 12 17:31:51 2017
//

#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

bool is_prime(uint32_t n)
{
  for (uint32_t i = 2; i <= (uint32_t)sqrt((double)n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int32_t main()
{
  while (true) {
    uint32_t n;
    cin >> n;

    if (n == 0) break;

    uint32_t count = 0;
    for (uint32_t i = n + 1; i <= 2 * n; i++) {
      if (is_prime(i)) {
        count++;
      }
    }
    cout << count << endl;
  }

  return 0;
}
