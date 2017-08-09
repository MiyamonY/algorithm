///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Wed Aug  9 18:07:55 2017
//

#include <cstdint>
#include <iostream>

using namespace std;
#define MAX_CARDS_NUM 100000

static uint32_t cards[MAX_CARDS_NUM + 1];

int32_t main()
{
  uint32_t N;
  cin >> N;

  for (uint32_t i = 0; i < N; i++) {
    uint32_t num;
    cin >> num;
    cards[num]++;
    if (cards[num] == 3) {
      cards[num] = 1;
    }
  }

  uint32_t double_num = 0;
  uint32_t different_num = 0;
  for (uint32_t i = 1; i <= MAX_CARDS_NUM; i++) {
    if (cards[i] > 0) {
      different_num++;
    }

    if (cards[i] == 2) {
      double_num++;
    }
  }

  if (double_num == 0) {
    cout << different_num << endl;
  } else {
    if (double_num % 2 == 0) {
      cout << different_num << endl;
    } else {
      cout << different_num - 1 << endl;
    }
  }

  return 0;
}
