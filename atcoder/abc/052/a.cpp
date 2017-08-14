///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Wed Aug  9 18:20:25 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t A, B, C, D;
  cin >> A >> B >> C >> D;

  cout << max(A * B, C * D) << endl;

  return 0;
}
