///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Mon Sep 18 18:44:02 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static vector<int32_t> xs;

int32_t main()
{
  int32_t N, K;
  cin >> N;
  cin >> K;

  for (int32_t i = 0; i < N; i++) {
    int32_t x;
    cin >> x;
    xs.push_back(x);
  }

  int64_t distance = 0;
  for (uint32_t i = 0; i < xs.size(); i++) {
    int32_t x = xs[i];
    distance += 2 * min(abs(K - x), abs(x));
  }

  cout << distance << endl;

  return 0;
}
