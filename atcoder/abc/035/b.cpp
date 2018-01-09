///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Fri Jan  5 07:08:39 2018
//
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string S;
  cin >> S;

  int32_t x = 0;
  int32_t y = 0;
  uint32_t count = 0;
  for (auto s : S) {
    switch (s) {
    case 'L':
      x -= 1;
      break;
    case 'R':
      x += 1;
      break;
    case 'U':
      y += 1;
      break;
    case 'D':
      y -= 1;
      break;
    case '?':
      count++;
      break;
    }
  }

  int32_t T;
  cin >> T;
  uint32_t dist = abs(x) + abs(y);
  if (T == 1) {
    cout << dist + count << endl;
  } else {
    if (dist > count) {
      cout << dist - count << endl;

    } else {
      cout << (count - dist) % 2 << endl;
    }
  }
  return 0;
}
