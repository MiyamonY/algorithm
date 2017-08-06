///
// File:  b.cpp
// Author: ymiyamoto
//
// Created on Wed Aug  2 01:11:30 2017
//

#include <cstdint>
#include <iostream>

using namespace std;
static pair<int64_t, int64_t> students[50];
static pair<int64_t, int64_t> points[50];

int32_t main()
{
  uint32_t N, M;

  cin >> N >> M;

  for (uint32_t i = 0; i < N; i++) {
    int64_t x, y;
    cin >> x >> y;
    students[i] = make_pair(x, y);
  }

  for (uint32_t i = 0; i < M; i++) {
    int64_t x, y;
    cin >> x >> y;
    points[i] = make_pair(x, y);
  }

  for (uint32_t i = 0; i < N; i++) {
    int64_t x = students[i].first;
    int64_t y = students[i].second;
    uint64_t m = UINT64_MAX;
    uint64_t min_point = 0;
    for (uint32_t j = 0; j < M; j++) {
      uint64_t distance = abs(x - points[j].first) + abs(y - points[j].second);
      if (distance < m) {
        m = distance;
        min_point = j;
      }
    }
    cout << min_point + 1 << endl;
  }

  return 0;
}
