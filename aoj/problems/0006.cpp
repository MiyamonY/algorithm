///
// File:  0006.cpp
// Author: ymiyamoto
//
// Created on Wed Nov  8 22:09:01 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string str;
  cin >> str;
  for (int32_t i = str.size() - 1; i >= 0; i--) {
    cout << str[i];
  }

  cout << endl;

  return 0;
}
