/**
 * File:  test_merge_sort.c
 * Author: ymiyamoto
 *
 * Created on Sat May 13 17:38:35 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include <criterion/criterion.h>

#include "problems.h"

#include "util.h"

TestSuite(MergeSort);

Test(MergeSort, ArraySizeIs0)
{
  int64_t data[] = {1, 2, 3};
  size_t ret = merge_sort(data, 0);
  cr_assert_eq(ret, 0);
}

Test(TestMergeSort, ArrayIsNull)
{
  size_t ret = merge_sort(NULL, 0);
  cr_assert_eq(ret, 0);
}

Test(TestMergeSort, ArraySizeIs1)
{
  int64_t data[] = {1};
  size_t ret = merge_sort(data, UTIL_ARRAY_SIZE(data));
  cr_assert_eq(ret, 0);
}

Test(TestMergeSort, ArraySizeIs2Sorted)
{
  int64_t data[] = {1, 2};
  size_t ret = merge_sort(data, UTIL_ARRAY_SIZE(data));
  cr_assert_eq(ret, 2, "actual %d, expect %d", ret, 1);

  int64_t expected[] = {1, 2};
  cr_assert_arr_eq(data, expected, sizeof(expected));
}

Test(TestMergeSort, ArraySizeIs2)
{
  int64_t data[] = {2, 1};
  size_t ret = merge_sort(data, UTIL_ARRAY_SIZE(data));
  cr_assert_eq(ret, 2, "actual %d, expect %d", ret, 1);

  int64_t expected[] = {1, 2};
  cr_assert_arr_eq(data, expected, sizeof(expected));
}

Test(TestMergeSort, ArraySizeIsEven)
{
  int64_t data[] = {3, 2, 4, 1};
  size_t ret = merge_sort(data, UTIL_ARRAY_SIZE(data));
  cr_assert_eq(ret, 8, "actual %d, expect %d", ret, 5);

  int64_t expected[] = {1, 2, 3, 4};
  cr_assert_arr_eq(data, expected, sizeof(expected));
}

Test(TestMergeSort, ArraySizeIsOdd)
{
  int64_t data[] = {5, 3, 2, 4, 1};
  size_t ret = merge_sort(data, UTIL_ARRAY_SIZE(data));
  cr_assert_eq(ret, 12, "actual %d, expect %d", ret, 8);

  int64_t expected[] = {1, 2, 3, 4, 5};
  cr_assert_arr_eq(data, expected, sizeof(expected));
}

Test(TestMergeSort, Random)
{
  int64_t data[] = {8, 5, 9, 2, 6, 3, 7, 1, 10, 4};
  size_t ret = merge_sort(data, UTIL_ARRAY_SIZE(data));
  cr_assert_eq(ret, 34, "actual %d, expect %d", ret, 34);

  int64_t expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  cr_assert_arr_eq(data, expected, sizeof(expected));
}
