///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Fri Jan  5 17:44:17 2018
//

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

static vector<pair<double, double>> waters;

bool check(double mid, uint32_t K)
{
  vector<double> salts;
  for (uint32_t i = 0; i < waters.size(); i++) {
    double w = waters[i].first;
    double p = waters[i].second;
    salts.push_back(w * p / 100 - w * mid / 100);
  }
  sort(salts.begin(), salts.end());

  double diff = 0;
  for (uint32_t i = salts.size() - K; i < salts.size(); i++) {
    diff += salts[i];
  }

  return diff >= 0;
}

int32_t main()
{
  uint32_t N, K;
  cin >> N >> K;

  for (uint32_t i = 0; i < N; i++) {
    double w, p;
    cin >> w >> p;
    waters.push_back({w, p});
  }

  double ok = 0.0;
  double ng = 100.0;
  for (uint32_t i = 0; i < 100; i++) {
    double mid = (ok + ng) / 2;
    if (check(mid, K)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << fixed << setprecision(9) << ok << endl;

  return 0;
}
