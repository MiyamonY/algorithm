///
//  Author : Author
// Created On : Mon Dec 18 2017
//  File : c.cpp
//
#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

int32_t main() {
  uint64_t N, M;
  cin >> N >> M;

  cout << (1900 * M + 100 * (N - M)) * pow(2, M) << endl;

  return 0;
}
