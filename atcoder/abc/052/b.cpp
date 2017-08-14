///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Wed Aug  9 18:22:15 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  uint32_t _;
  cin >> _;

  string str;
  cin >> str;
  int32_t x = 0;
  int32_t m = x;
  for (uint32_t i = 0; i < str.size(); i++) {
    if (str[i] == 'I') {
      x++;
    } else {
      x--;
    }
    m = max(m, x);
  }

  cout << m << endl;
  return 0;
}
