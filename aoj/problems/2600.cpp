///
// File:  2600.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 24 03:06:16 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  int32_t N, W, H;
  cin >> N >> W >> H;

  vector<int32_t> h(W + 1);
  vector<int32_t> v(H + 1);
  for (int32_t i = 0; i < N; i++) {
    int32_t x, y, w;
    cin >> x >> y >> w;
    h[max(0, x - w)] += 1;
    h[min(x + w, W)] -= 1;
    v[max(0, y - w)] += 1;
    v[min(y + w, H)] -= 1;
  }

  bool coverage = true;
  for (int32_t i = 0; i < W; i++) {
    if (!(h[i] > 0)) {
      coverage = false;
    }
    h[i + 1] += h[i];
  }

  if (coverage) {
    cout << "Yes" << endl;
    return 0;
  }

  coverage = true;
  for (int32_t i = 0; i < H; i++) {
    if (!(v[i] > 0)) {
      coverage = false;
    }
    v[i + 1] += v[i];
  }

  if (coverage) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
