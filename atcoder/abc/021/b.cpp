///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Jan 14 17:19:25 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(n, init, N) for (int32_t n = init; n < (int32_t)(N); n++)
#define rrep(n, N) for (int32_t n = (int32_t)(N)-1; n >= 0; n--)

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

int32_t main()
{
  uint32_t N;
  cin >> N;

  uint32_t a, b;
  cin >> a >> b;

  uint32_t K;
  cin >> K;

  vector<uint32_t> ps(K + 2, 0);
  ps[0] = a;
  ps[ps.size() - 1] = b;
  rep(i, 1, K + 1)
  {
    cin >> ps[i];
  }

  rep(i, 0, ps.size())
  {
    rep(k, 0, ps.size())
    {
      if (i != k) {
        if (ps[i] == ps[k]) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }

  cout << "YES" << endl;
  return 0;
}
