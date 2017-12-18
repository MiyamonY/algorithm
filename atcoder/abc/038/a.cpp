///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Thu Dec 14 01:28:31 2017
//

#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

int32_t main()
{
  string str;
  cin >> str;
  if (str[str.size() - 1] == 'T') {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
