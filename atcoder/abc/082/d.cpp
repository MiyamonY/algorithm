///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sun Dec 17 22:47:43 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int32_t main()
{
  string str;
  cin >> str;

  int32_t X, Y;
  cin >> X >> Y;

  vector<int32_t> xnums;
  vector<int32_t> ynums;
  int32_t fnum = 0;
  bool isx = true;
  for (auto s : str) {
    if (s == 'F') {
      fnum++;
    } else {
      if (isx) {
        xnums.push_back(fnum);
        isx = false;
      } else {
        ynums.push_back(fnum);
        isx = true;
      }
      fnum = 0;
    }
  }
  if (isx) {
    xnums.push_back(fnum);
  } else {
    ynums.push_back(fnum);
  }

  vector<vector<bool>> dpx(xnums.size(), vector<bool>(16001, false));
  dpx[0][8000 + xnums[0]] = true;
  for (uint32_t i = 1; i < xnums.size(); i++) {
    for (int32_t x = 0; x < 16001; x++) {
      bool left = false;
      if (0 <= x - xnums[i]) {
        left = dpx[i - 1][x - xnums[i]];
      }
      bool right = false;
      if (x + xnums[i] < 16001) {
        right = dpx[i - 1][x + xnums[i]];
      }
      dpx[i][x] = left || right;
    }
  }

  vector<vector<bool>> dpy(ynums.size(), vector<bool>(16001, false));
  if (ynums.size() > 0) {
    dpy[0][8000 - ynums[0]] = true;
    dpy[0][8000 + ynums[0]] = true;
    for (uint32_t i = 1; i < ynums.size(); i++) {
      for (int32_t y = 0; y < 16001; y++) {
        bool left = false;
        if (0 <= y - ynums[i]) {
          left = dpy[i - 1][y - ynums[i]];
        }
        bool right = false;
        if (y + ynums[i] < 16001) {
          right = dpy[i - 1][y + ynums[i]];
        }
        dpy[i][y] = left || right;
      }
    }
  }

  if (dpx[dpx.size() - 1][X + 8000]) {
    if (ynums.size() == 0 || (ynums.size() > 0 && dpy[dpy.size() - 1][Y + 8000])) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}
