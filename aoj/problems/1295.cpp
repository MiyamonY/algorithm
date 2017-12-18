///
// File:  1295.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 10 10:50:36 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  while (true) {
    uint32_t w, d;
    cin >> w >> d;
    if (w == 0 && d == 0) break;

    vector<uint32_t> front(w);
    for (uint32_t i = 0; i < w; i++) {
      cin >> front[i];
    }
    vector<uint32_t> side(d);
    for (uint32_t i = 0; i < d; i++) {
      cin >> side[i];
    }

    vector<uint32_t> blocks;
    for (uint32_t i = 0; i < front.size(); i++) {
      blocks.push_back(front[i]);
    }

    for (uint32_t s : side) {
      bool found = false;
      for (auto iter = front.begin(); iter < front.end(); iter++) {
        if (*iter == s) {
          front.erase(iter);
          found = true;
          break;
        }
      }
      if (!found) {
        blocks.push_back(s);
      }
    }

    uint32_t sum = 0;
    for (auto v : blocks) {
      sum += v;
    }
    cout << sum << endl;
  }

  return 0;
}
