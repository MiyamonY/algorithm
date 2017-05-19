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
  card_t cards[] = {{.num = 3, .design = 'A'}, {.num = 1, .design = 'B'}, {.num = 2, .design = 'C'}, {.num = 4, .design = 'D'}};
  const card_t expect[] = {{.num = 1, .design = 'A'}, {.num = 2, .design = 'B'}, {.num = 3, .design = 'C'}, {.num = 4, .design = 'D'}};

  quick_sort(cards, UTIL_ARRAY_SIZE(cards));

  cr_assert_arr_eq(cards, expect, UTIL_ARRAY_SIZE(expect));
}

Test(QuickSort, SortArrayHasSameNum)
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
