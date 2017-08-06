///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sat Jul 29 23:09:12 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t A, B, C;

  cin >> A >> B >> C;

  for (uint32_t i = 1; i <= B; i++) {
    if (A * i % B == C) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}
