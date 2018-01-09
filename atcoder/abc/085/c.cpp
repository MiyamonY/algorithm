///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sun Jan  7 21:18:56 2018
//

#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N, Y;
  cin >> N >> Y;

  for (uint32_t a = 0; a <= N; a++) {
    for (uint32_t b = 0; b <= N - a; b++) {
      uint32_t c = N - a - b;
      if (Y == 10000 * a + b * 5000 + c * 1000) {
        cout << a << " " << b << " " << c << endl;
        return 0;
      }
    }
  }

  cout << -1 << " " << -1 << " " << -1 << endl;
  return 0;
}
