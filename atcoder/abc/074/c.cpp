///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Mon Sep 18 19:43:18 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  int32_t A, B, C, D, E, F;

  cin >> A >> B >> C >> D >> E >> F;

  int32_t water = 0;
  int32_t sugar = 0;

  for (int32_t i = 0; (100 * A * i) <= F; i++) {
    for (int32_t j = 0; (100 * A * i) + (100 * B * j) <= F; j++) {
      for (int32_t k = 0; (100 * A * i) + (100 * B * j) + (C * k) <= F; k++) {
        for (int32_t l = 0; (100 * A * i) + (100 * B * j) + (C * k) + (D * l) <= F; l++) {
          int32_t x = A * 100 * i + B * 100 * j;
          int32_t y = C * k + D * l;
          if (((y * 100) <= (x * E)) && ((sugar * (x + y)) <= (y * (water + sugar)))) {
            water = x;
            sugar = y;
          }
        }
      }
    }
  }

  cout << water + sugar << " " << sugar << endl;

  return 0;
}
