///
// File:  test_allocation.cpp
// Author: ymiyamoto
//
// Created on Sun Jul  2 22:59:12 2017
//

#include <cstdint>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

TestSuite(Allocation);

Test(Allocation, LoadCapacity)
{
  vector<uint32_t> loads{3, 4, 5, 7, 8, 1, 2};

  cr_assert_eq(allocation_load_capcity(loads, 8, 3), 4);
  cr_assert_eq(allocation_load_capcity(loads, 8, 4), 5);
  cr_assert_eq(allocation_load_capcity(loads, 2, 3), 0);
  cr_assert_eq(allocation_load_capcity(loads, 12, 4), 7);
  cr_assert_eq(allocation_load_capcity(loads, 9, 4), 6);
}

Test(Allocation, CalcMaxLoadCapacity)
{
  vector<uint32_t> loads{3, 4, 5, 7, 8, 1, 2};

  cr_assert_eq(allocation_max_load_capcity(loads, 6), 8);
  cr_assert_eq(allocation_max_load_capcity(loads, 5), 8);
  cr_assert_eq(allocation_max_load_capcity(loads, 4), 11);
  cr_assert_eq(allocation_max_load_capcity(loads, 2), 18);
  cr_assert_eq(allocation_max_load_capcity(loads, 1), 30);
}
