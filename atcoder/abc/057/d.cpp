///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Thu Aug  3 01:11:42 2017
//

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
#define MAX_NUM 50
uint32_t counts[MAX_NUM];
long long comb[MAX_NUM + 1][MAX_NUM + 1];

static void calc_comb()
{
  for (uint32_t i = 0; i <= MAX_NUM; i++) {
    for (uint32_t j = 0; j <= i; j++) {
      if ((j == 0) || (i == j)) {
        comb[i][j] = 1;
      } else {
        comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
      }
    }
  }
}

int32_t main()
{
  int64_t N, A, B;

  cin >> N >> A >> B;

  calc_comb();

  vector<uint64_t> values;
  for (uint32_t i = 0; i < N; i++) {
    uint64_t value;
    cin >> value;
    values.push_back(value);
  }

  sort(values.begin(), values.end());
  reverse(values.begin(), values.end());

  long double total = 0;
  for (uint32_t i = 0; i < A; i++) {
    total += values[i];
  }

  long double ave = total / A;

  cout << fixed << setprecision(6) << ave << endl;

  long long nums = 0;
  if (values[0] == values[A - 1]) {
    int64_t same_num = 0;
    for (uint32_t i = 0; i < N; i++) {
      if (values[i] == values[0]) {
        same_num++;
      }
    }

    for (uint32_t i = A; i <= min(B, same_num); i++) {
      nums += comb[same_num][i];
    }

  } else {
    uint32_t selected_num = 0;
    uint32_t same_num = 0;
    for (uint32_t i = 0; i < N; i++) {
      if (i < A) {
        if (values[A - 1] == values[i]) {
          selected_num++;
        }
      }
      if (values[A - 1] == values[i]) {
        same_num++;
      }
    }
    nums = comb[same_num][selected_num];
  }

  cout << nums << endl;

  return 0;
}
