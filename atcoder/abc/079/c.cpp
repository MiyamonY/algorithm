///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Tue Nov 21 23:24:08 2017
//

#include <cstdint>
#include <cstdlib>
#include <iostream>

using namespace std;

int32_t main()
{
  char A, B, C, D;
  cin >> A >> B >> C >> D;

  int32_t a = A - '0';
  int32_t b = B - '0';
  int32_t c = C - '0';
  int32_t d = D - '0';

  if (a + b + c + d == 7) {
    cout << a << "+" << b << "+" << c << "+" << d << "=7" << endl;
  } else if (a + b + c - d == 7) {
    cout << a << "+" << b << "+" << c << "-" << d << "=7" << endl;
  } else if (a + b - c + d == 7) {
    cout << a << "+" << b << "-" << c << "+" << d << "=7" << endl;
  } else if (a + b - c - d == 7) {
    cout << a << "+" << b << "-" << c << "-" << d << "=7" << endl;
  } else if (a - b + c + d == 7) {
    cout << a << "-" << b << "+" << c << "+" << d << "=7" << endl;
  } else if (a - b + c - d == 7) {
    cout << a << "-" << b << "+" << c << "-" << d << "=7" << endl;
  } else if (a - b - c + d == 7) {
    cout << a << "-" << b << "-" << c << "+" << d << "=7" << endl;
  } else if (a - b - c + d == 7) {
    cout << a << "-" << b << "-" << c << "-" << d << "=7" << endl;
  }

  return 0;
}
