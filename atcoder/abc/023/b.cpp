///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Jan 14 16:40:55 2018
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
  string S;
  cin >> S;

  string s = "";
  int32_t i = 0;
  while (true) {
    if (i == 0) {
      s = "b";
    } else {
      switch (i % 3) {
      case 0:
        s = "b" + s;
        s += 'b';
        break;
      case 1:
        s = "a" + s;
        s += 'c';
        break;
      case 2:
        s = "c" + s;
        s += 'a';
        break;
      }
    }

    if (s.size() >= S.size()) {
      if (S == s) {
        cout << i << endl;
      } else {
        cout << -1 << endl;
      }
      return 0;
    }
    i++;
  }
}
