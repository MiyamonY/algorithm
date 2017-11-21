///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Tue Nov 21 21:52:48 2017
//

#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

int32_t main()
{
  string str;
  cin >> str;

  bool is_good = false;
  if ((str[0] == str[1] && str[1] == str[2]) || (str[1] == str[2] && str[2] == str[3])) {
    is_good = true;
  }

  if (is_good) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
