///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Jan 14 01:16:32 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(n, i, N) for (int32_t n = i; n < (int32_t)(N); n++)
#define rrep(n, N) for (int32_t n = (int32_t)(N)-1; n >= 0; n--)

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

int32_t main()
{
  int32_t N, A, B;
  cin >> N >> A >> B;

  int32_t pos = 0;
  rep(i, 0, N)
  {
    string dir;
    int32_t dist;
    cin >> dir >> dist;
    if (dist < A) {
      dist = A;
    } else if (dist > B) {
      dist = B;
    }

    if (dir == "East") {
      pos += dist;
    } else {
      pos -= dist;
    }
  }

  if (pos == 0) {
    cout << "0" << endl;
  } else if (pos > 0) {
    cout << "East " << abs(pos) << endl;
  } else {
    cout << "West " << abs(pos) << endl;
  }
  return 0;
}
