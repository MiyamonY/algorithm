///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sat Dec 23 20:13:50 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;

  vector<vector<char>> board(N, vector<char>(N));
  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  for (uint32_t i = 0; i < N; i++) {
    for (int32_t j = N - 1; j >= 0; j--) {
      cout << board[j][i];
    }
    cout << endl;
  }

  return 0;
}
