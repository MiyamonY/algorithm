///
// File:  2311.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 10 17:01:13 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct pos_t {
  int32_t x;
  int32_t y;
};

bool in_range(int32_t x, int32_t y)
{
  return 0 <= x && x < 8 && 0 <= y && y < 8;
}

void turnover(vector<string> &matrix, vector<pos_t> poss, char my)
{
  for (auto pos : poss) {
    matrix[pos.x][pos.y] = my;
  }
}

vector<pos_t> search(vector<string> &matrix, pos_t start, int32_t dx, int32_t dy, char my, char op)
{
  int32_t k = 1;
  vector<pos_t> poss;
  int32_t x = start.x;
  int32_t y = start.y;
  while (in_range(x + k * dx, y + k * dy) && matrix[x + k * dx][y + k * dy] == op) {
    poss.push_back({x + k * dx, y + k * dy});
    k++;
  }
  if (!poss.empty() && in_range(x + k * dx, y + k * dy) && matrix[x + k * dx][y + k * dy] == my) {
    return poss;
  }

  poss.clear();
  return poss;
}

vector<pos_t> turn(vector<string> &matrix, pos_t start, char my, char op)
{
  vector<pos_t> poss;
  for (int32_t dx = -1; dx <= 1; dx++) {
    for (int32_t dy = -1; dy <= 1; dy++) {
      if (!(dx == 0 && dy == 0)) {
        vector<pos_t> pos = search(matrix, start, dx, dy, my, op);
        poss.insert(poss.end(), pos.begin(), pos.end());
      }
    }
  }
  return poss;
}

int32_t main()
{
  vector<string> matrix(8);
  for (uint32_t i = 0; i < matrix.size(); i++) {
    cin >> matrix[i];
  }

  while (true) {
    bool first = false;
    bool second = false;

    uint32_t maxnum = 1;
    vector<pos_t> maxval;
    for (int32_t i = 0; i < 8; i++) {
      for (int32_t j = 0; j < 8; j++) {
        if (matrix[i][j] == '.') {
          pos_t start{i, j};
          vector<pos_t> poss = turn(matrix, start, 'o', 'x');
          poss.push_back(start);
          if (maxnum < poss.size()) {
            maxnum = poss.size();
            maxval = poss;
            first = true;
          }
        }
      }
    }
    turnover(matrix, maxval, 'o');

    maxnum = 1;
    vector<pos_t> opval;
    for (int32_t i = 7; i >= 0; i--) {
      for (int32_t j = 7; j >= 0; j--) {
        if (matrix[i][j] == '.') {
          pos_t start{i, j};
          vector<pos_t> poss = turn(matrix, start, 'x', 'o');
          poss.push_back(start);
          if (maxnum < poss.size()) {
            maxnum = poss.size();
            opval = poss;
            second = true;
          }
        }
      }
    }
    turnover(matrix, opval, 'x');

    if (first == false && second == false) break;
  }

  for (auto m : matrix) {
    cout << m << endl;
  }

  return 0;
}
