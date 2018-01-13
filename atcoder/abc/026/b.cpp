///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sat Jan 13 14:35:51 2018
//
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
  uint32_t N;
  cin >> N;

  vector<double> rs(N);
  for (uint32_t i = 0; i < N; i++) {
    cin >> rs[i];
  }

  sort(rs.begin(), rs.end(), greater<double>());

  rs.push_back(0);

  double ans = 0.0;
  for (uint32_t i = 0; i < rs.size() - 1; i++) {
    if (i % 2 == 0) {
      ans += 2 * asin(1) * (rs[i] * rs[i] - rs[i + 1] * rs[i + 1]);
    }
  }

  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}
