/**
 * File:  test_exhaustive_search.c
 * Author: ymiyamoto
 *
 * Created on Wed May 10 12:30:24 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

static int32_t *data_;
static size_t size_;
static int32_t expect;

static void when(int32_t data[], size_t size)
{
  data_ = data;
  size_ = size;
}

static void expect_true(int32_t expect)
{
  cr_assert(exhaustive_search_search(data_, size_, expect));
}

static void expect_false(int32_t expect)
{
  cr_assert_not(exhaustive_search_search(data_, size_, expect));
}

Test(ExhaustiveSearch, DataIsNUll)
{
  when(NULL, 3);
  expect_false(35);
}

Test(ExhaustiveSearch, DataSizeIs0)
{
  int32_t data[] = {1, 2, 3};
  when(data, 0);
  expect_false(32);
}

Test(ExhausitveSearch, DataNotFound)
{
  int32_t data[] = {1};
  when(data, UTIL_ARRAY_SIZE(data));
  expect_false(35);
}

Test(ExhausitveSearch, DataSingleFound)
{
  int32_t data[] = {1};
  when(data, UTIL_ARRAY_SIZE(data));
  expect_true(1);
}

Test(ExhausitveSearch, DataDoubleNotFound)
{
  int32_t data[] = {26, 34};
  when(data, UTIL_ARRAY_SIZE(data));
  expect_false(1);
}

Test(ExhausitveSearch, DataDoubleFoundFisrt)
{
  int32_t data[] = {37, 33};
  when(data, UTIL_ARRAY_SIZE(data));
  expect_true(37);
}

Test(ExhausitveSearch, DataDoubleFoundLast)
{
  int32_t data[] = {37, 33};
  when(data, UTIL_ARRAY_SIZE(data));
  expect_true(33);
}

Test(ExhausitveSearch, DataWhoseSumIsFoundData)
{
  int32_t data[] = {7234, 234};
  when(data, UTIL_ARRAY_SIZE(data));
  expect_true(7468);
}

Test(ExhausiveSearch, RandomNotFound)
{
  int32_t data[] = {1, 5, 7, 10, 21};
  when(data, UTIL_ARRAY_SIZE(data));
  expect_false(4);
}

Test(ExhausiveSearch, RandomFound)
{
  int32_t data[] = {1, 5, 7, 10, 21};
  when(data, UTIL_ARRAY_SIZE(data));
  expect_true(17);
}
