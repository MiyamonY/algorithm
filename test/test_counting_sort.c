/**
 * File:  test_counting_sort.c
 * Author: ymiyamoto
 *
 * Created on Sun May 21 07:02:21 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

counting_sort_t c;

static void setup(void)
{
  c = counting_sort_create(64);
}

static void teardown(void)
{
  counting_sort_destroy(c);
}

TestSuite(CountingSort, .init = setup, .fini = teardown);

Test(CountingSort, SortArrayWhoseSize1)
{
  uint64_t arr[] = {34};
  const uint64_t expect[] = {34};

  counting_sort(c, arr, UTIL_ARRAY_SIZE(arr));
  cr_assert_arr_eq(arr, expect, UTIL_ARRAY_SIZE(expect));
}

Test(CountingSort, SortArrayWhoseSize2)
{
  uint64_t arr[] = {2, 1};
  const uint64_t expect[] = {1, 2};

  counting_sort(c, arr, UTIL_ARRAY_SIZE(arr));
  cr_assert_arr_eq(arr, expect, UTIL_ARRAY_SIZE(expect));
}

Test(CountingSort, SortArrayWhoseSizeN)
{
  uint64_t arr[] = {34, 32, 3, 2, 5, 0};
  const uint64_t expect[] = {0, 2, 3, 5, 32, 34};

  counting_sort(c, arr, UTIL_ARRAY_SIZE(arr));
  cr_assert_arr_eq(arr, expect, UTIL_ARRAY_SIZE(expect));
}

Test(CountingSort, SortArrayWhichHasSameValue)
{
  uint64_t arr[] = {34, 32, 3, 2, 5, 0, 32};
  const uint64_t expect[] = {0, 2, 3, 5, 32, 32, 34};

  counting_sort(c, arr, UTIL_ARRAY_SIZE(arr));
  cr_assert_arr_eq(arr, expect, UTIL_ARRAY_SIZE(expect));
}

Test(CountingSort, ArraySizeIs0)
{
  uint64_t arr[] = {34, 32, 3, 2, 5, 0, 32};
  const uint64_t expect[] = {34, 32, 3, 2, 5, 0, 32};

  counting_sort(c, arr, 0);
  cr_assert_arr_eq(arr, expect, UTIL_ARRAY_SIZE(expect));
}

Test(CountingSort, SortNotCrashWhenArrayIsNULL)
{
  const uint64_t expect[] = {34, 32, 3, 2, 5, 0, 32};

  counting_sort(c, NULL, 3);
}
