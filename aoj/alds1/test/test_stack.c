/**
 * File:  test_stack.c
 * Author: ymiyamoto
 *
 * Created on Fri Apr 28 12:27:23 2017
 */

#include <criterion/criterion.h>
#include <stdint.h>

#include "problems.h"

/*    NULLにget_size push,getしてもerrorがおきる
*/

#define STACK_SIZE 10

static stack_t *s = NULL;

static void push_stack_until_full(stack_t *const stack)
{
  for (uint32_t i = 0; i < STACK_SIZE; i++) {
    bool ok = stack_push(stack, i);
    cr_assert(ok);
  }
}

void setup(void)
{
  s = stack_create(STACK_SIZE);
}

void teardown(void)
{
  stack_destroy(s);
}

Test(stack, GetStackSizeWhenCreated, .init = setup, .fini = teardown)
{
  size_t size = stack_get_size(s);
  cr_assert_eq(size, 0);
}

Test(stack, AddDataToStack, .init = setup, .fini = teardown)
{
  int32_t data = 1;
  bool ok = stack_push(s, data);
  cr_assert(ok);
  cr_assert_eq(1, stack_get_size(s));
}

Test(stack, AddDataToStackWhenStackIsFull, .init = setup, .fini = teardown)
{
  push_stack_until_full(s);
  cr_assert_eq(STACK_SIZE, stack_get_size(s));

  bool ok = stack_push(s, 1);
  cr_assert(!ok);
  cr_assert_eq(STACK_SIZE, stack_get_size(s));
}

Test(stack, PopDataFromStackWhenStackIsEmpty, .init = setup, .fini = teardown)
{
  int32_t data;
  bool ret = stack_pop(s, &data);
  cr_assert(!ret);
  cr_assert_eq(stack_get_size(s), 0);
}

Test(stack, PopDataFromStack, .init = setup, .fini = teardown)
{
  int32_t data = 0;
  bool ret = stack_push(s, 3);
  cr_assert(ret);
  ret = stack_pop(s, &data);
  cr_assert(ret);
  cr_assert_eq(data, 3);
  cr_assert_eq(stack_get_size(s), 0);
}

Test(stack, PopDataFromStackWithFull, .init = setup, .fini = teardown)
{
  push_stack_until_full(s);

  int32_t data;
  bool ret = stack_pop(s, &data);
  cr_assert(ret);
  cr_assert_eq(data, STACK_SIZE - 1);

  ret = stack_push(s, 9);
  cr_assert(ret);
}
