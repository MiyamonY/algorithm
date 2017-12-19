///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Mon Dec 18 02:23:17 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  int32_t N, K;
  cin >> N >> K;

  vector<uint64_t> arr(N + 1, 0);
  for (int32_t i = 1; i <= N; i++) {
    cin >> arr[i];
  }

  uint64_t total = 0;
  if (N - K < K) {
    for (int32_t i = 1; i <= N - K + 1; i++) {
      for (int32_t j = 0; j < K; j++) {
        total += arr[i + j];
      }
    }
  } else {
    for (int32_t i = 1; i <= N; i++) {
      if (i <= K) {
        total += i * arr[i];
      } else if (i <= N - K) {
        total += K * arr[i];
      } else {
        total += (N - i + 1) * arr[i];
      }
    }
  }

  cout << total << endl;

  return 0;
}
