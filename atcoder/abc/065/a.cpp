///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Fri Jul 21 22:55:11 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  int32_t x, a, b;
  cin >> x >> a >> b;

  if (b <= a)
    cout << "delicious" << endl;
  else if (b <= (a + x))
    cout << "safe" << endl;
  else
    cout << "dangerous" << endl;

  return 0;
}
