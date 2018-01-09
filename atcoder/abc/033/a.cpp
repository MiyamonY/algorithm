///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Fri Jan  5 23:53:13 2018
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string N;
  cin >> N;

  char c = N[0];
  for (uint32_t i = 1; i < N.size(); i++) {
    if (c != N[i]) {
      cout << "DIFFERENT" << endl;
      return 0;
    }
  }

  cout << "SAME" << endl;

  return 0;
}
