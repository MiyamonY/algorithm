///
// File:  0005.cpp
// Author: ymiyamoto
//
// Created on Wed Nov  8 22:03:57 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

uint64_t gcd(uint64_t a, uint64_t b)
{
  if (a < b) return gcd(b, a);
  if (b == 0)
    return a;
  else
    return gcd(b, a - b);
}

uint64_t lcm(uint64_t a, uint64_t b, uint64_t g)
{
  return a * b / g;
}

int32_t main()
{
  while (true) {
    uint64_t a, b;
    cin >> a >> b;
    if (cin.eof()) break;
    uint64_t g = gcd(a, b);
    cout << g << " " << lcm(a, b, g) << endl;
  }

  return 0;
}
