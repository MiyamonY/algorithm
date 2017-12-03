///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sun Dec  3 21:29:12 2017
//

#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

array<int32_t, 200010> cs;

int32_t main()
{
  uint32_t N, C;
  cin >> N >> C;

  vector<vector<pair<uint32_t, uint32_t>>> channels(C + 1);
  for (uint32_t i = 0; i < N; i++) {
    uint32_t s, t, c;
    cin >> s >> t >> c;
    channels[c].push_back({2 * s, 2 * t});
  }

  for (uint32_t i = 0; i < channels.size(); i++) {
    sort(channels[i].begin(), channels[i].end());
  }

  for (uint32_t i = 0; i < channels.size(); i++) {
    for (uint32_t j = 0; j < channels[i].size(); j++) {
      cs[channels[i][j].first - 1]++;
      while (j + 1 < channels[i].size() && channels[i][j].second == channels[i][j + 1].first) {
        j++;
      }
      cs[channels[i][j].second]--;
    }
  }

  int32_t maxval = 0;
  for (uint32_t i = 0; i < cs.size() - 1; i++) {
    cs[i + 1] += cs[i];
    maxval = max(maxval, cs[i + 1]);
  }

  cout << maxval << endl;
  return 0;
}
