///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sat Jul 29 23:21:02 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint64_t N, T;
  cin >> N >> T;

  uint64_t time = 0;
  uint64_t t0, t1;
  cin >> t0;
  for (uint64_t i = 0; i < N - 1; i++) {
    cin >> t1;
    time += min(T, t1 - t0);
    t0 = t1;
  }
  time += T;

  cout << time << endl;
  return 0;
}
