///
// File:  test_bubble_sort.cpp
// Author: ymiyamoto
//
// Created on Wed Jun 28 12:10:31 2017
//

#include <cstdint>
#include <stdexcept>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

TestSuite(BubbleSort);

Test(BubbleSort, ArraySizeIs1)
{
  vector<int32_t> vec{1};
  bubble_sort(&vec[0], vec.size(), nullptr);

  const vector<int32_t> expect{1};
  cr_assert(vec == expect);
}

Test(BubbleSort, ArraySizeIsN)
{
  vector<int32_t> vec{2, 3, 5, 1, 6, 4};
  bubble_sort(&vec[0], vec.size(), nullptr);

  const vector<int32_t> expect{1, 2, 3, 4, 5, 6};
  cr_assert(vec == expect);
}

Test(BubbleSort, ArrayIsNull)
{
  cr_assert_throw(bubble_sort(nullptr, 5, nullptr), exception);
}

Test(BubbleSort, ArraySizeIs0)
{
  vector<int32_t> vec{1};
  cr_assert_throw(bubble_sort(&vec[0], 0, nullptr), exception);
}
