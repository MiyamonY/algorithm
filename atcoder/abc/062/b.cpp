///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Wed Jul 26 00:44:56 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  uint32_t H, W;
  cin >> H >> W;

  for (uint32_t i = 0; i < W + 2; i++) {
    cout << "#";
  }
  cout << endl;

  for (uint32_t i = 0; i < H; i++) {
    string str;
    cin >> str;
    cout << "#" << str << "#" << endl;
  }

  for (uint32_t i = 0; i < W + 2; i++) {
    cout << "#";
  }
  cout << endl;

  return 0;
}
