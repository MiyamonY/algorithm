///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sun Jul 30 19:15:48 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  long long X, Y;
  cin >> X >> Y;

  if (abs(X - Y) <= 1) {
    cout << "Brown";
  } else {
    cout << "Alice";
  }
  cout << endl;

  return 0;
}
