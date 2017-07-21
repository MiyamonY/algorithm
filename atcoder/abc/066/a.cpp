///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Fri Jul 21 21:46:08 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t a, b, c;
  cin >> a >> b >> c;

  uint32_t m = a + b;

  m = min(m, b + c);
  m = min(m, a + c);
  cout << m << endl;

  return 0;
}
