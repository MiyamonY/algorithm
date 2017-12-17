///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 17 10:11:58 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;
  vector<uint64_t> arr(N);

  for (uint32_t i = 0; i < N; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  uint64_t old = arr[0];
  uint32_t same_num = 1;
  uint32_t remove = 0;
  for (uint32_t i = 1; i < N; i++) {
    if (old != arr[i]) {
      if (same_num != old) {
        if (same_num > old) {
          remove += same_num - old;
        } else {
          remove += same_num;
        }
      }
      old = arr[i];
      same_num = 1;
    } else {
      same_num++;
    }
  }

  if (same_num != old) {
    if (same_num > old) {
      remove += same_num - old;
    } else {
      remove += same_num;
    }
  }
  cout << remove << endl;

  return 0;
}
