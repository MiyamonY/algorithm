///
//  Author : Author
// Created On : Mon Dec 18 2017
//  File : d.cpp
//
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main() {
  int64_t N, Z, W;
  cin >> N >> Z >> W;

  vector<int64_t> cards(N);
  for (uint32_t i = 0; i < N; i++) {
    cin >> cards[i];
  }

  int64_t prev = 0;
  if (cards.size() > 1) {
    prev = abs(cards[cards.size() - 2] - cards[cards.size() - 1]);
  }

  cout << max(prev, abs(cards[cards.size() - 1] - W)) << endl;

  return 0;
}
