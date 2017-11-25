///
// File:  1346.cpp
// Author: ymiyamoto
//
// Created on Sun Nov 26 02:53:16 2017
//

#include <cstdint>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

uint32_t mult_first(string exp)
{
  stack<int32_t> stack;

  stack.push(exp[0] - '0');
  uint32_t index = 1;
  while (index < exp.size()) {
    uint32_t val = exp[index + 1] - '0';
    if (exp[index] == '+') {
      stack.push(val);
    } else {
      uint32_t val1 = stack.top();
      stack.pop();
      stack.push(val * val1);
    }
    index += 2;
  }

  uint32_t result = 0;
  while (!stack.empty()) {
    result += stack.top();
    stack.pop();
  }
  return result;
}

uint32_t left_to_right(string exp)
{
  uint32_t result = exp[0] - '0';

  uint32_t index = 1;
  while (index < exp.size()) {
    uint32_t val = exp[index + 1] - '0';
    if (exp[index] == '+') {
      result += val;
    } else {
      result *= val;
    }
    index += 2;
  }
  return result;
}

int32_t main()
{
  string exp;
  cin >> exp;

  uint32_t result1 = mult_first(exp);
  uint32_t result2 = left_to_right(exp);

  uint32_t n;
  cin >> n;
  if (result1 == n && result2 == n) {
    cout << "U" << endl;
  } else if (result1 == n) {
    cout << "M" << endl;
  } else if (result2 == n) {
    cout << "L" << endl;
  } else {
    cout << "I" << endl;
  }
  return 0;
}
