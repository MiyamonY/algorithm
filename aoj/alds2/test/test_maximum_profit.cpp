///
// File:  test_maximum_profit.cpp
// Author: ymiyamoto
//
// Created on Wed Jun 28 01:40:32 2017
//

#include <criterion/criterion.h>
#include <cstdint>
#include <vector>

#include "problems.hpp"

using namespace std;

TestSuite(MaximumProfit);

Test(MaximumProfit, RandomValue)
{
  vector<int32_t> vec{7, 4, 1, 5, 6, 1, 3};
  cr_assert_eq(maximum_profit(vec), 5);
}

Test(MaximumProfit, Decreasing)
{
  vector<int32_t> vec{5, 4, 3, 2};
  cr_assert_eq(maximum_profit(vec), -1);
}
