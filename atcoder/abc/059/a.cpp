///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sun Jul 30 16:01:52 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string a, b, c;
  cin >> a >> b >> c;

  cout << (char)(a[0] - 'a' + 'A') << (char)(b[0] - 'a' + 'A') << (char)(c[0] - 'a' + 'A') << endl;

  return 0;
}
