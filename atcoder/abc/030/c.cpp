///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Tue Jan  9 23:46:17 2018
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  uint32_t N, M;
  cin >> N >> M;
  uint32_t X, Y;
  cin >> X >> Y;

  vector<uint32_t> as(N, 0);
  vector<uint32_t> bs(M, 0);
  for (uint32_t i = 0; i < N; i++) {
    cin >> as[i];
  }

  for (uint32_t i = 0; i < M; i++) {
    cin >> bs[i];
  }

  uint32_t count = 0;
  uint32_t t = 0;
  while (true) {
    auto i_a = lower_bound(as.begin(), as.end(), t);
    if (i_a >= as.end()) {
      break;
    }
    t = *i_a;
    t += X;
    auto i_b = lower_bound(bs.begin(), bs.end(), t);
    if (i_b >= bs.end()) {
      break;
    }
    t = *i_b;
    t += Y;
    count++;
  }

  cout << count << endl;

  return 0;
}
