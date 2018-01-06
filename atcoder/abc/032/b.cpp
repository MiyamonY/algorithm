///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sat Jan  6 16:12:30 2018
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int32_t main()
{
  string s;
  int32_t k;
  cin >> s >> k;

  vector<string> subs;
  uint32_t count = 0;
  for (int32_t i = 0; i <= (int32_t)s.size() - k; i++) {
    string su = s.substr(i, k);
    bool has_same = false;
    for (auto sub : subs) {
      if (su == sub) {
        has_same = true;
      }
    }
    if (!has_same) {
      subs.push_back(su);
      count++;
    }
  }

  cout << count << endl;
  return 0;
}
