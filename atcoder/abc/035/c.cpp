///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Fri Jan  5 07:15:54 2018
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N, Q;
  cin >> N >> Q;

  vector<int32_t> board(N + 1, 0);
  for (uint32_t i = 0; i < Q; i++) {
    uint32_t l, r;
    cin >> l >> r;
    board[l - 1]++;
    board[r]--;
  }

  for (uint32_t i = 0; i < board.size() - 1; i++) {
    board[i + 1] += board[i];
  }

  for (uint32_t i = 0; i < N; i++) {
    if (board[i] % 2 == 1) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << endl;

  return 0;
}
