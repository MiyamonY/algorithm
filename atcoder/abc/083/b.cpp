///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sat Dec 23 21:43:58 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  int32_t N, A, B;
  cin >> N >> A >> B;

  int32_t num = 0;
  for (int32_t i = 1; i <= N; i++) {
    int32_t total = 0;
    string str = to_string(i);
    for (auto c : str) {
      total += c - '0';
    }
    if (A <= total && total <= B) {
      num += i;
    }
  }

  cout << num << endl;

  return 0;
}
