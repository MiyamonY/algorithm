///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Thu Jan 18 23:00:23 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(_n, _init, _N) for (int32_t _n = _init; _n < (int32_t)(_N); _n++)
#define rrep(_n, _N, _end) for (int32_t _n = (int32_t)(_N); _n >= _end; _n--)
#define iceil(_x, _y) (((_x) + (_y)-1) / (_y))
#define ifloor(_x, _y) ((_x) / (_y))

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

int32_t main()
{
  string S;
  cin >> S;

  uint32_t N;
  cin >> N;

  rep(i, 0, N)
  {
    uint32_t start, end;
    cin >> start >> end;
    string s = S.substr(start - 1, end - start + 1);
    reverse(s.begin(), s.end());
    rep(k, start - 1, end)
    {
      S[k] = s[k - start + 1];
    }
  }

  cout << S << endl;

  return 0;
}
