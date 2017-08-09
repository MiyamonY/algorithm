///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Wed Aug  9 16:50:14 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string str;
  cin >> str;

  bool start = false;
  uint32_t indexA = 0;
  uint32_t indexZ = 0;
  for (uint32_t i = 0; i < str.size(); i++) {
    if (!start && (str[i] == 'A')) {
      start = true;
      indexA = i;
    }

    if (start) {
      if (str[i] == 'Z') {
        indexZ = i;
      }
    }
  }

  cout << indexZ - indexA + 1 << endl;

  return 0;
}
