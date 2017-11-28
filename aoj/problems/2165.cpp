///
// File:  2165.cpp
// Author: ymiyamoto
//
// Created on Tue Nov 28 22:51:14 2017
//

#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define EPS 1e-9
#define M 256

uint32_t R(uint32_t i, uint32_t S, uint32_t A, uint32_t C)
{
  if (i == 0)
    return S;
  else
    return (A * R(i - 1, S, A, C) + C) % M;
}

double H(vector<uint32_t> O)
{
  double h = 0.0;
  uint32_t N = O.size();
  map<uint32_t, uint32_t> nums;
  for (uint32_t i = 0; i < O.size(); i++) {
    if (nums.count(O[i]) == 0) {
      nums[O[i]] = 1;
    } else {
      nums[O[i]] += 1;
    }
  }

  for (auto iter = nums.begin(); iter != nums.end(); iter++) {
    h += (double)iter->second * log((double)iter->second / (double)N);
  }

  return -h;
}

int32_t main()
{
  while (true) {
    uint32_t N;
    cin >> N;
    if (N == 0) break;

    vector<uint32_t> I(N + 1, 0);
    for (uint32_t i = 1; i <= N; i++) {
      cin >> I[i];
    }

    double min_O = 1e6;
    uint32_t max_S, max_A, max_C;
    for (uint32_t S = 0; S <= 15; S++) {
      for (uint32_t A = 0; A <= 15; A++) {
        for (uint32_t C = 0; C <= 15; C++) {
          vector<uint32_t> O;
          for (uint32_t i = 1; i <= N; i++) {
            O.push_back((I[i] + R(i, S, A, C)) % M);
          }
          double o = H(O);
          if (o + EPS < min_O) {
            min_O = o;
            max_S = S;
            max_A = A;
            max_C = C;
          }
        }
      }
    }
    cout << max_S << " " << max_A << " " << max_C << endl;
  }

  return 0;
}
