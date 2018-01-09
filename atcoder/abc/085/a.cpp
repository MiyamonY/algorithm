///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sun Jan  7 21:14:25 2018
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string str;

  cin >> str;
  for (uint32_t i = 0; i < str.size(); i++) {
    if (i == 3) {
      cout << '8';
    } else {
      cout << str[i];
    }
  }
  cout << endl;

  return 0;
}
