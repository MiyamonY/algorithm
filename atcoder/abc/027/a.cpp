///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Fri Jan 12 00:39:08 2018
//
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
  uint32_t l1, l2, l3;
  cin >> l1 >> l2 >> l3;

  if (l1 == l2) {
    cout << l3 << endl;
  } else if (l2 == l3) {
    cout << l1 << endl;
  } else if (l3 == l1) {
    cout << l2 << endl;
  }

  return 0;
}
