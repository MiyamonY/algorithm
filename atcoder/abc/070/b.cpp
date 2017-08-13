///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Mon Aug 14 01:51:47 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t A, B, C, D;
  cin >> A >> B >> C >> D;

  if (D <= A) {
    cout << 0 << endl;
  } else if (B <= C) {
    cout << 0 << endl;
  } else {
    cout << min(B, D) - max(A, C) << endl;
  }

  return 0;
}
