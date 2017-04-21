/**
 * File:  test_gcd.c
 * Author: ymiyamoto
 *
 * Created on Sat Apr 22 03:57:58 2017
 */

#include <criterion/criterion.h>
#include <stdint.h>

#include "gcd.h"

Test(gcd, same_number)
{
  int64_t x = gcd(2, 2);
  cr_assert_eq(2, x, "Error %d(actual) is not %d(expected)\n", x, 2);
}

Test(gcd, simple_gcd)
{
  int64_t x = gcd(6, 3);
  cr_assert_eq(3, x, "Error %d(actual) is not %d(expected)\n", x, 3);
}

Test(gcd, simple_gcd2)
{
  int64_t x = gcd(3, 12);
  cr_assert_eq(3, x, "Error %d(actual) is not %d(expected)\n", x, 3);
}

Test(gcd, two_number_has_no_gcd)
{
  int64_t x = gcd(5, 7);
  cr_assert_eq(1, x, "Error %d(actual) is not %d(expected)\n", x, 1);
}

Test(gcd, great_divisioner)
{
  int64_t x = gcd(8, 12);
  cr_assert_eq(4, x, "Error %d(actual) is not %d(expected)\n", x, 4);
}

Test(gcd, large_number)
{
  int64_t x = gcd(812500000, 1000000000);
  cr_assert_eq(25 * 25 * 100000, x, "Error %l(actual) is not %l(expected)\n", x, 25 * 25 * 100000);
}
