/**
 * File:  test_selection_sort.c
 * Author: ymiyamoto
 *
 * Created on Wed Jun 28 13:00:32 2017
 */

#include <stdbool.h>
#include <stdexcept>
#include <stdint.h>
#include <utility>

#include "problems.hpp"

#include <criterion/criterion.h>

using namespace std;

TestSuite(SelectionSort);

Test(SelectionSort, ArraySizeIs1)
{
  vector<int32_t> vec{1};
  selection_sort(&vec[0], vec.size(), nullptr);

  const vector<int32_t> expect{1};
  cr_assert_eq(vec, expect);
}

Test(SelectionSort, ArraySizeIsN)
{
  vector<int32_t> vec{5, 3, 1, 4, 6, 2};
  selection_sort(&vec[0], vec.size(), nullptr);

  const vector<int32_t> expect{1, 2, 3, 4, 5, 6};
  cr_assert_eq(vec, expect);
}

Test(SelectionSort, ArraySizeIs0)
{
  vector<int32_t> vec{5};
  cr_assert_throw(selection_sort(&vec[0], 0, nullptr), exception);
}

Test(SelectionSort, ArrayIsNull)
{
  cr_assert_throw(selection_sort(nullptr, 5, nullptr), exception);
}
