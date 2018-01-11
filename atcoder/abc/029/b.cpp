///
//  Author : Author
// Created On : Thu Jan 11 2018
//  File : b.cpp
//
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main() {
  uint32_t count = 0;
  for (uint32_t i = 0; i < 12; i++) {
    string s;
    cin >> s;
    for (auto c : s) {
      if (c == 'r') {
        count++;
        break;
      }
    }
  }

  cout << count << endl;

  return 0;
}
