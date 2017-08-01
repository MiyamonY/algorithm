///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sun Jul 30 23:43:57 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

#define ARRAY_MAX_NUM 50
#define ARRAY_LEN 26

static uint32_t array[ARRAY_MAX_NUM][ARRAY_LEN];

int32_t main()
{
  uint32_t n;
  cin >> n;

  for (uint32_t i = 0; i < n; i++) {
    string str;
    cin >> str;

    for (uint32_t j = 0; j < str.size(); j++) {
      array[i][str[j] - 'a']++;
    }
  }

  for (uint32_t i = 0; i < ARRAY_LEN; i++) {
    uint32_t count = UINT32_MAX;
    for (uint32_t j = 0; j < n; j++) {
      count = min(count, array[j][i]);
    }

    for (uint32_t k = 0; k < count; k++) {
      cout << (char)('a' + i);
    }
  }

  cout << endl;

  return 0;
}
