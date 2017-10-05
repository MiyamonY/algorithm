///
// File:  alds1_3_a.cpp
// Author: ymiyamoto
//
// Created on Fri Oct  6 00:43:19 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

#define SIZE 200

static int64_t array[SIZE];
static uint32_t index;

static int64_t pop()
{
  index--;
  int64_t val = array[index];
  return val;
}

static void push(int64_t val)
{
  array[index] = val;
  index++;
}

int32_t main()
{
  while (true) {
    string str;
    cin >> str;
    if (cin.eof()) break;
    if (str[0] == '+') {
      int64_t operand2 = pop();
      int64_t operand1 = pop();
      push(operand1 + operand2);
    } else if (str[0] == '-') {
      int64_t operand2 = pop();
      int64_t operand1 = pop();
      push(operand1 - operand2);
    } else if (str[0] == '*') {
      int64_t operand2 = pop();
      int64_t operand1 = pop();
      push(operand1 * operand2);
    } else {
      push(stoi(str));
    }
  }

  int64_t val = pop();
  cout << val << endl;

  return 0;
}
