///
// File:  koch_curve.cpp
// Author: ymiyamoto
//
// Created on Tue Jul  4 21:55:15 2017
//

#include <cmath>
#include <cstdint>
#include <math.h>
#include <vector>

using namespace std;

void koch_curve(vector<pair<double, double>> &vec, uint32_t num)
{
  if (num == 0) {
  } else {
    vector<pair<double, double>> v;
    for (uint32_t i = 0; i < vec.size() - 1; i++) {
      pair<double, double> left = vec[i];
      pair<double, double> right = vec[i + 1];
      pair<double, double> s;
      pair<double, double> t;
      pair<double, double> u;
      s.first = (2 * left.first + 1 * right.first) / 3;
      s.second = (2 * left.second + 1 * right.second) / 3;
      t.first = (1 * left.first + 2 * right.first) / 3;
      t.second = (1 * left.second + 2 * right.second) / 3;
      u.first = (t.first - s.first) * cos(M_PI / 3.0) - (t.second - s.second) * sin(M_PI / 3.0) + s.first;
      u.second = (t.first - s.first) * sin(M_PI / 3.0) + (t.second - s.second) * cos(M_PI / 3.0) + s.second;
      v.push_back(left);
      v.push_back(s);
      v.push_back(u);
      v.push_back(t);
    }
    v.push_back(vec[vec.size() - 1]);

    vec.clear();
    for (uint32_t i = 0; i < v.size(); i++) {
      vec.push_back(v[i]);
    }

    koch_curve(vec, num - 1);
  }
}

#if !defined(TEST)
#include <cstdio>

int32_t main()
{
  int32_t num;
  scanf("%d", &num);

  vector<pair<double, double>> vec{{0.0, 0.0}, {100.0, 0.0}};
  koch_curve(vec, num);
  for (uint32_t i = 0; i < vec.size(); i++) {
    printf("%.8f %.8f\n", vec[i].first, vec[i].second);
  }

  return 0;
}
#endif
