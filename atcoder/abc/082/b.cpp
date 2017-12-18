///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 17 00:51:26 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string s, t;
  cin >> s;
  cin >> t;

  sort(s.begin(), s.end());
  sort(t.begin(), t.end(), greater<char>());

  if (s < t) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
