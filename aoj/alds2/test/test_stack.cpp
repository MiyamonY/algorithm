///
// File:  test_stack.cpp
// Author: ymiyamoto
//
// Created on Fri Jun 30 05:58:22 2017
//

#include <cstdint>

#include "problems.hpp"
#include <criterion/criterion.h>

using namespace std;

TestSuite(Stack);

Test(Stack, PushAndPop)
{
  stack_push(3);
  stack_push(10);
  int32_t data;
  cr_assert(stack_pop(data));
  cr_assert_eq(data, 10);
  cr_assert(stack_pop(data));
  cr_assert_eq(data, 3);
  cr_assert_not(stack_pop(data));
}
