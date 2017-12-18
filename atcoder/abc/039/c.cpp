///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Wed Dec 13 01:29:17 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int32_t main()
{
  const string keyboard = "WBWBWWBWBWBW";

  string str;
  cin >> str;

  vector<pair<uint32_t, string>> scale({{0, "Do"}, {2, "Re"}, {4, "Mi"}, {5, "Fa"}, {7, "So"}, {9, "La"}, {11, "Si"}});

  for (auto s : scale) {
    bool found = true;
    uint32_t start = s.first;
    for (uint32_t i = 0; i < 20; i++) {
      if (str[i] != keyboard[(i + start) % keyboard.size()]) {
        found = false;
      }
    }
    if (found) {
      cout << s.second << endl;
      return 0;
    }
  }
  return 0;
}
