///
// File:  alds1_4_a.cpp
// Author: ymiyamoto
//
// Created on Sat Oct  7 19:00:24 2017
//

#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

static vector<uint64_t> S;

int32_t main()
{
  uint32_t n, q;
  cin >> n;

  for (uint32_t i = 0; i < n; i++) {
    uint64_t val;
    cin >> val;
    S.push_back(val);
  }

  uint64_t count = 0;
  cin >> q;
  for (uint32_t i = 0; i < q; i++) {
    uint64_t val;
    cin >> val;
    for (uint32_t j = 0; j < S.size(); j++) {
      if (val == S[j]) {
        count++;
        break;
      }
    }
  }

  cout << count << endl;

  return 0;
}
