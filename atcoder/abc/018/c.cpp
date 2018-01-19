///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Thu Jan 18 23:24:26 2018
//
#include <bits/stdc++.h>
using namespace std;

#define rep(_n, _init, _N) for (int32_t _n = _init; _n < (int32_t)(_N); _n++)
#define rrep(_n, _N, _end) for (int32_t _n = (int32_t)(_N); _n >= _end; _n--)
#define iceil(_x, _y) (((_x) + (_y)-1) / (_y))
#define ifloor(_x, _y) ((_x) / (_y))

static const double pi = 2 * asin(1);
static const double precision = 10e-9;

int32_t main()
{
  int32_t R, C, K;
  cin >> R >> C >> K;

  vector<string> board(R);
  rep(i, 0, R)
  {
    cin >> board[i];
  }

  vector<vector<pair<int32_t, int32_t>>> white_nums(R, vector<pair<int32_t, int32_t>>(C));
  rep(i, 0, R)
  {
    rep(j, 0, C)
    {
      int32_t upper = 0, lower = 0;
      if (board[i][j] == 'o') {
        int32_t x = i;
        while (x >= 0 && board[x][j] == 'o') {
          upper++;
          x--;
        }
        x = i;
        while (x < R && board[x][j] == 'o') {
          lower++;
          x++;
        }
      }
      white_nums[i][j] = {upper, lower};
    }
  }

  uint32_t count = 0;
  rep(i, 0, R)
  {
    rep(j, 0, C)
    {
      bool has_black = false;
      rrep(k, K, 1)
      {
        uint32_t upper = white_nums[i][j - k + K].first;
        uint32_t lower = white_nums[i][j - k + K].second;
        if (upper < k || lower < k) {
          has_black = true;
        }
        upper = white_nums[i][j + k - K].first;
        lower = white_nums[i][j + k - K].second;
        if (upper < k || lower < k) {
          has_black = true;
        }
      }
      if (!has_black) {
        count++;
      }
    }
  }

  cout << count << endl;
  return 0;
}
