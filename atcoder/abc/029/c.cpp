///
//  Author : Author
// Created On : Thu Jan 11 2018
//  File : c.cpp
//
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

int32_t main() {
  uint32_t N;
  cin >> N;
  for (uint64_t i = 0; i < pow(3, N); i++) {
    string s;
    uint64_t x = i;
    for (uint32_t j = 0; j < N; j++) {
      s += string("abc")[x % 3];
      x /= 3;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
  }

  return 0;
}
