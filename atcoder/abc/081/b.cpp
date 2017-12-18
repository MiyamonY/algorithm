///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 10 21:23:57 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;
  vector<uint32_t> arr;
  for (uint32_t i = 0; i < N; i++) {
    uint32_t n;
    cin >> n;
    arr.push_back(n);
  }

  uint32_t count = 0;
  while (true) {
    bool has_odd = false;
    for (auto a : arr) {
      if (a % 2 == 1) {
        has_odd = true;
      }
    }
    if (has_odd) break;

    for (uint32_t i = 0; i < arr.size(); i++) {
      arr[i] /= 2;
    }
    count++;
  }

  cout << count << endl;
  return 0;
}
