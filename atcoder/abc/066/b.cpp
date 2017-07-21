///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Fri Jul 21 21:50:54 2017
//

#include <cstdint>
#include <iostream>
#include <string.h>

using namespace std;

int32_t main()
{
  char str[200];

  cin >> str;

  uint32_t n = strlen(str);

  for (uint32_t i = n - 2; i > 0; i -= 2) {
    if (strncmp(str, str + (i / 2), i / 2) == 0) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
