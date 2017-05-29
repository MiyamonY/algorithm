/**
 * File:  test_binary_search_tree.c
 * Author: ymiyamoto
 *
 * Created on Sat May 27 15:05:18 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

binary_search_tree_t t;

static int64_t buffer[100];
static size_t count = 0;

static uint32_t memory_allocation_counter = 0;
extern void *__real_malloc(size_t bytes);
extern void __real_free(void *obj);

void *__wrap_malloc(size_t bytes)
{
  memory_allocation_counter++;
  return __real_malloc(bytes);
}

void __wrap_free(void *obj)
{
  memory_allocation_counter--;
  __real_free(obj);
}

static void callback(int64_t data)
{
  buffer[count] = data;
  count++;
}

static void setup(void)
{
  t = binary_search_tree_create();
}

static void teardown(void)
{
  binary_search_tree_destroy(t);
}

TestSuite(BinarySearchTreeWhoseSizeIs0, .init = setup, .fini = teardown);

Test(BinarySearchTreeWhoseSizeIs0, PreorderSizeIs0)
{
  size_t len = binary_search_tree_preorder(t, callback);
  cr_assert_eq(len, 0);
}

Test(BinarySearchTreeWhoseSizeIs0, InorderSizeIs0)
{
  size_t len = binary_search_tree_inorder(t, callback);
  cr_assert_eq(len, 0);
}

static void setup1(void)
{
  t = binary_search_tree_create();
  binary_search_tree_insert(t, 1);
}

TestSuite(BinarySearchTreeWhoseSizeIs1, .init = setup1, .fini = teardown);

Test(BinarySearchTreeWhoseSizeIs1, PreorderSizeIs1)
{
  const int64_t expect[] = {1};

  size_t len = binary_search_tree_preorder(t, callback);
  cr_assert_eq(len, 1);
  cr_assert_arr_eq(buffer, expect, UTIL_ARRAY_SIZE(expect) * sizeof(int64_t));
}

Test(BinarySearchTreeWhoseSizeIs1, InorderSizeIs1)
{
  const int64_t expect[] = {1};

  size_t len = binary_search_tree_inorder(t, callback);
  cr_assert_eq(len, 1);
  cr_assert_arr_eq(buffer, expect, UTIL_ARRAY_SIZE(expect) * sizeof(int64_t));
}

static void setup2(void)
{
  t = binary_search_tree_create();
  binary_search_tree_insert(t, 30);
  binary_search_tree_insert(t, 88);
  binary_search_tree_insert(t, 12);
  binary_search_tree_insert(t, 1);
  binary_search_tree_insert(t, 20);
  binary_search_tree_insert(t, 17);
  binary_search_tree_insert(t, 25);
}

TestSuite(BinarySearchTree, .init = setup2, .fini = teardown);

Test(BinarySearchTree, PreorderReturnsKeys)
{
  const int64_t expect[] = {30, 12, 1, 20, 17, 25, 88};

  size_t len = binary_search_tree_preorder(t, callback);
  cr_assert_eq(len, UTIL_ARRAY_SIZE(expect));
  cr_assert_arr_eq(buffer, expect, UTIL_ARRAY_SIZE(expect) * sizeof(int64_t));
}

Test(BinarySearchTree, InorderReturnsKeys)
{
  const int64_t expect[] = {1, 12, 17, 20, 25, 30, 88};

  size_t len = binary_search_tree_inorder(t, callback);
  cr_assert_eq(len, UTIL_ARRAY_SIZE(expect));
  cr_assert_arr_eq(buffer, expect, UTIL_ARRAY_SIZE(expect) * sizeof(int64_t));
}

Test(BinarySearchTreeMemoryAllocationCheck, AllAllocationIsFreed)
{
  t = binary_search_tree_create();
  binary_search_tree_insert(t, 30);
  binary_search_tree_insert(t, 88);
  binary_search_tree_insert(t, 12);
  binary_search_tree_insert(t, 1);
  binary_search_tree_insert(t, 20);
  binary_search_tree_insert(t, 17);
  binary_search_tree_insert(t, 25);
  cr_assert_eq(memory_allocation_counter, 8);
  binary_search_tree_destroy(t);
  cr_assert_eq(memory_allocation_counter, 0);
}

Test(BinarySearchTreeNullCheck, AllFunctionNotCrashedWithNull)
{
  binary_search_tree_destroy(NULL);
  binary_search_tree_insert(NULL, 3);
  cr_assert_eq(binary_search_tree_preorder(NULL, NULL), 0);
  t = binary_search_tree_create();
  cr_assert_eq(binary_search_tree_preorder(t, NULL), 0);
  cr_assert_eq(binary_search_tree_inorder(NULL, NULL), 0);
  cr_assert_eq(binary_search_tree_inorder(t, NULL), 0);
  binary_search_tree_destroy(t);
}
