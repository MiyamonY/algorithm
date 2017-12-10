///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 10 21:38:08 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;

  vector<int32_t> arr(N);
  int32_t max_val = INT32_MIN;
  int32_t min_val = INT32_MAX;
  int32_t max_index = 0;
  int32_t min_index = 0;
  bool all_positive = true;
  bool all_negative = true;
  for (uint32_t i = 0; i < N; i++) {
    cin >> arr[i];
    if (arr[i] > 0) {
      all_negative = false;
    } else if (arr[i] < 0) {
      all_positive = false;
    }
    if (max_val < arr[i]) {
      max_index = i;
      max_val = arr[i];
    }
    if (arr[i] < min_val) {
      min_index = i;
      min_val = arr[i];
    }
  }

  if (all_positive) {
    cout << N - 1 << endl;
    for (uint32_t i = 1; i < N; i++) {
      cout << i << " " << i + 1 << endl;
    }
  } else if (all_negative) {
    cout << N - 1 << endl;
    for (int32_t i = N; i > 1; i--) {
      cout << i << " " << i - 1 << endl;
    }
  } else if (abs(min_val) <= abs(max_val)) {
    cout << 2 * N - 1 << endl;
    for (uint32_t i = 1; i <= N; i++) {
      cout << max_index + 1 << " " << i << endl;
    }
    for (uint32_t i = 1; i < N; i++) {
      cout << i << " " << i + 1 << endl;
    }
  } else {
    cout << 2 * N - 1 << endl;
    for (uint32_t i = 1; i <= N; i++) {
      cout << min_index + 1 << " " << i << endl;
    }
    for (int32_t i = N; i > 1; i--) {
      cout << i << " " << i - 1 << endl;
    }
  }

  return 0;
}
