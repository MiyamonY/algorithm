///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Mon Aug 14 09:51:53 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
static vector<uint64_t> cities;

int32_t main()
{
  uint64_t N, A, B;
  cin >> N >> A >> B;

  for (uint64_t i = 0; i < N; i++) {
    uint64_t X;
    cin >> X;
    cities.push_back(X);
  }

  uint64_t dist = 0;
  for (uint64_t i = 0; i < cities.size() - 1; i++) {
    uint64_t walk = (cities[i + 1] - cities[i]) * A;
    dist += min(B, walk);
  }

  cout << dist << endl;

  return 0;
}
