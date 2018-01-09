///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Fri Jan  5 23:55:48 2018
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;

  uint32_t total = 0;
  vector<pair<uint32_t, string>> cities;
  for (uint32_t i = 0; i < N; i++) {
    string name;
    uint32_t p;
    cin >> name >> p;
    total += p;
    cities.push_back({p, name});
  }

  sort(cities.begin(), cities.end());
  if (total < cities[cities.size() - 1].first * 2) {
    cout << cities[cities.size() - 1].second << endl;
  } else {
    cout << "atcoder" << endl;
  }

  return 0;
}
