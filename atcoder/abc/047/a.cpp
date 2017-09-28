///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Thu Sep 28 01:31:36 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t a, b, c;
  cin >> a >> b >> c;

  if (a + b == c) {
    cout << "Yes" << endl;
  } else if (b + c == a) {
    cout << "Yes" << endl;
  } else if (c + a == b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
