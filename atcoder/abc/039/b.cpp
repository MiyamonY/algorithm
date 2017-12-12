///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Wed Dec 13 01:26:52 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint64_t X;
  cin >> X;
  for (uint32_t i = 0; i * i * i * i <= X; i++) {
    if (i * i * i * i == X) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
