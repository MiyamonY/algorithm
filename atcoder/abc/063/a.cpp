///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Mon Jul 24 20:50:34 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t A, B;
  cin >> A >> B;

  if (A + B >= 10)
    cout << "error" << endl;
  else
    cout << A + B << endl;

  return 0;
}
