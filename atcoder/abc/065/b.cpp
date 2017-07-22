///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Fri Jul 21 23:09:05 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

#define SIZE 100001
static uint32_t led[SIZE];
static bool status[SIZE];

int32_t main()
{
  uint32_t num;
  cin >> num;

  for (uint32_t i = 1; i <= num; i++) {
    status[i] = false;
    uint32_t val;
    cin >> val;
    led[i] = val;
  }

  uint32_t index = 1;
  uint32_t count = 0;
  while ((index != 2) && !status[index]) {
    status[index] = true;
    count++;

    index = led[index];
  }

  if (index == 2) {
    cout << count << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
