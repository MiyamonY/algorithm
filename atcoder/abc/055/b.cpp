///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Aug  6 17:49:00 2017
//

#include <cstdint>
#include <iostream>

using namespace std;
#define MOD (1000000000 + 7)

int32_t main()
{
  uint32_t N;
  cin >> N;

  long long power = 1;
  for (uint32_t i = 1; i <= N; i++) {
    power *= i;
    power %= MOD;
  }

  cout << power << endl;

  return 0;
}
