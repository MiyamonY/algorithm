///
// File:  2727.cpp
// Author: ymiyamoto
//
// Created on Thu Nov 30 21:35:23 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

bool found(uint32_t start, string T, string S)
{
  uint32_t index = 0;
  for (uint32_t i = start; i < S.size(); i += 2) {
    char c = S[i];
    bool found = false;
    for (; index < T.size(); index++) {
      if (c == T[index]) {
        found = true;
        break;
      }
    }
    if (!found) {
      return false;
    }
    index++;
  }
  return true;
}

int32_t main()
{
  string S, T;
  cin >> S >> T;

  if (found(1, T, S) || found(0, T, S)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
