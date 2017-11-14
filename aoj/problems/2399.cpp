///
// File:  2399.cpp
// Author: ymiyamoto
//
// Created on Mon Nov 13 21:04:52 2017
//

#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  while (true) {
    uint32_t N;
    cin >> N;

    if (N == 0) break;

    array<vector<uint32_t>, 101> mem;

    for (uint32_t i = 1; i <= N; i++) {
      uint32_t n;
      cin >> n;
      for (uint32_t j = 0; j < n; j++) {
        uint32_t m;
        cin >> m;
        mem[i].push_back(m);
      }
      sort(mem[i].begin(), mem[i].end());
    }

    vector<uint32_t> dis;
    uint32_t n;
    cin >> n;
    for (uint32_t i = 0; i < n; i++) {
      uint32_t m;
      cin >> m;
      dis.push_back(m);
    }
    sort(dis.begin(), dis.end());

    int32_t m = -1;
    for (uint32_t i = 1; i <= N; i++) {
      uint32_t all_found = true;
      for (uint32_t j = 0; j < dis.size(); j++) {
        uint32_t found = false;
        for (uint32_t k = 0; k < mem[i].size(); k++) {
          if (dis[j] == mem[i][k]) {
            found = true;
          }
        }
        all_found &= found;
      }

      if (all_found) {
        if (m != -1) {
          m = -1;
          break;
        } else {
          m = i;
        }
      }
    }
    cout << m << endl;
  }

  return 0;
}
