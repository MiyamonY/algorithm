///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 17 18:15:48 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t A, B, C;
  cin >> A >> B >> C;

  cout << C / min(A, B) << endl;

  return 0;
}
