///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sun Jan  7 21:59:59 2018
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
  int64_t N, H;
  cin >> N >> H;

  vector<int64_t> bs;
  int64_t max_a = 0;
  for (uint32_t i = 0; i < N; i++) {
    int64_t a, b;
    cin >> a >> b;
    bs.push_back(b);
    max_a = max(max_a, a);
  }

  sort(bs.begin(), bs.end(), greater<int64_t>());
  uint32_t count = 0;
  for (uint32_t i = 0; i < bs.size(); i++) {
    if (bs[i] > max_a) {
      H -= bs[i];
      count++;
      if (H <= 0) {
        cout << count << endl;
        return 0;
      }
    }
  }

  count += H / max_a;
  if ((H % max_a) != 0) {
    count++;
  }

  cout << count << endl;
  return 0;
}
