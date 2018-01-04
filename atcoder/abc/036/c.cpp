///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sat Dec 23 20:21:28 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;

  vector<int64_t> arr(N);
  for (uint32_t i = 0; i < N; i++) {
    cin >> arr[i];
  }

  vector<int64_t> arr1(arr);
  sort(arr1.begin(), arr1.end());

  int64_t val = -1;
  uint32_t num = 0;
  map<int64_t, uint32_t> kinds;
  for (uint32_t i = 0; i < N; i++) {
    if (val != arr1[i]) {
      kinds[arr1[i]] = num;
      val = arr1[i];
      num++;
    }
  }

  for (uint32_t i = 0; i < N; i++) {
    cout << kinds[arr[i]] << endl;
  }

  return 0;
}
