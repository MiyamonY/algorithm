///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sat Jan  6 00:10:28 2018
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string exp;
  cin >> exp;

  uint32_t count = 0;
  bool has_0 = false;
  for (uint32_t i = 0; i < exp.size(); i++) {
    if (exp[i] == '+') {
      if (!has_0) {
        count++;
      }
      has_0 = false;
    } else if (exp[i] == '0') {
      has_0 = true;
    }
  }

  if (!has_0) {
    count++;
  }

  cout << count << endl;
  return 0;
}
