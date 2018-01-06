///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sat Jan  6 16:08:42 2018
//

#include <cstdint>
#include <iostream>

using namespace std;
uint32_t gcd(uint32_t a, uint32_t b)
{
  if (b > a) return gcd(b, a);
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int32_t main()
{
  uint32_t a, b, n;
  cin >> a >> b >> n;

  uint32_t g = gcd(a, b);
  for (uint32_t i = 0;; i++) {
    if (n <= i * a * b / g) {
      cout << i * a * b / g << endl;
      return 0;
    }
  }

  return 0;
}
