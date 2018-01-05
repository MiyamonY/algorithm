///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 31 17:45:55 2017
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

int32_t main()
{
  vector<uint32_t> like2017;
  for (uint32_t i = 2; i < 100000; i++) {
    if (i % 2 == 1) {
      if (is_prime(i) && is_prime((i + 1) / 2)) {
        like2017.push_back(i);
      }
    }
  }

  uint32_t Q;
  cin >> Q;

  for (uint32_t i = 0; i < Q; i++) {
    uint32_t n, m;
    cin >> n >> m;
    cout << upper_bound(like2017.begin(), like2017.end(), m) - lower_bound(like2017.begin(), like2017.end(), n) << endl;
  }
  return 0;
}
