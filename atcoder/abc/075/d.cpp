///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sat Oct 14 21:55:52 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static vector<pair<int64_t, int64_t>> points;
static vector<int64_t> xs;
static vector<int64_t> ys;

int32_t main()
{
  uint32_t N, K;
  cin >> N >> K;

  for (uint32_t i = 0; i < N; i++) {
    int64_t x, y;
    cin >> x >> y;
    points.push_back({x, y});
    xs.push_back(x);
    ys.push_back(y);
  }

  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());

  int64_t area = INT64_MAX;

  for (int32_t i = 0; i < (int32_t)xs.size(); i++) {
    for (int32_t j = 0; j < (int32_t)ys.size(); j++) {
      for (int32_t k = xs.size() - 1; k >= i; k--) {
        for (int32_t l = ys.size() - 1; l >= j; l--) {
          uint32_t count = 0;
          for (uint32_t m = 0; m < points.size(); m++) {
            if (xs[i] <= points[m].first && points[m].first <= xs[k] && ys[j] <= points[m].second && points[m].second <= ys[l]) {
              count++;
            }
          }
          if (count >= K) {
            area = min(area, abs(xs[i] - xs[k]) * abs(ys[j] - ys[l]));
          }
        }
      }
    }
  }

  cout << area << endl;
  return 0;
}
