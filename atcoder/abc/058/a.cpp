///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sun Jul 30 19:27:11 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t a, b, c;
  cin >> a >> b >> c;

  if ((c - b) == (b - a)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;

  return 0;
}
