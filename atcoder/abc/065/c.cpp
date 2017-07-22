///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Fri Jul 21 23:16:58 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

#define DIV 1000000007
#define SIZE 10001
long long facts[10001];

long long fact(uint64_t n)
{
  long long val = 1;
  for (uint32_t i = 1; i <= n; i++) {
    val *= i;
    val %= DIV;
  }

  return val;
}

int32_t main()
{
  uint64_t n, m;
  cin >> n >> m;

  if (n == m) {
    cout << (fact(n) * fact(m) * 2) % DIV;
  } else if ((n == m + 1) || (n + 1 == m)) {
    cout << (fact(n) * fact(m)) % DIV;
  } else {
    cout << 0;
  }
  cout << endl;

  return 0;
}
