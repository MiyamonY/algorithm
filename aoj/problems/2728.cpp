///
// File:  2728.cpp
// Author: ymiyamoto
//
// Created on Thu Dec 28 20:03:55 2017
//

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int64_t diff(string A, string B)
{
  return min(abs(stol(A) - stol(B)), (int64_t)pow(10, A.size()) - abs(stol(A) - stol(B)));
}

bool comp(pair<int64_t, string> x, pair<int64_t, string> y)
{
  if (x.first == y.first) {
    return x.second > y.second;
  }
  return x.first < y.first;
}

pair<int64_t, string> min_str(string A, vector<bool> used, string B)
{
  if (A.size() == B.size()) {
    return {diff(A, B), B};
  } else {
    vector<pair<int64_t, string>> strs;
    for (uint32_t i = 0; i < used.size(); i++) {
      if (!used[i]) {
        used[i] = true;
        string b = string(B);
        b += i + '0';
        strs.push_back(min_str(A, used, b));
        used[i] = false;
      }
    }
    sort(strs.begin(), strs.end(), comp);
    if (strs.size() > 0) {
      return strs[strs.size() - 1];
    } else {
      return {-1, ""};
    }
  }
}

int32_t main()
{
  string A;
  cin >> A;

  vector<bool> used(10, false);
  cout << min_str(A, used, "").second << endl;

  return 0;
}
