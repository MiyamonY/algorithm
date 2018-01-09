///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Tue Jan  9 22:10:33 2018
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  double A, B, C, D;
  cin >> A >> B >> C >> D;

  if (A / B == C / D) {
    cout << "DRAW" << endl;
  } else if (A / B < C / D) {
    cout << "TAKAHASHI" << endl;
  } else {
    cout << "AOKI" << endl;
  }

  return 0;
}
