///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Fri Sep 29 20:21:11 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
static string turns;
static vector<char> my_turns;

int32_t main()
{
  cin >> turns;

  uint32_t g_count = 0;
  uint32_t p_count = 0;
  int32_t win_count = 0;
  int32_t lose_count = 0;

  for (uint32_t i = 0; i < turns.size(); i++) {
    if (turns[i] == 'g') {
      if (p_count < g_count) {
        p_count++;
        my_turns.push_back('p');
        win_count++;
      } else {
        g_count++;
        my_turns.push_back('g');
      }
    } else {
      if (p_count < g_count) {
        p_count++;
        my_turns.push_back('p');
      } else {
        g_count++;
        lose_count++;
        my_turns.push_back('g');
      }
    }
  }

  cout << win_count - lose_count << endl;

  return 0;
}
