///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sun Aug  6 17:53:52 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

static long long NUM_S;
static long long NUM_C;

static bool can_create(long long num)
{
  if ((NUM_S - num) >= 0) {
    if (NUM_C >= 2 * num) {
      return true;
    }
  } else {
    if (NUM_C >= (2 * (num - NUM_S) + 2 * num)) {
      return true;
    }
  }

  return false;
}

int32_t main()
{
  cin >> NUM_S >> NUM_C;

  long long count = (NUM_C / 2) + 1;

  long long left = 0, right = count;
  while (true) {
    if (right <= left + 1) break;
    long long mid = (left + right) / 2;
    if (can_create(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }

  cout << left << endl;

  return 0;
}
