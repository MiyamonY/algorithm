///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Wed Jul 26 00:39:26 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  vector<uint32_t> group1{1, 3, 5, 7, 8, 10, 12};
  vector<uint32_t> group2{4, 6, 9, 11};
  vector<uint32_t> group3{2};

  uint32_t x, y;
  cin >> x >> y;

  uint32_t group_x = 0, group_y = 0;
  for (uint32_t i = 0; i < group1.size(); i++) {
    if (x == group1[i]) group_x = 1;
    if (y == group1[i]) group_y = 1;
  }

  for (uint32_t i = 0; i < group2.size(); i++) {
    if (x == group2[i]) group_x = 2;
    if (y == group2[i]) group_y = 2;
  }

  for (uint32_t i = 0; i < group3.size(); i++) {
    if (x == group3[i]) group_x = 3;
    if (y == group3[i]) group_y = 3;
  }

  if (group_x == group_y)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
