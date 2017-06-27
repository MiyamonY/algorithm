/**
 * File:  test_binary_tree.c
 * Author: ymiyamoto
 *
 * Created on Wed May 24 03:16:48 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"

static binary_tree_t t;

static void setup(void)
{
  t = binary_tree_create(20);
  cr_assert(binary_tree_insert(t, 0, 1, 4));
  cr_assert(binary_tree_insert(t, 1, 2, 3));
  cr_assert(binary_tree_insert(t, 2, BINARY_TREE_ID_NULL, BINARY_TREE_ID_NULL));
  cr_assert(binary_tree_insert(t, 3, BINARY_TREE_ID_NULL, BINARY_TREE_ID_NULL));
  cr_assert(binary_tree_insert(t, 4, 5, 8));
  cr_assert(binary_tree_insert(t, 5, 6, 7));
  cr_assert(binary_tree_insert(t, 6, BINARY_TREE_ID_NULL, BINARY_TREE_ID_NULL));
  cr_assert(binary_tree_insert(t, 7, BINARY_TREE_ID_NULL, BINARY_TREE_ID_NULL));
  cr_assert(binary_tree_insert(t, 8, BINARY_TREE_ID_NULL, BINARY_TREE_ID_NULL));
}

static void teardown(void)
{
  binary_tree_destroy(t);
}

TestSuite(BinaryTree, .init = setup, .fini = teardown);

Test(BinaryTree, InsertEelemtSameId)
{
  cr_assert_not(binary_tree_insert(t, 0, 1, 2));
}

Test(BinaryTree, TopElementHasNoSibling)
{
  binary_tree_id_t sibling;
  cr_assert_not(binary_tree_sibling(t, 0, &sibling));
}

Test(BinaryTree, LeafHasRightSibling)
{
  binary_tree_id_t sibling = BINARY_TREE_ID_NULL;

  cr_assert(binary_tree_sibling(t, 2, &sibling));
  cr_assert_eq(sibling, 3);
}

Test(BinaryTree, LeafHasLeftSibling)
{
  binary_tree_id_t sibling = BINARY_TREE_ID_NULL;

  cr_assert(binary_tree_sibling(t, 3, &sibling));
  cr_assert_eq(sibling, 2);
}

Test(BinaryTree, SiblingErrorWhenIdNotExist)
{
  binary_tree_id_t sibling = BINARY_TREE_ID_NULL;

  cr_assert_not(binary_tree_sibling(t, 9, &sibling));
}

Test(BinaryTree, LeafHasNoChild)
{
  size_t degree = 0xff;
  cr_assert(binary_tree_degree(t, 2, &degree));
  cr_assert_eq(degree, 0);
}

Test(BinaryTree, NodeHasTwoChildren)
{
  size_t degree = 0xff;
  cr_assert(binary_tree_degree(t, 4, &degree));
  cr_assert_eq(degree, 2);
}

Test(BinaryTree, TopHasTwoChildren)
{
  size_t degree = 0xff;
  cr_assert(binary_tree_degree(t, 0, &degree));
  cr_assert_eq(degree, 2);
}

Test(BinaryTree, DegreeErrorWhenIdNotExist)
{
  size_t degree = 0xff;
  cr_assert_not(binary_tree_degree(t, 9, &degree));
}

Test(BinaryTree, DepthOfTopElementIs0)
{
  size_t depth = 0xff;
  cr_assert(binary_tree_depth(t, 0, &depth));
  cr_assert_eq(depth, 0);
}

Test(BinaryTree, CheckDepthOfNode)
{
  size_t depth = 0xff;
  cr_assert(binary_tree_depth(t, 5, &depth));
  cr_assert_eq(depth, 2);
}

Test(BinaryTree, CheckDepthOfLeaf)
{
  size_t depth = 0xff;
  cr_assert(binary_tree_depth(t, 8, &depth));
  cr_assert_eq(depth, 2);
}

Test(BinaryTree, DepthErrorWhenIdNotExists)
{
  size_t depth = 0xff;
  cr_assert_not(binary_tree_depth(t, 9, &depth));
}

Test(BinaryTree, HeightOfLeafIs0)
{
  size_t height = 0xff;
  cr_assert(binary_tree_height(t, 8, &height));
  cr_assert_eq(height, 0);
}

Test(BinaryTree, CheckHeightOfTop)
{
  size_t height = 0xff;
  cr_assert(binary_tree_height(t, 0, &height));
  cr_assert_eq(height, 3);
}

Test(BinaryTree, CheckHeightOfNode)
{
  size_t height = 0xff;
  cr_assert(binary_tree_height(t, 4, &height));
  cr_assert_eq(height, 2);
}

Test(BinaryTree, HeightErrorWhenIdNotExists)
{
  size_t height = 0xff;
  cr_assert_not(binary_tree_height(t, 9, &height));
}

Test(BinaryTree, InterfaceNotCrashWhenPassingNULL)
{
  binary_tree_destroy(NULL);
  cr_assert_not(binary_tree_insert(NULL, BINARY_TREE_ID_NULL, BINARY_TREE_ID_NULL, BINARY_TREE_ID_NULL));
  binary_tree_id_t sibling;
  cr_assert_not(binary_tree_sibling(NULL, BINARY_TREE_ID_NULL, NULL));
  cr_assert_not(binary_tree_degree(NULL, BINARY_TREE_ID_NULL, NULL));
  cr_assert_not(binary_tree_depth(NULL, BINARY_TREE_ID_NULL, NULL));
  cr_assert_not(binary_tree_height(NULL, BINARY_TREE_ID_NULL, NULL));
}
