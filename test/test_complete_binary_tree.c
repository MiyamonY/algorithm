/**
 * File:  test_complete_binary_tree.c
 * Author: ymiyamoto
 *
 * Created on Fri Jun  2 02:15:56 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"

static complete_binary_tree_t t;

static void setup(void)
{
  t = complete_binary_tree_create(100);
}

static void teardown(void)
{
  complete_binary_tree_destroy(t);
}

TestSuite(CompleteBinaryTree, .init = setup, .fini = teardown);

Test(CompleteBinaryTree, IsAbleToInsertDataWhenDataIsNotFull)
{
  bool empty = complete_binary_tree_insert(t, 1);
  cr_assert(empty);
}

Test(CompleteBinaryTree, TopEelemntsParentKeyShouldBeNone)
{
  complete_binary_tree_key key = complete_binary_tree_parent(t, 1);
  cr_assert_eq(key, COMPLETE_BINARY_TREE_KEY_NONE);
}

Test(CompleteBinaryTree, LeftKeyIsTwoTimesOfItsIndex)
{
  const complete_binary_tree_key parent_key = 1;
  complete_binary_tree_key key = complete_binary_tree_left_key(t, parent_key);
  cr_assert_eq(key, 2 * parent_key);
}

Test(CompleteBinaryTree, RightKeyIsTwoTimesOfItsKeyPlus1)
{
  const complete_binary_tree_key parent_key = 1;
  complete_binary_tree_key key = complete_binary_tree_right_key(t, parent_key);
  cr_assert_eq(key, 2 * parent_key + 1);
}
