///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Jan 14 17:01:24 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(n, init, N) for (int32_t n = init; n < (int32_t)(N); n++)
#define rrep(n, N) for (int32_t n = (int32_t)(N)-1; n >= 0; n--)

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

static vector<bool> visited(100000, false);

int32_t main()
{
  uint32_t N;
  cin >> N;

  uint32_t count = 0;
  rep(i, 0, N)
  {
    uint32_t A;
    cin >> A;
    if (visited[A - 1]) {
      count++;
    } else {
      visited[A - 1] = true;
    }
  }

  cout << count << endl;

  return 0;
}
