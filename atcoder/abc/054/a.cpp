///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Tue Aug  8 00:22:25 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t A, B;
  cin >> A >> B;

  if (A == B) {
    cout << "Draw";
  } else if (A == 1) {
    cout << "Alice";
  } else if (B == 1) {
    cout << "Bob";
  } else if (A < B) {
    cout << "Bob";
  } else {
    cout << "Alice";
  }

  return 0;
}
