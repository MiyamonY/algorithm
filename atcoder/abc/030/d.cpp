///
//  Author : ymiyamoto
// Created On : Thu Jan 11 2018
//  File : d.cpp
//
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int32_t main() {
  uint64_t N, a;
  string k;
  cin >> N >> a >> k;

  vector<uint32_t> b(N + 1, 0);
  for (uint32_t i = 1; i <= N; i++) {
    cin >> b[i];
  }

  uint32_t n = a;
  if (k.size() <= 5) {
    for (int32_t i = 0; i < stoi(k); i++) {
      n = b[n];
    }
    cout << n << endl;
    return 0;
  }

  uint32_t T = 0, C = 0;
  uint32_t m = a;
  vector<int32_t> ind(N + 1, -1);
  ind[m] = 0;
  for (uint32_t i = 1; i <= N; i++) {
    m = b[m];
    if (ind[m] == -1) {
      ind[m] = i;
    } else {
      T = ind[m];
      C = i - ind[m];
    }
  }

  uint32_t k_mod_c = 0;
  for (uint32_t i = 0; i < k.size(); i++) {
    k_mod_c = (k_mod_c * 10 + k[i] - '0') % C;
  }

  while (k_mod_c < T) {
    k_mod_c += C;
  }

  uint32_t l = a;
  for (uint32_t i = 0; i < k_mod_c; i++) {
    l = b[l];
  }

  cout << l << endl;
  return 0;
}
