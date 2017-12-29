///
// File:  2254.cpp
// Author: ymiyamoto
//
// Created on Fri Dec 29 11:08:05 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;
enum turn_t {
  Left,
  Right,
};

uint32_t violates(string arrows, turn_t start)
{
  uint32_t left;
  uint32_t right;
  if (start == Left) {
    right = (arrows[0] - '0' + 2) % 3;
  } else {
    left = (arrows[0] - '0' + 2) % 3;
  }
  turn_t turn = start;

  uint32_t count = 0;
  for (uint32_t i = 1; i < arrows.size(); i++) {
    uint32_t arrow = (arrows[i] - '0' + 2) % 3;
    if (turn == Left) {
      if (arrow <= right) {
        left = arrow;
        turn = Right;
      } else {
        right = arrow;
        turn = Left;
        count++;
      }
    } else {
      if (left <= arrow) {
        right = arrow;
        turn = Left;
      } else {
        left = arrow;
        turn = Right;
        count++;
      }
    }
  }

  return count;
}

int32_t main()
{
  while (true) {
    string arrows;
    cin >> arrows;
    if (arrows[0] == '#') break;

    if (arrows.size() <= 2) {
      cout << 0 << endl;
      continue;
    }

    cout << min(violates(arrows, Left), violates(arrows, Right)) << endl;
  }
  return 0;
}
