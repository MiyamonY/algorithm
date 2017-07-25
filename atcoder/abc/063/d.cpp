///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Mon Jul 24 21:22:18 2017
//

#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static vector<int64_t> monsters;

bool enough(int64_t num, int64_t a, int64_t b)
{
  int64_t extra_damages = 0;

  for (uint32_t i = 0; i < monsters.size(); i++) {
    if (monsters[i] > num * b) {
      extra_damages += ceil((monsters[i] - num * b) / (double)(a - b));
    }
  }
  return extra_damages <= num;
}

int32_t main()
{
  int64_t num, center, around;
  cin >> num >> center >> around;

  int64_t m = 0;
  for (int64_t i = 0; i < num; i++) {
    int64_t val;
    cin >> val;
    monsters.push_back(val);
    m = max(m, val);
  }

  int64_t l = 0, r = (m / around) + 1;
  while (l + 1 < r) {
    int64_t c = (l + r) / 2;
    if (enough(c, center, around)) {
      r = c;
    } else {
      l = c;
    }
  }

  cout << r << endl;

  return 0;
}
