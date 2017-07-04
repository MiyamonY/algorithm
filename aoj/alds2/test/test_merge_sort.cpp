///
// File:  test_merge_sort.cpp
// Author: ymiyamoto
//
// Created on Tue Jul  4 22:38:17 2017
//

#include <cstdint>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

TestSuite(MergeSort);

Test(MergeSort, merge)
{
  vector<uint32_t> vec{5, 3, 1, 9, 10, 2, 34};

  merge_sort_merge(&vec[0], vec.size());
  vector<uint32_t> expect{1, 2, 3, 5, 9, 10, 34};

  cr_assert_eq(vec, expect);
}

Test(MergeSort, MergeSameValue)
{
  vector<uint32_t> vec{5, 3, 1, 9, 1, 10, 2, 2, 34};

  merge_sort_merge(&vec[0], vec.size());
  vector<uint32_t> expect{1, 1, 2, 2, 3, 5, 9, 10, 34};

  cr_assert_eq(vec, expect);
}
