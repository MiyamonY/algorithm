///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sat Dec 23 21:41:27 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t A, B, C, D;
  cin >> A >> B >> C >> D;

  if (A + B == C + D) {
    cout << "Balanced" << endl;
  } else if (A + B < C + D) {
    cout << "Right" << endl;
  } else {
    cout << "Left" << endl;
  }

  return 0;
}
