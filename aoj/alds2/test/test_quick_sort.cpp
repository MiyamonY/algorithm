///
// File:  test_quick_sort.cpp
// Author: ymiyamoto
//
// Created on Wed Jul  5 19:54:08 2017
//

#include <cstdint>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

TestSuite(QuickSort);

Test(QuickSort, QuickSort)
{
  vector<uint32_t> vec{
      3, 2, 21, 4, 23, 1, 21, 1, 233,
  };

  quick_sort_sort(&vec[0], 0, vec.size() - 1);

  const vector<uint32_t> expect{
      1, 1, 2, 3, 4, 21, 21, 23, 233,
  };

  cr_assert_eq(vec, expect);
}

Test(QuickSort, MergeSort)
{
  vector<uint32_t> vec{
      3, 2, 21, 4, 23, 1, 21, 1, 233,
  };

  quick_sort_merge_sort(&vec[0], 0, vec.size());

  const vector<uint32_t> expect{
      1, 1, 2, 3, 4, 21, 21, 23, 233,
  };

  cr_assert_eq(vec, expect);
}
