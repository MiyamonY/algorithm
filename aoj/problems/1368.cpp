///
// File:  1368.cpp
// Author: ymiyamoto
//
// Created on Thu Nov 30 21:58:14 2017
//

#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

uint32_t calc_e(array<uint32_t, 5> code, array<array<uint32_t, 10>, 10> matrix)
{
  uint32_t num = 0;
  for (uint32_t i = 0; i < code.size() - 1; i++) {
    num = matrix[num][code[i]];
  }
  return num;
}

bool check(array<uint32_t, 5> code, array<array<uint32_t, 10>, 10> matrix)
{
  uint32_t num = 0;
  for (uint32_t i = 0; i < code.size(); i++) {
    num = matrix[num][code[i]];
  }

  return num == 0;
}

int32_t main()
{
  array<array<uint32_t, 10>, 10> matrix;
  for (uint32_t i = 0; i < 10; i++) {
    for (uint32_t j = 0; j < 10; j++) {
      cin >> matrix[i][j];
    }
  }

  uint32_t count = 0;
  for (uint32_t i = 0; i < 10000; i++) {
    bool invalid = false;
    array<uint32_t, 5> code;
    code[0] = i / 1000;
    code[1] = (i - code[0] * 1000) / 100;
    code[2] = (i - code[0] * 1000 - code[1] * 100) / 10;
    code[3] = (i - code[0] * 1000 - code[1] * 100) % 10;
    code[4] = calc_e(code, matrix);

    for (uint32_t j = 0; j < 5; j++) {
      for (uint32_t k = 0; k < 10; k++) {
        array<uint32_t, 5> err(code);
        err[j] = k;
        if (err[j] != code[j]) {
          if (check(err, matrix)) {
            invalid = true;
          }
        }
      }
    }

    for (uint32_t j = 0; j < 5 - 1; j++) {
      array<uint32_t, 5> err(code);
      swap(err[j], err[j + 1]);
      if (err[j] != code[j] || err[j + 1] != code[j + 1]) {
        if (check(err, matrix)) {
          invalid = true;
        }
      }
    }

    if (invalid) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
