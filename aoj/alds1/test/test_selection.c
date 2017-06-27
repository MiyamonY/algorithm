/**
 * File:  test_selection.c
 * Author: ymiyamoto
 *
 * Created on Wed Apr 26 02:16:32 2017
 */

#include <criterion/criterion.h>
#include <stdint.h>

#include "problems.h"
#include "util.h"

const static int32_t expected[] = {1, 2, 3, 4, 5, 6};
static int32_t const *expected_array;
static uint32_t expected_array_size;

static void set_expected_array(const int32_t const array[], const uint32_t array_size)
{
  expected_array = array;
  expected_array_size = array_size;
}

static void assert_sorted(uint32_t const buf[], const size_t buf_size, const size_t count_expected)
{
  char format1[256];
  char format2[256];
  uint32_t count = selection_sort(buf, buf_size);
  cr_assert_arr_eq(buf, expected_array, expected_array_size, "%s(buf) is not equal %s(expected)\n",
                   util_sprintf_array(format1, buf, buf_size), util_sprintf_array(format2, expected_array, expected_array_size));
  cr_assert_eq(count, count_expected);
}

void setup(void)
{
  set_expected_array(expected, UTIL_ARRAY_SIZE(expected));
}

Test(selection_sort, buf_is_null)
{
  int32_t count = selection_sort(NULL, 0);
  cr_assert_eq(count, 0);
}

Test(selection_sort, buf_size_is_0)
{
  int32_t buf[] = {1, 2, 3, 4, 5, 6};

  assert_sorted(buf, UTIL_ARRAY_SIZE(buf), 0);
}

Test(selection_sort, buf_is_sorted)
{
  int32_t buf[] = {1, 2, 3, 4, 5, 6};

  assert_sorted(buf, UTIL_ARRAY_SIZE(buf), 0);
}

Test(selection_sort, exchanged_one)
{
  int32_t buf[] = {2, 1, 3, 4, 5, 6};
  assert_sorted(buf, UTIL_ARRAY_SIZE(buf), 1);
}

Test(selection_sort, desdened)
{
  int32_t buf[] = {6, 5, 4, 3, 2, 1};
  assert_sorted(buf, UTIL_ARRAY_SIZE(buf), 3);
}

Test(selection_sort, has_same_number)
{
  int32_t expected[] = {1, 2, 3, 3, 5, 6};
  int32_t buf[] = {6, 5, 3, 3, 2, 1};

  set_expected_array(expected, UTIL_ARRAY_SIZE(expected));
  assert_sorted(buf, UTIL_ARRAY_SIZE(buf), 2);
}
