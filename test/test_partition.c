/**
 * File:  test_partition.c
 * Author: ymiyamoto
 *
 * Created on Sun May 14 02:02:09 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

Test(Partition, ArrayIsNull)
{
  size_t index = partition(NULL, 1, 5);
  cr_assert_eq(index, 0);
}

Test(Partition, ArraySizeIs0)
{
  const int32_t expect[] = {1, 3, 2};
  int32_t data[] = {1, 3, 2};
  size_t index = partition(data, 0, 5);
  cr_assert_arr_eq(data, expect, sizeof(expect));
  cr_assert_eq(index, 0);
}

Test(Partition, ArraySizeIs1AndPivotIsSmall)
{
  const int32_t expect[] = {1};
  int32_t data[] = {1};
  size_t index = partition(data, UTIL_ARRAY_SIZE(data), 0);
  cr_assert_arr_eq(data, expect, sizeof(expect));
  cr_assert_eq(index, 0);
}

Test(Partition, ArraySizeIs1AndPivotIsBig)
{
  const int32_t expect[] = {1};
  int32_t data[] = {1};
  size_t index = partition(data, UTIL_ARRAY_SIZE(data), 3);
  cr_assert_arr_eq(data, expect, sizeof(expect));
  cr_assert_eq(index, 1);
}

Test(Partition, PivotIsTheBiggest)
{
  const int32_t expect[] = {3, 1};
  int32_t data[] = {3, 1};
  size_t index = partition(data, UTIL_ARRAY_SIZE(data), 4);
  cr_assert_arr_eq(data, expect, sizeof(expect));
  cr_assert_eq(index, 2);
}

Test(Partition, PivotIsMiddleInTheData)
{
  const int32_t expect[] = {1, 3};
  int32_t data[] = {3, 1};
  size_t index = partition(data, UTIL_ARRAY_SIZE(data), 2);
  cr_assert_arr_eq(data, expect, sizeof(expect));
  cr_assert_eq(index, 1);
}

Test(Partition, PivotIsTheSmallest)
{
  const int32_t expect[] = {3, 1};
  int32_t data[] = {3, 1};
  size_t index = partition(data, UTIL_ARRAY_SIZE(data), 0);
  cr_assert_arr_eq(data, expect, sizeof(expect));
  cr_assert_eq(index, 0);
}

Test(Partition, DataHasSameNumberOfPivot)
{
  const int32_t expect[] = {3, 1};
  int32_t data[] = {3, 1};
  size_t index = partition(data, UTIL_ARRAY_SIZE(data), 3);
  cr_assert_arr_eq(data, expect, sizeof(expect));
  cr_assert_eq(index, 2);
}

Test(Partition, RandomNumber)
{
  const int32_t expect[] = {1, 2, 3, 5, 7, 13, 14, 12, 9};
  int32_t data[] = {1, 12, 13, 14, 2, 3, 5, 7, 9};
  size_t index = partition(data, UTIL_ARRAY_SIZE(data), 8);
  cr_assert_arr_eq(data, expect, sizeof(expect));
  cr_assert_eq(index, 5);
}
