///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sat Jul 29 23:30:19 2017
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>

using namespace std;

static vector<uint64_t> items0;
static vector<uint64_t> items1;
static vector<uint64_t> items2;
static vector<uint64_t> items3;

int32_t main()
{
  uint64_t N, W;
  cin >> N >> W;

  uint64_t w0, v0;
  cin >> w0 >> v0;

  items0.push_back(v0);

  for (uint64_t i = 1; i < N; i++) {
    uint64_t w, v;
    cin >> w >> v;
    switch (w - w0) {
    case 0:
      items0.push_back(v);
      break;
    case 1:
      items1.push_back(v);
      break;
    case 2:
      items2.push_back(v);
      break;
    case 3:
      items3.push_back(v);
      break;
    }
  }

  sort(items0.begin(), items0.end(), std::greater<uint64_t>());
  sort(items1.begin(), items1.end(), std::greater<uint64_t>());
  sort(items2.begin(), items2.end(), std::greater<uint64_t>());
  sort(items3.begin(), items3.end(), std::greater<uint64_t>());
  items0.insert(items0.begin(), 0);
  for (uint32_t i = 1; i < items0.size(); i++) {
    items0[i] += items0[i - 1];
  }
  items1.insert(items1.begin(), 0);
  for (uint32_t i = 1; i < items1.size(); i++) {
    items1[i] += items1[i - 1];
  }
  items2.insert(items2.begin(), 0);
  for (uint32_t i = 1; i < items2.size(); i++) {
    items2[i] += items2[i - 1];
  }
  items3.insert(items3.begin(), 0);
  for (uint32_t i = 1; i < items3.size(); i++) {
    items3[i] += items3[i - 1];
  }

  uint64_t max_values = 0;
  for (uint32_t i0 = 0; i0 < items0.size(); i0++) {
    for (uint32_t i1 = 0; i1 < items1.size(); i1++) {
      for (uint32_t i2 = 0; i2 < items2.size(); i2++) {
        for (uint32_t i3 = 0; i3 < items3.size(); i3++) {
          uint64_t values = items0[i0] + items1[i1] + items2[i2] + items3[i3];
          uint64_t weights = i0 * w0 + i1 * (w0 + 1) + i2 * (w0 + 2) + i3 * (w0 + 3);
          if (weights <= W) {
            max_values = max(max_values, values);
          }
        }
      }
    }
  }

  cout << max_values << endl;

  return 0;
}
