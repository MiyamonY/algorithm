///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Thu Sep 28 21:30:26 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;
static string str;

int32_t main()
{
  cin >> str;

  uint32_t count = 0;
  if (str[0] != str[str.size() - 1]) {
    uint32_t i = str.size() - 1;
    while (str[0] != str[i] && i > 0) {
      str[i] = str[0];
      i--;
    }
    count++;
  }

  char current = str[0];
  for (uint32_t i = 0; i < str.size(); i++) {
    if (current != str[i]) {
      count++;
      current = str[i];
    }
  }

  cout << count << endl;
  return 0;
}
