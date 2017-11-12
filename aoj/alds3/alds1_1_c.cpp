///
// File:  alds1_1_c.cpp
// Author: ymiyamoto
//
// Created on Mon Nov 13 02:50:09 2017
//

#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

bool is_prime(uint32_t num)
{
  for (uint32_t i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int32_t main()
{
  uint32_t n;
  cin >> n;

  uint32_t count = 0;
  for (uint32_t i = 0; i < n; i++) {
    uint32_t num;
    cin >> num;
    if (is_prime(num)) {
      count++;
    }
  }
  cout << count << endl;

  return 0;
}
