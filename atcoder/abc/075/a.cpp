///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sat Oct 14 21:26:32 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  int32_t A, B, C;
  cin >> A >> B >> C;

  if (A == B) {
    cout << C << endl;
  } else if (B == C) {
    cout << A << endl;
  } else {
    cout << B << endl;
  }

  return 0;
}
