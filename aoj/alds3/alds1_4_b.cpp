///
// File:  alds1_4_b.cpp
// Author: ymiyamoto
//
// Created on Sat Oct  7 19:10:25 2017
//

#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

static vector<int64_t> S;

bool binary_search(int64_t val)
{
  uint64_t left = 0;
  uint64_t right = S.size();
  while (left + 1 <= right) {
    uint64_t mid = (left + right) / 2;
    if (S[mid] == val) {
      return true;
    } else if (val < S[mid]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return false;
}

int32_t main()
{
  uint32_t n, q;
  cin >> n;

  for (uint32_t i = 0; i < n; i++) {
    int64_t val;
    cin >> val;
    S.push_back(val);
  }

  uint64_t count = 0;
  cin >> q;
  for (uint32_t i = 0; i < q; i++) {
    int64_t val;
    cin >> val;
    if (binary_search(val)) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
