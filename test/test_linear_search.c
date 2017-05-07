/**
 * File:  test_linear_search.c
 * Author: ymiyamoto
 *
 * Created on Fri May  5 12:00:03 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

TestSuite(linear_search);

Test(linear_search, FindDataIsNone)
{
  int32_t data[] = {1, 2, 3};
  int32_t find[] = {0};

  size_t n = linear_search_find(data, UTIL_ARRAY_SIZE(data), find, 0);
  cr_assert_eq(n, 0);
}

Test(linear_search, DataIsNull)
{
  int32_t find[] = {0};
  size_t n = linear_search_find(NULL, 3, find, UTIL_ARRAY_SIZE(find));
  cr_assert_eq(n, 0);
}

Test(linear_search, FindIsNull)
{
  int32_t data[] = {1, 2, 3};
  size_t n = linear_search_find(data, UTIL_ARRAY_SIZE(data), NULL, 3);
  cr_assert_eq(n, 0);
}

Test(linear_search, DataSizeIs0)
{
  int32_t data[] = {1, 2, 3};
  int32_t find[] = {1, 2};
  size_t n = linear_search_find(data, 0, find, UTIL_ARRAY_SIZE(find));
  cr_assert_eq(n, 0);
}

Test(linear_search, FindSizeIs0)
{
  int32_t data[] = {1, 2, 3};
  int32_t find[] = {1, 2};
  size_t n = linear_search_find(data, UTIL_ARRAY_SIZE(data), find, 0);
  cr_assert_eq(n, 0);
}

Test(linear_search, LinearSearchFound1)
{
  int32_t data[] = {1};
  int32_t find[] = {1};
  size_t n = linear_search_find(data, UTIL_ARRAY_SIZE(data), find, UTIL_ARRAY_SIZE(find));
  cr_assert_eq(n, 1);
}

Test(linear_search, LinearSearchFoundDataSizeIs2)
{
  int32_t data[] = {1, 2};
  int32_t find[] = {2};
  size_t n = linear_search_find(data, UTIL_ARRAY_SIZE(data), find, UTIL_ARRAY_SIZE(find));
  cr_assert_eq(n, 1);
}

Test(linear_search, LinearSearchFoundSizeIs2)
{
  int32_t data[] = {1, 2};
  int32_t find[] = {1, 2};
  size_t n = linear_search_find(data, UTIL_ARRAY_SIZE(data), find, UTIL_ARRAY_SIZE(find));
  cr_assert_eq(n, 2);
}
