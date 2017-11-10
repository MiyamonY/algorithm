///
// File:  2440.cpp
// Author: ymiyamoto
//
// Created on Fri Nov 10 15:06:25 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum status_t {
  Open,
  Close,
};

int32_t main()
{
  uint32_t N, U;
  cin >> N;

  vector<string> registered;
  for (uint32_t i = 0; i < N; i++) {
    string str;
    cin >> str;
    registered.push_back(str);
  }

  cin >> U;
  bool is_close = true;
  for (uint32_t i = 0; i < U; i++) {
    string str;
    cin >> str;
    uint32_t j = 0;
    for (; j < registered.size(); j++) {
      if (str == registered[j]) {
        if (is_close) {
          cout << "Opened by " << str << endl;
        } else {
          cout << "Closed by " << str << endl;
        }
        is_close = !is_close;
        break;
      }
    }

    if (j == registered.size()) {
      cout << "Unknown " << str << endl;
    }
  }

  return 0;
}
