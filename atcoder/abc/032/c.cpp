///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sat Jan  6 20:22:23 2018
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N, K;
  cin >> N >> K;

  vector<uint32_t> arr(N, 0);
  for (uint32_t i = 0; i < N; i++) {
    cin >> arr[i];
    if (arr[i] == 0) {
      cout << N << endl;
      return 0;
    }
  }

  uint32_t start = 0;
  uint32_t end = 1;
  uint32_t len = 0;
  uint64_t total = arr[start];
  do {
    if (total <= K) {
      len = max(len, end - start);
      total *= arr[end];
      end++;
    } else {
      total /= arr[start];
      start++;
      if (start == end) {
        total *= arr[end];
        end++;
      }
    }
  } while (end <= arr.size());

  cout << len << endl;

  return 0;
}
