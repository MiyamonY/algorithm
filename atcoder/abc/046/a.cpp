///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Fri Sep 29 19:23:24 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t a, b, c;
  cin >> a >> b >> c;

  if ((a == b) && (b == c)) {
    cout << 1;
  } else if (a == b) {
    cout << 2;
  } else if (b == c) {
    cout << 2;
  } else if (c == a) {
    cout << 2;
  } else {
    cout << 3;
  }
  cout << endl;

  return 0;
}
