///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 17 18:17:54 2017
//

#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

int32_t main()
{
  uint32_t N, Q;
  cin >> N >> Q;
  vector<uint32_t> arr(N + 1, 0);

  for (uint32_t i = 0; i < Q; i++) {
    uint32_t L, R, T;
    cin >> L >> R >> T;
    for (uint32_t j = L; j <= R; j++) {
      arr[j] = T;
    }
  }

  for (uint32_t i = 1; i <= N; i++) {
    cout << arr[i] << endl;
  }

  return 0;
}
