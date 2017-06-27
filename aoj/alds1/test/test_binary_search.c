/**
 * File:  test_binary_search.c
 * Author: ymiyamoto
 *
 * Created on Sun May  7 16:43:05 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

TestSuite(BinarySearch);

Test(BinarySearch, DataArraySizeIs0)
{
  int32_t data[] = {1, 2, 3, 4};
  int32_t find[] = {1, 2};

  size_t n = binary_search_find(data, 0, find, UTIL_ARRAY_SIZE(find));
  cr_assert_eq(n, 0);
}

Test(BinarySearch, FindArraySizeIs0)
{
  int32_t data[] = {1, 2, 3, 4};
  int32_t find[] = {1, 2};

  size_t n = binary_search_find(data, UTIL_ARRAY_SIZE(data), find, 0);
  cr_assert_eq(n, 0);
}

Test(BinarySearch, DataArraySizeIsNULL)
{
  int32_t find[] = {1, 2};

  size_t n = binary_search_find(NULL, 3, find, UTIL_ARRAY_SIZE(find));
  cr_assert_eq(n, 0);
}

Test(BinarySearch, FindArraySizeIsNULL)
{
  int32_t data[] = {1, 2, 3, 4};

  size_t n = binary_search_find(data, UTIL_ARRAY_SIZE(data), NULL, 3);
  cr_assert_eq(n, 0);
}

Test(BinarySearch, NotFound)
{
  int32_t data[] = {1, 2, 3, 4, 5};
  int32_t found[] = {0};

  size_t n = binary_search_find(data, UTIL_ARRAY_SIZE(data), found, UTIL_ARRAY_SIZE(found));
  cr_assert_eq(n, 0);
}

Test(BinarySearch, FoundOneWhenDataSizeIs1)
{
  int32_t data[] = {1};
  int32_t found[] = {1};

  size_t n = binary_search_find(data, UTIL_ARRAY_SIZE(data), found, UTIL_ARRAY_SIZE(found));
  cr_assert_eq(n, 1);
}

Test(BinarySearch, FoundOneEven)
{
  int32_t data[] = {1, 2, 3, 4};
  int32_t found[] = {0};

  for (int32_t i = 0; i < UTIL_ARRAY_SIZE(data); i++) {
    found[0] = data[i];
    size_t n = binary_search_find(data, UTIL_ARRAY_SIZE(data), found, UTIL_ARRAY_SIZE(found));
    cr_assert_eq(n, 1);
  }
}

Test(BinarySearch, FoundOneOdd)
{
  int32_t data[] = {1, 2, 3, 4, 5};
  int32_t found[] = {0};

  for (int32_t i = 0; i < UTIL_ARRAY_SIZE(data); i++) {
    found[0] = data[i];
    size_t n = binary_search_find(data, UTIL_ARRAY_SIZE(data), found, UTIL_ARRAY_SIZE(found));
    cr_assert_eq(n, 1);
  }
}

Test(BinarySearch, Founds)
{
  int32_t data[] = {1, 2, 3, 4, 5};
  int32_t found[] = {2, 3, 4};

  size_t n = binary_search_find(data, UTIL_ARRAY_SIZE(data), found, UTIL_ARRAY_SIZE(found));
  cr_assert_eq(n, 3, "found %d\n", n);
}

Test(BinarySearch, HasSameValueOdd)
{
  int32_t data[] = {1, 2, 3, 3, 3, 4, 5};
  int32_t found[] = {3};

  size_t n = binary_search_find(data, UTIL_ARRAY_SIZE(data), found, UTIL_ARRAY_SIZE(found));
  cr_assert_eq(n, 1);
}

Test(BinarySearch, HasSameValueEven)
{
  int32_t data[] = {1, 2, 3, 3, 3, 4, 5, 5};
  int32_t found[] = {8, 4, 5, 0};

  size_t n = binary_search_find(data, UTIL_ARRAY_SIZE(data), found, UTIL_ARRAY_SIZE(found));
  cr_assert_eq(n, 2);
}
