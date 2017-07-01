///
// File:  test_binary_search.cpp
// Author: ymiyamoto
//
// Created on Sat Jul  1 21:59:27 2017
//

#include <cstdint>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

TestSuite(BinarySearch);

Test(BinarySearch, SearchFound)
{
  vector<uint32_t> array{1, 5, 6, 7, 8, 9, 12, 15, 16};

  cr_assert(binary_search(&array[0], array.size(), 5));
  cr_assert(binary_search(&array[0], array.size(), 16));
}

Test(BinarySearch, NotFound)
{
  vector<uint32_t> array{1, 5, 6, 7, 8, 9, 12, 15, 16};

  cr_assert_not(binary_search(&array[0], array.size(), 2));
  cr_assert_not(binary_search(&array[0], array.size(), 18));
  cr_assert_not(binary_search(&array[0], array.size(), 0));
}
