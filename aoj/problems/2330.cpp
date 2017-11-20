///
// File:  2330.cpp
// Author: ymiyamoto
//
// Created on Sun Nov 19 17:49:51 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  long long n;
  cin >> n;

  for (uint32_t i = 0;; i++) {
    if (n == 1) {
      cout << i << endl;
      break;
    } else if (n == 2) {
      cout << i + 1 << endl;
      break;
    }
    long long third = (n + 2) / 3;
    n = max(third, n - 2 * third);
  }

  return 0;
}
