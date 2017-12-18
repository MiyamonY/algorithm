///
// File:  c.cpp
// Author: ymiyamoto
//
// Created on Sun Dec  3 21:10:11 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int32_t cost(vector<vector<uint32_t>> F, vector<vector<int32_t>> P, vector<uint32_t> ret)
{
  int32_t c = 0;
  if (ret.size() > 0) {
    for (uint32_t n = 0; n < F.size(); n++) {
      uint32_t count = 0;
      for (uint32_t i = 0; i < ret.size(); i++) {
        if (F[n][ret[i]] == 1) {
          count += 1;
        }
      }
      c += P[n][count];
    }
    return c;
  } else {
    return INT32_MIN;
  }
}

int32_t comb(vector<vector<uint32_t>> F, vector<vector<int32_t>> P, int32_t i, vector<uint32_t> ret)
{
  if (i == 10) {
    return cost(F, P, ret);
  } else {
    vector<uint32_t> ret1(ret);
    ret1.push_back(i);
    return max(comb(F, P, i + 1, ret), comb(F, P, i + 1, ret1));
  }
}

int32_t main()
{
  uint32_t N;
  cin >> N;

  vector<vector<uint32_t>> F(N);
  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = 0; j < 10; j++) {
      uint32_t f;
      cin >> f;
      F[i].push_back(f);
    }
  }

  vector<vector<int32_t>> P(N);
  for (uint32_t i = 0; i < N; i++) {
    for (uint32_t j = 0; j <= 10; j++) {
      int32_t p;
      cin >> p;
      P[i].push_back(p);
    }
  }

  vector<uint32_t> ret;
  cout << comb(F, P, 0, ret) << endl;

  return 0;
}
