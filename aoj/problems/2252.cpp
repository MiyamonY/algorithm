///
// File:  2252.cpp
// Author: ymiyamoto
//
// Created on Fri Nov 10 08:11:03 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

enum hand_t {
  None,
  Right,
  Left,
};

bool is_right(char c)
{
  return (c == 'y' || c == 'u' || c == 'i' || c == 'o' || c == 'p' || c == 'h' || c == 'j' || c == 'k' || c == 'l' || c == 'n' || c == 'm');
}

int32_t main()
{
  while (true) {
    string str;
    cin >> str;
    if (str[0] == '#') break;

    hand_t hand = None;
    uint32_t count = 0;
    for (uint32_t i = 0; i < str.size(); i++) {
      if (is_right(str[i])) {
        if (hand == None) {
          hand = Right;
        } else {
          if (hand == Left) {
            count++;
            hand = Right;
          }
        }
      } else {
        if (hand == None) {
          hand = Left;
        } else {
          if (hand == Right) {
            count++;
            hand = Left;
          }
        }
      }
    }
    cout << count << endl;
  }

  return 0;
}
