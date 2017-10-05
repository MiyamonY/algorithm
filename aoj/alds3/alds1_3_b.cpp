///
// File:  alds1_3_b.cpp
// Author: ymiyamoto
//
// Created on Fri Oct  6 01:08:23 2017
//

#include <cstdint>
#include <iostream>

using namespace std;
#define SIZE 200000
static pair<string, int32_t> que[SIZE];
static uint32_t top;
static uint32_t bottom;

static void push(pair<string, int32_t> val)
{
  que[bottom] = val;
  bottom++;
  bottom %= SIZE;
}

static pair<string, int32_t> pop()
{
  pair<string, int32_t> val = que[top];
  top++;
  top %= SIZE;
  return val;
}

static bool empty()
{
  return top == bottom;
}

int32_t main()
{
  int32_t n, q;
  cin >> n >> q;
  for (int32_t i = 0; i < n; i++) {
    string str;
    int32_t val;
    cin >> str >> val;
    push({str, val});
  }

  uint64_t current_time = 0;
  while (!empty()) {
    auto val = pop();
    if (val.second - q <= 0) {
      current_time += val.second;
      cout << val.first << " " << current_time << endl;
    } else {
      current_time += q;
      push({val.first, val.second - q});
    }
  }

  return 0;
}
