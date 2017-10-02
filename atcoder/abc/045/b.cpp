///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Oct  1 03:11:40 2017
//

#include <cstdint>
#include <iostream>
#include <queue>
#include <string>

using namespace std;
static queue<char> que[3];

int32_t main()
{
  for (uint32_t i = 0; i < 3; i++) {
    string str;
    cin >> str;
    for (uint32_t j = 0; j < str.size(); j++) {
      que[i].push(str[j]);
    }
  }

  uint32_t parent = que[0].front() - 'a';
  que[0].pop();

  while (true) {
    if (que[parent].empty()) {
      cout << (char)(parent + 'A') << endl;
      return 0;
    }
    parent = que[parent].front() - 'a';
    que[parent].pop();
  }

  return 0;
}
