/**
 * File:  test_longest_common_subsequence.c
 * Author: ymiyamoto
 *
 * Created on Mon Jun 19 10:57:08 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

TestSuite(LongestCommonSubsequence);

Test(LongestCommonSubsequence, LengthIs0)
{
  char arr1[] = "abc";
  char arr2[] = "abcdef";
  size_t len = longest_common_subsequence(arr1, 0, arr2, strlen(arr2));
  cr_assert_eq(len, 0);
  size_t len2 = longest_common_subsequence(arr1, strlen(arr1), arr2, 0);
  cr_assert_eq(len2, 0);
}

Test(LongestCommonSubsequence, SameValueLengthIs1)
{
  char arr1[] = "a";
  char arr2[] = "a";
  size_t len = longest_common_subsequence(arr1, strlen(arr1), arr2, strlen(arr2));
  cr_assert_eq(len, 1);
}

Test(LongestCommonSubsequence, DifferentValueLengthIs1)
{
  char arr1[] = "a";
  char arr2[] = "b";
  size_t len = longest_common_subsequence(arr1, strlen(arr1), arr2, strlen(arr2));
  cr_assert_eq(len, 0);
}

Test(LongestCommonSubsequence, LengthIsN)
{
  char arr1[] = "abcbdab";
  char arr2[] = "bdcaba";
  size_t len = longest_common_subsequence(arr1, strlen(arr1), arr2, strlen(arr2));
  cr_assert_eq(len, 4);
}

Test(LongestCommonSubsequence, LengthIsN2)
{
  char arr1[] = "abc";
  char arr2[] = "bc";
  size_t len = longest_common_subsequence(arr1, strlen(arr1), arr2, strlen(arr2));
  cr_assert_eq(len, 2);
}
