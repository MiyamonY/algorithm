///
// File:  0002.cpp
// Author: ymiyamoto
//
// Created on Sat Nov  4 15:39:12 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  while (true) {
    uint32_t a, b;
    cin >> a >> b;
    if (cin.eof()) break;
    cout << to_string(a + b).size() << endl;
  }

  return 0;
}
