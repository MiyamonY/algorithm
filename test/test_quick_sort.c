/**
 * File:  test_quick_sort.c
 * Author: ymiyamoto
 *
 * Created on Fri May 19 02:36:34 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

Test(QuickSort, ArgumentIsNULL)
{
  quick_sort(NULL, 3);
}

Test(QuickSort, ArraySizeIs0)
{
  card_t cards[] = {{.num = 1, .design = 'A'}};
  quick_sort(cards, 0);
}

Test(QuickSort, SortArrayWhoseDataSizeIs1)
{
  card_t cards[] = {{.num = 1, .design = 'A'}};
  const card_t expect[] = {{.num = 1, .design = 'A'}};

  quick_sort(cards, UTIL_ARRAY_SIZE(cards));

  cr_assert_arr_eq(cards, expect, UTIL_ARRAY_SIZE(expect));
}

Test(QuickSort, SortSortedArray)
{
  card_t cards[] = {{.num = 1, .design = 'A'}, {.num = 2, .design = 'B'}, {.num = 3, .design = 'C'}, {.num = 4, .design = 'D'}};
  const card_t expect[] = {{.num = 1, .design = 'A'}, {.num = 2, .design = 'B'}, {.num = 3, .design = 'C'}, {.num = 4, .design = 'D'}};

  quick_sort(cards, UTIL_ARRAY_SIZE(cards));

  cr_assert_arr_eq(cards, expect, UTIL_ARRAY_SIZE(expect));
}

Test(QuickSort, SortArray)
{
  card_t cards[] = {
      {.num = 3, .design = 'A'}, {.num = 1, .design = 'B'}, {.num = 2, .design = 'C'}, {.num = 4, .design = 'D'},
  };
  const card_t expect[] = {
      {.num = 1, .design = 'A'}, {.num = 2, .design = 'B'}, {.num = 3, .design = 'C'}, {.num = 4, .design = 'D'},
  };

  quick_sort(cards, UTIL_ARRAY_SIZE(cards));

  cr_assert_arr_eq(cards, expect, UTIL_ARRAY_SIZE(expect));
}

Test(QuickSort, SortArrayHasSameValue)
{
  card_t cards[] = {{.num = 3, .design = 'A'},
                    {.num = 1, .design = 'B'},
                    {.num = 2, .design = 'C'},
                    {.num = 4, .design = 'D'},
                    {.num = 1, .design = 'E'}};
  const card_t expect[] = {{.num = 1, .design = 'A'},
                           {.num = 1, .design = 'E'},
                           {.num = 2, .design = 'B'},
                           {.num = 3, .design = 'C'},
                           {.num = 4, .design = 'D'}};

  quick_sort(cards, UTIL_ARRAY_SIZE(cards));

  cr_assert_arr_eq(cards, expect, UTIL_ARRAY_SIZE(expect));
}

Test(IsStable, Size1ArrayIsStable)
{
  card_t cards[] = {
      {.num = 3, .design = 'A'},
  };

  bool ret = quick_sort_is_stable(cards, UTIL_ARRAY_SIZE(cards));
  cr_assert(ret);
}

Test(IsStable, Size2ArrayIsStable)
{
  card_t cards[] = {
      {.num = 3, .design = 'C'}, {.num = 1, .design = 'A'},
  };

  bool ret = quick_sort_is_stable(cards, UTIL_ARRAY_SIZE(cards));
  cr_assert(ret);
}

Test(IsStable, NotStable)
{
  card_t cards[] = {{.num = 3, .design = 'D'}, {.num = 2, .design = 'H'}, {.num = 1, .design = 'D'},
                    {.num = 3, .design = 'S'}, {.num = 2, .design = 'D'}, {.num = 1, .design = 'C'}};

  bool ret = quick_sort_is_stable(cards, UTIL_ARRAY_SIZE(cards));
  cr_assert_not(ret);
}