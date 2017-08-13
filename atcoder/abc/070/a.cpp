///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Mon Aug 14 01:48:30 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string str;
  cin >> str;

  bool result = true;
  for (uint32_t i = 0; i < str.size(); i++) {
    if (str[i] != str[str.size() - 1 - i]) {
      result = false;
    }
  }

  if (result) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
