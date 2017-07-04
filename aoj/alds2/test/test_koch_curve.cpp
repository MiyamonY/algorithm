///
// File:  test_koch_curve.cpp
// Author: ymiyamoto
//
// Created on Mon Jul  3 23:22:07 2017
//

#include <cstdint>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

TestSuite(KochCurve);

Test(KochCurve, Koch0)
{
  vector<pair<double, double>> vec{{0.0, 0.0}, {100.0, 0.0}};
  koch_curve(vec, 0);

  const vector<pair<double, double>> expect{{0.0, 0.0}, {100.0, 0.0}};
  cr_assert_eq(vec, expect);
}

Test(KochCurve, Koch1)
{
  vector<pair<double, double>> vec{{0.0, 0.0}, {100.0, 0.0}};
  koch_curve(vec, 1);

  const vector<pair<double, double>> expect{
      {0.0, 0.0}, {33.3333, 0.0}, {50.00, 28.86751346}, {66.666667, 0.0}, {100.0, 0.0},
  };

  for (uint32_t i = 0; i < expect.size(); i++) {
    cr_assert_float_eq(vec[i].first, expect[i].first, 0.1, "%f, %f", vec[i].first, expect[i].first);
    cr_assert_float_eq(vec[i].second, expect[i].second, 0.1, "%f, %f", vec[i].second, expect[i].second);
  }
}
