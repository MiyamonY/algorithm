///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sat Dec 23 22:00:20 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string str;
  cin >> str;

  uint32_t K = str.size();
  for (uint32_t i = 1; i < str.size(); i++) {
    if (str[i - 1] != str[i]) {
      K = min(K, max(i, (int32_t)str.size() - i));
    }
  }
  cout << K << endl;

  return 0;
}
