///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sat Jan  6 23:00:02 2018
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t L, H, N;
  cin >> L >> H;
  cin >> N;

  for (uint32_t i = 0; i < N; i++) {
    uint32_t A;
    cin >> A;
    if (A < L) {
      cout << L - A << endl;
    } else if (A <= H) {
      cout << 0 << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
