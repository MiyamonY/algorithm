///
// File:  2300.cpp
// Author: ymiyamoto
//
// Created on Wed Nov 22 00:34:02 2017
//

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

double distance(vector<tuple<double, double, double>> selected)
{
  double dist = 0.0;
  for (uint32_t i = 0; i < selected.size(); i++) {
    for (uint32_t j = i; j < selected.size(); j++) {
      dist += pow(get<0>(selected[i]) - get<0>(selected[j]), 2);
      dist += pow(get<1>(selected[i]) - get<1>(selected[j]), 2);
      dist += pow(get<2>(selected[i]) - get<2>(selected[j]), 2);
    }
  }
  return dist;
}

double comb(vector<tuple<double, double, double>> &colors, uint32_t index, uint32_t M, vector<tuple<double, double, double>> selected)
{
  if (selected.size() == M) {
    return distance(selected);
  } else if (colors.size() <= index) {
    return 0.0;
  } else {
    vector<tuple<double, double, double>> vec(selected);
    vec.push_back(colors[index]);
    return max(comb(colors, index + 1, M, selected), comb(colors, index + 1, M, vec));
  }
}

int32_t main()
{
  uint32_t N, M;
  cin >> N >> M;

  vector<tuple<double, double, double>> colors;
  for (uint32_t i = 0; i < N; i++) {
    double L, a, b;
    cin >> L >> a >> b;

    colors.push_back(make_tuple(L, a, b));
  }

  vector<tuple<double, double, double>> selected;
  double dist = comb(colors, 0, M, selected);

  cout << fixed << setprecision(8) << dist << endl;

  return 0;
}
