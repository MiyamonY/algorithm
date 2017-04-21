/**
 * File:  test_bubble.c
 * Author: ymiyamoto
 *
 * Created on Sat Apr 22 04:38:28 2017
 */

#include <criterion/criterion.h>
#include <stdint.h>

#include "problems.h"
#include "util.h"

static const int32_t expected[] = {1, 2, 3, 4, 5, 6};
static const int32_t expected_sin[] = {1};

Test(bubble, single)
{
  int32_t test[] = {1};
  size_t num = bubble_sort(test, UTIL_ARRAY_SIZE(test));

  cr_assert_arr_eq(expected_sin, test, UTIL_ARRAY_SIZE(expected_sin));
  cr_assert_eq(0, num);

  return;
}

Test(bubble, sorted)
{
  int32_t test[] = {1, 2, 3, 4, 5, 6};
  size_t num = bubble_sort(test, UTIL_ARRAY_SIZE(test));

  cr_assert_arr_eq(expected, test, UTIL_ARRAY_SIZE(expected));
  cr_assert_eq(0, num);

  return;
}

Test(bubble, unsorted1)
{
  int32_t test[] = {2, 1, 3, 4, 5, 6};
  size_t num = bubble_sort(test, UTIL_ARRAY_SIZE(test));

  cr_assert_arr_eq(expected, test, UTIL_ARRAY_SIZE(expected));
  cr_assert_eq(1, num);

  return;
}

Test(bubble, decs)
{
  int32_t test[] = {6, 5, 4, 3, 2, 1};
  size_t num = bubble_sort(test, UTIL_ARRAY_SIZE(test));

  cr_assert_arr_eq(expected, test, UTIL_ARRAY_SIZE(expected));
  cr_assert_eq(15, num);

  return;
}
