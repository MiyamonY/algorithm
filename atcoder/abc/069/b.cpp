///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Aug  6 21:44:44 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string str;
  cin >> str;

  cout << str[0] << str.size() - 2 << str[str.size() - 1] << endl;

  return 0;
}
