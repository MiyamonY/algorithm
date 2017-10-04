///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Wed Oct  4 20:37:57 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
static vector<char> stack;

int32_t main()
{
  string str;
  cin >> str;

  for (uint32_t i = 0; i < str.size(); i++) {
    if (str[i] == 'B') {
      if (!stack.empty()) {
        stack.pop_back();
      }
    } else {
      stack.push_back(str[i]);
    }
  }

  for (uint32_t i = 0; i < stack.size(); i++) {
    cout << stack[i];
  }
  cout << endl;

  return 0;
}
