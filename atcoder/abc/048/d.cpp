///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Thu Sep 28 22:16:17 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string str;
  cin >> str;

  if ((str.size() % 2 == 0) ^ (str[0] == str[str.size() - 1])) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }

  return 0;
}
