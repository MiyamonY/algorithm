///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sat Oct 14 21:37:27 2017
//

#include <cstdint>
#include <iostream>
using namespace std;

#define SIZE 50

static uint32_t graph[SIZE][SIZE];

int32_t main()
{
  uint32_t N, M;
  cin >> N >> M;

  for (uint32_t i = 0; i < M; i++) {
    uint32_t from, to;
    cin >> from >> to;
    graph[from - 1][to - 1] = 1;
    graph[to - 1][from - 1] = 1;
  }

  uint32_t count = 0;
  while (true) {
    bool found = false;
    for (uint32_t i = 0; i < N; i++) {
      uint32_t connects = 0;
      int32_t at_i, at_j = 0;
      for (uint32_t j = 0; j < N; j++) {
        if (graph[i][j] == 1) {
          connects += 1;
          at_i = i;
          at_j = j;
        }
      }
      if (connects == 1) {
        count++;
        graph[at_i][at_j] = 0;
        graph[at_j][at_i] = 0;
        found = true;
      }
    }

    if (!found) {
      break;
    }
  }

  cout << count << endl;

  return 0;
}
