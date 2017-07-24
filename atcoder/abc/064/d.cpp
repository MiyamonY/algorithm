///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Mon Jul 24 20:42:20 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string _, str;
  cin >> _;
  cin >> str;

  int32_t count = 0;
  uint32_t left_paren = 0;
  uint32_t right_paren = 0;

  for (uint32_t i = 0; i < str.size(); i++) {
    if (str[i] == '(') {
      count++;
    } else if (str[i] == ')') {
      count--;
      if (count < 0) {
        count = 0;
        left_paren++;
      }
    }
  }

  right_paren = count;

  for (uint32_t i = 0; i < left_paren; i++) {
    cout << '(';
  }
  cout << str;

  for (uint32_t i = 0; i < right_paren; i++) {
    cout << ')';
  }

  cout << endl;

  return 0;
}
