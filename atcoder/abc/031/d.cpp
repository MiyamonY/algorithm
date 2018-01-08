///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Tue Jan  9 02:47:08 2018
//
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int32_t main()
{
  int32_t N, K;
  cin >> K >> N;

  vector<pair<string, string>> inputs;
  for (int32_t i = 0; i < N; i++) {
    string v, w;
    cin >> v >> w;
    inputs.push_back({v, w});
  }

  int32_t cnt = pow(3, K);
  for (int32_t i = 0; i < cnt; i++) {
    vector<uint32_t> lens(K + 1);
    int32_t x = i;
    for (int32_t j = 1; j <= K; j++) {
      lens[j] = x % 3 + 1;
      x /= 3;
    }

    vector<string> logos(K + 1, "");
    bool invalid = false;
    for (auto in : inputs) {
      string v = in.first;
      string w = in.second;
      uint32_t index = 0;
      for (auto c : v) {
        int32_t n = c - '0';

        if (index + lens[n] > w.size()) {
          invalid = true;
          break;
        }

        string sub = w.substr(index, lens[n]);
        if (logos[n] == "") {
          logos[n] = sub;
        } else if (logos[n] != sub) {
          invalid = true;
          break;
        }
        index += lens[n];
      }

      if (index != w.size()) {
        invalid = true;
      }

      if (invalid) break;
    }

    if (!invalid) {
      for (int32_t j = 1; j <= K; j++) {
        cout << logos[j] << endl;
      }
      return 0;
    }
  }

  return 0;
}
