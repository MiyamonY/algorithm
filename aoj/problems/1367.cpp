///
// File:  1367.cpp
// Author: ymiyamoto
//
// Created on Wed Nov 29 07:40:28 2017
//

#include <array>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

int32_t main()
{
  uint32_t n, m;
  cin >> n >> m;

  vector<uint32_t> q(m, 0);
  for (uint32_t i = 0; i < m; i++) {
    cin >> q[i];
  }

  vector<bool> printed(n + 1, 0);
  for (int32_t i = q.size() - 1; i >= 0; i--) {
    if (!printed[q[i]]) {
      cout << q[i] << endl;
      printed[q[i]] = true;
    }
  }

  for (uint32_t i = 1; i <= n; i++) {
    if (!printed[i]) {
      cout << i << endl;
      printed[i] = true;
    }
  }
  return 0;
}
