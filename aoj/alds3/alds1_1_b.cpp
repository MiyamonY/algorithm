///
// File:  alds1_1_b.cpp
// Author: ymiyamoto
//
// Created on Mon Nov 13 03:00:08 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

uint64_t gcd(uint64_t a, uint64_t b)
{
  if (b > a) gcd(b, a);
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int32_t main()
{
  uint64_t a, b;
  cin >> a >> b;

  cout << gcd(a, b) << endl;

  return 0;
}
