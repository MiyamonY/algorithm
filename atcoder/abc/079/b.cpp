///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Tue Nov 21 23:18:32 2017
//

#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

static array<uint64_t, 100> mem{
    0,
};

uint64_t luca(uint32_t n)
{
  if (n == 0)
    return mem[0] = 2;
  else if (n == 1)
    return mem[1] = 1;
  else {
    if (mem[n - 1] == 0) {
      mem[n - 1] = luca(n - 1);
    }
    if (mem[n - 2] == 0) {
      mem[n - 2] = luca(n - 2);
    }

    return mem[n] = mem[n - 1] + mem[n - 2];
  }
}

int32_t main()
{
  uint32_t N;
  cin >> N;

  cout << luca(N) << endl;

  return 0;
}
