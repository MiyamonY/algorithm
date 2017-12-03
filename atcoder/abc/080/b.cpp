///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Dec  3 21:03:20 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string str;
  cin >> str;

  int64_t n = stoll(str);

  int64_t sum = 0;
  for (uint32_t i = 0; i < str.size(); i++) {
    sum += str[i] - '0';
  }

  if (n % sum == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
