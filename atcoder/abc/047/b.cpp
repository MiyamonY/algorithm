///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Thu Sep 28 20:38:14 2017
//

#include <cstdint>
#include <iostream>

using namespace std;

struct point_t {
  int32_t x;
  int32_t y;
  point_t(int32_t _x, int32_t _y)
  {
    x = _x;
    y = _y;
  }
};

int32_t main()
{
  int32_t W, H, N;
  cin >> W >> H >> N;

  point_t upper_right(W, H);
  point_t lower_left(0, 0);

  bool all_black = false;
  for (int32_t _ = 0; _ < N; _++) {
    int32_t x, y, a;
    cin >> x >> y >> a;
    if (a == 1) {
      lower_left.x = max(lower_left.x, x);
    } else if (a == 2) {
      upper_right.x = min(upper_right.x, x);
    } else if (a == 3) {
      lower_left.y = max(lower_left.y, y);
    } else if (a == 4) {
      upper_right.y = min(upper_right.y, y);
    }
    int32_t width = upper_right.x - lower_left.x;
    int32_t height = upper_right.y - lower_left.y;
    if ((width <= 0) || (height <= 0)) {
      all_black = true;
    }
  }

  if (all_black) {
    cout << 0 << endl;
  } else {
    int32_t width = upper_right.x - lower_left.x;
    int32_t height = upper_right.y - lower_left.y;
    cout << width * height << endl;
  }

  return 0;
}
