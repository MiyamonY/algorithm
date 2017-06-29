///
// File:  stack.cpp
// Author: ymiyamoto
//
// Created on Fri Jun 30 06:03:58 2017
//

#include <cstdint>
#include <string>

#include "problems.hpp"

using namespace std;

#define ARRAY_SIZE 256
int32_t array[ARRAY_SIZE];
int32_t index = 0;

void stack_push(int32_t data)
{
  array[index] = data;
  index++;
}

bool stack_pop(int32_t &data)
{
  if (index > 0) {
    index--;
    data = array[index];
    return true;
  }

  return false;
}

#if !defined(TEST)
#include <iostream>

int32_t main()
{
  string str;

  while (cin >> str) {
    if (cin.eof()) break;
    int32_t data1, data2;
    switch (str.front()) {
    case '+':
      stack_pop(data2);
      stack_pop(data1);
      stack_push(data1 + data2);
      break;
    case '-':
      stack_pop(data2);
      stack_pop(data1);
      stack_push(data1 - data2);
      break;
    case '*':
      stack_pop(data2);
      stack_pop(data1);
      stack_push(data1 * data2);
      break;
    default:
      stack_push(stoi(str));
      break;
    }
    str.clear();
  }

  int32_t data;
  stack_pop(data);
  cout << data << endl;

  return 0;
}
#endif
