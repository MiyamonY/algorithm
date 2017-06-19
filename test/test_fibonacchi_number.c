/**
 * File:  test_fibonacchi_number.c
 * Author: ymiyamoto
 *
 * Created on Mon Jun 19 09:50:01 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"

TestSuite(FibbonacchiNumber);

static void assert_fibonacchi_number(int64_t n, int64_t expect)
{
  int64_t fib = fibonacchi_number(n);
  cr_assert_eq(expect, fib);
}

Test(FibbonacchiNumber, fib0)
{
  assert_fibonacchi_number(0, 1);
}

Test(FibbonacchiNumber, fib1)
{
  assert_fibonacchi_number(1, 1);
}

Test(FibbonacchiNumber, fib2)
{
  assert_fibonacchi_number(2, 2);
}

Test(FibbonacchiNumber, fib19)
{
  assert_fibonacchi_number(19, 6765);
}
