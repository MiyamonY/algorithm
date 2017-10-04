///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Wed Oct  4 21:03:40 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string str;
  cin >> str;

  for (uint32_t i = 0; i < str.size() - 1; i++) {
    if (str[i] == str[i + 1]) {
      cout << i + 1 << " " << i + 2 << endl;
      return 0;
    } else if (i + 2 < str.size() && str[i] == str[i + 2]) {
      cout << i + 1 << " " << i + 3 << endl;
      return 0;
    }
  }

  cout << -1 << " " << -1 << endl;

  return 0;
}
