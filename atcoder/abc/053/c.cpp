///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Wed Aug  9 16:59:40 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

static bool is_get(long long x, long long n)
{
  if (x <= (5 * n + (n + 1) / 2)) return true;

  return false;
}

int32_t main()
{
  long long x;
  cin >> x;

  long long left = 0;
  long long right = x + 1;
  long long mid = (left + right) / 2;

  while (left + 1 < right) {
    if (is_get(x, mid)) {
      right = mid;
    } else {
      left = mid;
    }
    mid = (left + right) / 2;
  }

  cout << right << endl;

  return 0;
}
