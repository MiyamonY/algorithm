///
// File:  1241.cpp
// Author: ymiyamoto
//
// Created on Fri Nov 24 21:15:52 2017
//

#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  while (true) {
    uint32_t n;
    cin >> n;
    if (n == 0) break;

    uint32_t val = sqrt(n);
    uint32_t count = 0;
    for (uint32_t i = 1; i <= val; i++) {
      for (uint32_t j = i; j <= val; j++) {
        for (uint32_t k = j; k <= val; k++) {
          for (uint32_t l = k; l <= val; l++) {
            if (n == i * i + j * j + k * k + l * l) {
              count += 1;
            }
          }
        }
      }
    }

    for (uint32_t i = 1; i <= val; i++) {
      for (uint32_t j = i; j <= val; j++) {
        for (uint32_t k = j; k <= val; k++) {
          if (n == i * i + j * j + k * k) {
            count += 1;
          }
        }
      }
    }

    for (uint32_t i = 1; i <= val; i++) {
      for (uint32_t j = i; j <= val; j++) {
        if (n == i * i + j * j) {
          count += 1;
        }
      }
    }

    if (n == val * val) {
      count++;
    }

    cout << count << endl;
  }

  return 0;
}
