///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Fri Dec 15 00:47:49 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

struct box_t {
  uint32_t h;
  uint32_t w;

  bool operator<(const box_t &b) const
  {
    if (h == b.h) {
      return w > b.w;
    }
    return h < b.h;
  }
};

using namespace std;

uint64_t LIS(vector<box_t> boxes)
{
  vector<uint32_t> lis;

  lis.push_back(boxes[0].w);
  for (uint32_t i = 1; i < boxes.size(); i++) {
    if (lis[lis.size() - 1] < boxes[i].w) {
      lis.push_back(boxes[i].w);
    } else {
      *lower_bound(lis.begin(), lis.end(), boxes[i].w) = boxes[i].w;
    }
  }
  return lis.size();
}

int32_t main()
{
  uint32_t N;
  cin >> N;
  vector<box_t> boxes(N);

  for (uint32_t i = 0; i < N; i++) {
    cin >> boxes[i].h >> boxes[i].w;
  }

  sort(boxes.begin(), boxes.end());

  cout << LIS(boxes) << endl;
  return 0;
}
