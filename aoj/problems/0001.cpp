///
// File:  0001.cpp
// Author: ymiyamoto
//
// Created on Sat Nov  4 15:34:23 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  vector<uint32_t> heights(10);

  for (uint32_t i = 0; i < 10; i++) {
    cin >> heights[i];
  }

  sort(heights.begin(), heights.end());

  cout << heights[heights.size() - 1] << endl;
  cout << heights[heights.size() - 2] << endl;
  cout << heights[heights.size() - 3] << endl;

  return 0;
}
