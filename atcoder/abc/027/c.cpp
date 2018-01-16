///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Fri Jan 12 00:53:26 2018
//
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
  uint64_t N;
  cin >> N;

  uint64_t count = 0;
  for (uint64_t n = N; n > 1; n /= 2) {
    count++;
  }

  uint64_t x = 1;
  bool win_takahashi = true;
  if (count % 2 == 0) {
    while (true) {
      x = 2 * x + 1;
      if (N < x) {
        win_takahashi = false;
        break;
      }
      x *= 2;
      if (N < x) {
        break;
      }
    }
  } else {
    while (x < N) {
      x *= 2;
      if (N < x) {
        win_takahashi = false;
        break;
      }
      x = 2 * x + 1;
      if (N < x) {
        break;
      }
    }
  }

  if (win_takahashi) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }

  return 0;
}
