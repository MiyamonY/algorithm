///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Fri Jan 12 00:40:52 2018
//
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;

  vector<uint32_t> num(N);
  uint32_t total = 0;
  for (uint32_t i = 0; i < N; i++) {
    cin >> num[i];
    total += num[i];
  }

  if (total % N != 0) {
    cout << -1 << endl;
    return 0;
  }

  int32_t ave = total / N;
  vector<int32_t> diffs(N);
  for (uint32_t i = 0; i < N; i++) {
    diffs[i] = ave - num[i];
  }

  int32_t diff = 0;
  uint32_t count = 0;
  for (uint32_t i = 0; i < N; i++) {
    diff += diffs[i];
    if (diff != 0) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
