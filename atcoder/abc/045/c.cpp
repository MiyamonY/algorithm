///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sun Oct  1 21:09:59 2017
//

#include <cstdint>
#include <iostream>
#include <map>
#include <string>

using namespace std;
#define SIZE 10

static bool sep[SIZE];
static string str;

static uint64_t calc_count()
{
  uint64_t count = 0;
  uint64_t val = 0;
  for (uint32_t i = 0; i < str.size(); i++) {
    val *= 10;
    val += str[i] - '0';
    if (sep[i]) {
      count += val;
      val = 0;
    }
  }
  count += val;
  return count;
}

static uint64_t perm(uint32_t i, uint32_t N)
{
  uint64_t count = 0;

  if (i < N) {
    sep[i] = true;
    count += perm(i + 1, N);
    sep[i] = false;
    count += perm(i + 1, N);
  } else {
    count += calc_count();
  }

  return count;
}

int32_t main()
{
  cin >> str;

  cout << perm(0, str.size() - 1) << endl;

  return 0;
}
