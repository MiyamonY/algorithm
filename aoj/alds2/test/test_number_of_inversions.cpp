///
// File:  test_number_of_inversion.cpp
// Author: ymiyamoto
//
// Created on Thu Jul  6 23:25:36 2017
//

#include <cstdint>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

TestSuite(NumberOfInversion);

Test(NumberOfInversion, InversionNumber1)
{
  vector<uint32_t> vec{3, 5, 2, 1, 4};

  size_t num = number_of_inversion(&vec[0], vec.size());
  cr_assert_eq(num, 6, "%d", num);
}

Test(NumberOfInversion, InversionNumber2)
{
  vector<uint32_t> vec{3, 5, 8, 2, 1, 4, 10, 6};

  cr_assert_eq(number_of_inversion(&vec[0], vec.size()), 11);
}
