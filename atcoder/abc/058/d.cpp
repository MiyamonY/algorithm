///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sun Jul 30 23:53:26 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static const long long MOD = ((1e9) + 7);

static vector<long long> xs;
static vector<long long> ys;

int32_t main()
{
  uint32_t n, m;
  cin >> n >> m;

  xs.push_back(0);
  for (uint32_t i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    xs.push_back(x);
  }

  ys.push_back(0);
  for (uint32_t i = 1; i <= m; i++) {
    long long y;
    cin >> y;
    ys.push_back(y);
  }

  long long sum_x = 0;
  for (uint32_t k = 1; k <= n; k++) {
    sum_x += (k - 1) * xs[k] - (n - k) * xs[k];
    sum_x = (sum_x + MOD) % MOD;
  }

  long long sum_y = 0;
  for (uint32_t k = 1; k <= m; k++) {
    sum_y += (k - 1) * ys[k] - (m - k) * ys[k];
    sum_y = (sum_y + MOD) % MOD;
  }

  long long ans = (sum_x * sum_y) % MOD;

  cout << ans << endl;

  return 0;
}
