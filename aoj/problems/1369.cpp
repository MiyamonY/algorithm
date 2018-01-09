///
// File:  1369.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 31 19:24:47 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct pos_t {
  uint32_t x;
  uint32_t y;
  bool operator<(const pos_t &p)
  {
    if (x == p.x) {
      return y < p.y;
    }
    return x < p.x;
  }
};

int32_t main()
{
  uint32_t n, m;
  cin >> n >> m;

  vector<pos_t> arms(m);
  for (uint32_t i = 0; i < m; i++) {
    cin >> arms[i].x >> arms[i].y;
  }

  sort(arms.begin(), arms.end());

  vector<pair<uint32_t, uint32_t>> sets(n);
  for (uint32_t i = 0; i < sets.size(); i++) {
    sets[i] = {i, i};
  }

  for (auto arm : arms) {
    uint32_t y = arm.y;
    sets[y - 1].second = max(sets[y - 1].second, sets[y].second);
    sets[y].first = min(sets[y].first, sets[y - 1].first);
  }

  for (uint32_t i = 0; i < n; i++) {
    if (i != 0) cout << " ";
    cout << sets[i].second - sets[i].first + 1;
  }
  cout << endl;

  return 0;
}
