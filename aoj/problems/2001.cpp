///
// File:  2001.cpp
// Author: ymiyamoto
//
// Created on Mon Nov 13 02:17:48 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  while (true) {
    uint32_t n, m, a;
    cin >> n >> m >> a;
    if (n == 0) break;
    vector<uint32_t> vers(n + 1, 0);

    for (uint32_t i = 0; i < n + 1; i++) {
      vers[i] = i;
    }

    vector<pair<uint32_t, pair<uint32_t, uint32_t>>> pals;
    for (uint32_t i = 0; i < m; i++) {
      uint32_t h, p, q;
      cin >> h >> p >> q;
      pals.push_back({h, {p, q}});
    }
    sort(pals.begin(), pals.end());

    for (uint32_t i = 0; i < pals.size(); i++) {
      pair<uint32_t, uint32_t> line = pals[i].second;
      swap(vers[line.first], vers[line.second]);
    }
    cout << vers[a] << endl;
  }

  return 0;
}
