///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 31 17:25:47 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  uint32_t N, M;
  cin >> N >> M;
  string str;
  cin >> str;

  for (uint32_t i = 0; i < N; i++) {
    if (!('0' <= str[i] && str[i] <= '9')) {
      cout << "No" << endl;
      return 0;
    }
  }

  if (!(str[N] == '-')) {
    cout << "No" << endl;
    return 0;
  }

  for (uint32_t i = N + 1; i < str.size(); i++) {
    if (!('0' <= str[i] && str[i] <= '9')) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
