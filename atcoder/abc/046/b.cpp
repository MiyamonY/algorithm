///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Fri Sep 29 19:39:00 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint64_t N, K;
  cin >> N >> K;

  uint64_t count = K;
  for (uint32_t i = 1; i < N; i++) {
    count *= K - 1;
  }

  cout << count << endl;

  return 0;
}
