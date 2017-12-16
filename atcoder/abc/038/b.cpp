///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Thu Dec 14 01:31:09 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint32_t H1, H2, W1, W2;
  cin >> H1 >> W1;
  cin >> H2 >> W2;
  if (H1 == H2 || H1 == W2 || H2 == W1 || W1 == W2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
