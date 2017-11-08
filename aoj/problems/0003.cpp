///
// File:  0003.cpp
// Author: ymiyamoto
//
// Created on Sat Nov  4 15:48:51 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;
  for (uint32_t i = 0; i < N; i++) {
    uint32_t a, b, c;
    cin >> a >> b >> c;
    if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
