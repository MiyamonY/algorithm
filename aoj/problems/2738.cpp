///
// File:  2738.cpp
// Author: ymiyamoto
//
// Created on Sat Nov 11 00:00:11 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;
  int32_t count = 0;

  vector<string> conv;
  bool has_one_A = false;
  for (uint32_t i = 0; i < N; i++) {
    string str;
    cin >> str;
    conv.push_back(str);
  }

  for (auto c = conv.begin(); c < conv.end(); c++) {
    if (*c == "A") {
      has_one_A = true;
      count++;
    } else {
      count--;
      if (count < 0) {
        break;
      }
    }
  }

  if (has_one_A && count == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
