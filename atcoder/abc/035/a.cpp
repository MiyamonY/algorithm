///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Fri Jan  5 06:59:18 2018
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t gcd(int32_t a, int32_t b)
{
  if (b > a) return gcd(b, a);
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int32_t main()
{
  uint32_t W, H;
  cin >> W >> H;

  uint32_t g = gcd(W, H);

  cout << W / g << ":" << H / g << endl;

  return 0;
}
