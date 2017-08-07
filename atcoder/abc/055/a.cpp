///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sun Aug  6 17:46:40 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

int32_t main()
{
  uint64_t N;
  cin >> N;

  cout << N * 800 - ((N / 15) * 200) << endl;

  return 0;
}
