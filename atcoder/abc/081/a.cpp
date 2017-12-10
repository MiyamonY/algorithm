///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 10 21:22:14 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string str;
  cin >> str;

  uint32_t num = 0;
  for (auto c : str) {
    if (c == '1') {
      num++;
    }
  }
  cout << num << endl;

  return 0;
}
