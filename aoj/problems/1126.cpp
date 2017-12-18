///
// File:  1126.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 10 00:54:34 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool bigger(string str1, string str2)
{
  if (str1.size() == str2.size()) {
    return str1 < str2;
  } else {
    return str1.size() < str2.size();
  }
}

string wfs(vector<string> matrix, vector<vector<string>> &memo, uint32_t i, uint32_t j)
{
  if (i < matrix.size() && j < matrix[0].size() && memo[i][j] != "") return memo[i][j];

  if (i >= matrix.size() || j >= matrix[0].size() || !isdigit(matrix[i][j]))
    return "";
  else {
    string s1 = wfs(matrix, memo, i + 1, j);
    string s2 = wfs(matrix, memo, i, j + 1);
    return memo[i][j] = matrix[i][j] + (bigger(s1, s2) ? s2 : s1);
  }
}

int32_t main()
{
  while (true) {
    uint32_t W, H;
    cin >> W >> H;
    if (W == 0 && H == 0) break;
    vector<string> matrix;
    for (uint32_t i = 0; i < H; i++) {
      string line;
      cin >> line;
      matrix.push_back(line);
    }

    string number = "";
    vector<vector<string>> memo(H, vector<string>(W, ""));
    for (int32_t i = matrix.size() - 1; i >= 0; i--) {
      for (int32_t j = matrix[0].size() - 1; j >= 0; j--) {
        if (matrix[i][j] == '0') continue;
        string num = wfs(matrix, memo, i, j);
        if (bigger(number, num)) {
          number = num;
        }
      }
    }
    cout << number << endl;
  }

  return 0;
}
