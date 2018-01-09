///
// File:  2590.cpp
// Author: ymiyamoto
//
// Created on Thu Dec 28 11:40:56 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int32_t main()
{
  while (true) {
    uint32_t N, M, Q;
    cin >> N >> M >> Q;
    if (N == 0 && M == 0 && Q == 0) break;

    vector<bool> sw(N, false);
    vector<vector<bool>> switches(M, vector<bool>(N, true));
    for (uint32_t i = 0; i < Q; i++) {
      string ops, state;
      cin >> ops >> state;

      for (auto &op : ops) {
        if (op == '1') {
          sw[(&op - &ops[0])] = !sw[(&op - &ops[0])];
        }
      }

      for (uint32_t j = 0; j < state.size(); j++) {
        for (uint32_t k = 0; k < ops.size(); k++) {
          if (state[j] == '1') {
            if (!sw[k]) {
              switches[j][k] = false;
            }
          } else {
            if (sw[k]) {
              switches[j][k] = false;
            }
          }
        }
      }
    }

    string nums = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers;
    for (uint32_t i = 0; i < M; i++) {
      bool not_determine = false;
      int32_t num = -1;
      for (uint32_t j = 0; j < N; j++) {
        if (switches[i][j]) {
          if (num != -1) {
            not_determine = true;
          }
          num = j;
        }
      }
      if (not_determine) {
        numbers += '?';
      } else {
        numbers += nums[num];
      }
    }
    cout << numbers << endl;
  }

  return 0;
}
