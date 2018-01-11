///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Thu Jan 11 21:28:09 2018
//
#include <bits/stdc++.h>

using namespace std;

int32_t sums(vector<int32_t> ns, uint32_t i, uint32_t n)
{
  if (n == 3) {
    return 0;
  }
  if (i == ns.size()) {
    return -500;
  }

  return max(ns[i] + sums(ns, i + 1, n + 1), sums(ns, i + 1, n));
}

int32_t main()
{
  vector<int32_t> ns(5, 0);
  for (uint32_t i = 0; i < ns.size(); i++) {
    cin >> ns[i];
  }

  vector<uint32_t> sums;
  for (uint32_t i = 0; i < 5; i++) {
    for (uint32_t j = i + 1; j < 5; j++) {
      for (uint32_t k = j + 1; k < 5; k++) {
        sums.push_back(ns[i] + ns[j] + ns[k]);
      }
    }
  }
  sort(sums.begin(), sums.end());
  cout << sums[sums.size() - 3] << endl;
  return 0;
}
