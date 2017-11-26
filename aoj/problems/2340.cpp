///
// File:  2340.cpp
// Author: ymiyamoto
//
// Created on Sun Nov 26 13:33:28 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t n;
  cin >> n;

  uint64_t lparen = 0;
  uint64_t rparen = 0;
  for (uint32_t i = 0; i < n; i++) {
    uint64_t p, n;
    char c;
    cin >> p >> c >> n;
    if (c == ')') {
      lparen += n;
    } else if (c == '(') {
      rparen += n;
    }

    if (lparen == rparen) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
