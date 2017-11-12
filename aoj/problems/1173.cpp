///
// File:  1173.cpp
// Author: ymiyamoto
//
// Created on Sun Nov 12 17:50:22 2017
//

#include <cstdint>
#include <iostream>
#include <istream>
#include <stack>

using namespace std;

int32_t main()
{
  while (true) {
    string str;
    getline(cin, str);
    if (str[0] == '.') break;

    stack<char> s;
    for (uint32_t i = 0; i < str.size(); i++) {
      if (str[i] == '(') {
        s.push('(');
      } else if (str[i] == ')') {
        if (!s.empty() && s.top() == '(') {
          s.pop();
        } else {
          s.push('*');
          break;
        }
      } else if (str[i] == '[') {
        s.push('[');
      } else if (str[i] == ']') {
        if (!s.empty() && s.top() == '[') {
          s.pop();
        } else {
          s.push('*');
          break;
        }
      }
    }

    if (s.empty()) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }

  return 0;
}
