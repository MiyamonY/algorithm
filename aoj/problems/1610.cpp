///
// File:  1610.cpp
// Author: ymiyamoto
//
// Created on Wed Nov 29 00:50:26 2017
//

#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  while (true) {
    uint64_t m, n;
    cin >> m >> n;
    if (m == 0 && n == 0) break;

    array<bool, 7368792> years;
    for (uint64_t i = 0; i < years.size(); i++) {
      years[i] = true;
    }

    uint64_t year = m;
    for (uint64_t i = 0; i < n; i++) {
      for (uint64_t j = year; j < years.size(); j += year) {
        years[j] = false;
      }

      while (!years[year]) {
        year++;
      }
    }
    cout << year << endl;
  }
  return 0;
}
