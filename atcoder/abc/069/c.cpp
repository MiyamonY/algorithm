///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sun Aug  6 21:53:44 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

static uint32_t num4;
static uint32_t even;
static uint32_t odd;

int32_t main()
{
  uint64_t N;
  cin >> N;

  for (uint64_t i = 0; i < N; i++) {
    uint64_t num;
    cin >> num;
    if ((num % 4) == 0) {
      num4++;
    } else if ((num % 2) == 0) {
      even++;
    } else {
      odd++;
    }
  }

  bool res = false;
  if ((num4 + 1) == odd) {
    if (even == 0) res = true;
  } else if (num4 >= odd) {
    res = true;
  }

  if (res) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
