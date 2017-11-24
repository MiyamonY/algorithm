///
// File:  1285.cpp
// Author: ymiyamoto
//
// Created on Tue Nov 21 21:45:11 2017
//

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  while (true) {
    uint32_t n, w;
    cin >> n >> w;
    if (n == 0 && w == 0) break;
    uint32_t num = 100 / w;
    vector<uint32_t> counts(num + 1, 0);

    uint32_t max_count = 0;
    uint32_t max_index = 0;
    for (uint32_t i = 0; i < n; i++) {
      uint32_t val;
      cin >> val;
      for (uint32_t j = 0; j < counts.size(); j++) {
        if (j * w <= val && val < j * w + w) {
          counts[j]++;
          max_count = max(max_count, counts[j]);
          max_index = max(max_index, j);
          break;
        }
      }
    }

    double ink = 0.01;
    for (uint32_t i = 0; i < counts.size(); i++) {
      ink += (double)counts[i] / (double)max_count * (double)(max_index - i) / (double)max_index;
    }
    cout << fixed << setprecision(8) << ink << endl;
  }

  return 0;
}
