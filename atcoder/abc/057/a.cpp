///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Wed Aug  2 01:09:38 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t A, B;

  cin >> A >> B;

  cout << (A + B) % 24 << endl;

  return 0;
}
