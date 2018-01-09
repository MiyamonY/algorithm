///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Fri Jan  5 17:03:47 2018
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint64_t n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n - 1 << endl;
  } else {
    cout << n + 1 << endl;
  }

  return 0;
}
