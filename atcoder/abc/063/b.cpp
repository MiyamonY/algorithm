///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Mon Jul 24 20:52:27 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string str;

  cin >> str;

  for (uint32_t i = 0; i < str.size(); i++) {
    for (uint32_t j = i + 1; j < str.size(); j++) {
      if (str[i] == str[j]) {
        cout << "no" << endl;
        return 0;
      }
    }
  }

  cout << "yes" << endl;

  return 0;
}
