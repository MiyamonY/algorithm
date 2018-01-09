///
// File:  1602.cpp
// Author: ymiyamoto
//
// Created on Wed Dec 20 00:50:10 2017
//

#include <cstdint>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string calc(vector<string> values, string op)
{
  uint32_t val;
  if (op == "+") {
    val = 0;
  } else {
    val = 1;
  }

  for (auto s : values) {
    int32_t i = stoi(s);
    if (op == "+") {
      val += i;
    } else {
      val *= i;
    }
  }

  return to_string(val);
}

void conv(stack<pair<uint32_t, string>> &s, uint32_t depth)
{
  while (s.top().first > depth) {
    vector<string> values;
    uint32_t d = s.top().first;
    while (true) {
      pair<uint32_t, string> t = s.top();
      s.pop();
      if (t.first < d) {
        s.push({t.first, calc(values, t.second)});
        break;
      } else {
        values.push_back(t.second);
      }
    }
  }
}

int32_t main()
{
  while (true) {
    int32_t n;
    cin >> n;
    if (n == 0) break;

    stack<pair<uint32_t, string>> s;
    uint32_t depth = 0;
    for (int32_t i = 0; i < n; i++) {
      string str;
      cin >> str;
      uint32_t d = str.size() - 1;

      if (depth > d) {
        conv(s, d);
      }
      s.push({d, string{str[str.size() - 1]}});
      depth = d;
    }
    conv(s, 0);

    cout << s.top().second << endl;
  }

  return 0;
}
