///
// File:  test_insersion_sort.cpp
// Author: ymiyamoto
//
// Created on Wed Jun 28 02:15:59 2017
//

#include <cstdint>
#include <exception>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

TestSuite(InsersionSort);

Test(InsersionSort, WhenArraySizeIs1)
{
  vector<int32_t> vec{1};

  insersion_sort(&vec[0], vec.size(), nullptr);

  vector<int32_t> expect{1};
  cr_assert(vec == expect);
}

Test(InsersionSort, WhenArraySizeIsN)
{
  vector<int32_t> vec{3, 5, 4, 1, 6};

  insersion_sort(&vec[0], vec.size(), nullptr);

  vector<int32_t> expect{1, 3, 4, 5, 6};

  cr_assert(vec == expect);
}

Test(InsersionSort, WhenArrayIsNULL)
{
  cr_assert_throw(insersion_sort(nullptr, 5, nullptr), exception);
}

Test(InsersionSort, WhenArraySizeIs0)
{
  vector<int32_t> vec{3};
  cr_assert_throw(insersion_sort(&vec[0], 0, nullptr), exception);
}
