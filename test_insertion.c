/**
 * File:  test_insersion.c
 * Author: ymiyamoto
 *
 * Created on Fri Apr 21 16:49:11 2017
 */

#include <criterion/criterion.h>
#include <stdint.h>

#include "insertion.h"

static const uint8_t const ac[] = {1, 2, 3, 4, 5, 6};

Test(insertion, sorted)
{
  uint8_t sort[] = {1, 2, 3, 4, 5, 6};

  insertion_sort(sort, sizeof(sort));
  cr_assert_arr_eq(ac, sort, sizeof(ac));

  return;
}

Test(insersion, decr)
{
  uint8_t sort[] = {6, 5, 4, 3, 2, 1};

  insertion_sort(sort, sizeof(sort));
  cr_assert_arr_eq(ac, sort, sizeof(ac));

  return;
}

Test(insersion, rand)
{
  uint8_t sort[] = {6, 3, 4, 1, 5, 2};

  insertion_sort(sort, sizeof(sort));
  cr_assert_arr_eq(ac, sort, sizeof(ac));

  return;
}

static const uint8_t const ac2[] = {1, 2, 2, 2, 5, 6};

Test(insersion, has_same_number)
{
  uint8_t sort[] = {6, 2, 2, 1, 5, 2};

  insertion_sort(sort, sizeof(sort));
  cr_assert_arr_eq(ac2, sort, sizeof(ac2));

  return;
}
