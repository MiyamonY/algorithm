///
// File:  1148.cpp
// Author: ymiyamoto
//
// Created on Fri Nov 17 00:20:41 2017
//

#include <cstdint>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int32_t main()
{
  while (true) {
    uint32_t N, M;
    cin >> N >> M;
    if (N == 0 && M == 0) break;

    vector<stack<uint32_t>> stacks(M + 1);
    vector<vector<pair<uint32_t, uint32_t>>> used(M + 1);
    uint32_t r;
    cin >> r;
    for (uint32_t _ = 0; _ < r; _++) {
      uint32_t t, n, m, s;
      cin >> t >> n >> m >> s;
      if (s == 0) {
        if (stacks[m].empty()) {
          cerr << t << n << m << s;
          exit(1);
        }
        uint32_t start_time = stacks[m].top();
        stacks[m].pop();
        if (stacks[m].empty()) {
          used[m].push_back({start_time, t});
        }
      } else {
        stacks[m].push(t);
      }
    }

    uint32_t q;
    cin >> q;
    for (uint32_t _ = 0; _ < q; _++) {
      uint32_t s, e, m;
      cin >> s >> e >> m;
      uint32_t count = 0;
      for (auto iter = used[m].begin(); iter < used[m].end(); iter++) {
        uint32_t start = iter->first;
        uint32_t end = iter->second;
        if (start < s && e < end) {
          count += e - s;
        } else if (start < s && s < end && end < e) {
          count += end - s;
        } else if (s < start && start < e && e < end) {
          count += e - start;
        } else if (s <= start && end <= e) {
          count += end - start;
        }
      }
      cout << count << endl;
    }
  }
  return 0;
}
