///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Tue Aug  8 00:27:23 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

#define IMAGE_SIZE 50

int32_t main()
{
  uint32_t N, M;
  cin >> N >> M;

  char A[IMAGE_SIZE][IMAGE_SIZE], B[IMAGE_SIZE][IMAGE_SIZE];
  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }

  for (uint32_t i = 0; i < M; i++) {
    for (uint32_t j = 0; j < M; j++) {
      cin >> B[i][j];
    }
  }

  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = 0; j < N; j++) {
      bool is_same = true;
      for (uint32_t k = 0; k < M; k++) {
        for (uint32_t l = 0; l < M; l++) {
          if (((i + k) < N) && ((j + l) < N)) {
            if (A[i + k][j + l] != B[k][l]) {
              is_same = false;
            }
          } else {
            is_same = false;
          }
        }
      }

      if (is_same) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  return 0;
}
