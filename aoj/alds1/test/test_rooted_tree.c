/**
 * File:  test_rooted_tree.c
 * Author: ymiyamoto
 *
 * Created on Sun May 21 23:14:41 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

rooted_tree_t t;

void setup(void)
{
  t = rooted_tree_create(100);
  rooted_tree_id_t children[] = {1, 2, 3};
  cr_assert(rooted_tree_insert(t, 0, children, UTIL_ARRAY_SIZE(children)));
  cr_assert(rooted_tree_insert(t, 1, NULL, 0));
  rooted_tree_id_t children2[] = {4, 5};
  cr_assert(rooted_tree_insert(t, 2, children2, UTIL_ARRAY_SIZE(children2)));
  cr_assert(rooted_tree_insert(t, 3, NULL, 0));
  cr_assert(rooted_tree_insert(t, 4, NULL, 0));
  cr_assert(rooted_tree_insert(t, 5, NULL, 0));
}

void teardown(void)
{
  rooted_tree_destroy(t);
}

TestSuite(RootedTree, .init = setup, .fini = teardown);

Test(RootedTree, InsertElementSameIdError)
{
  cr_assert_not(rooted_tree_insert(t, 0, NULL, 0));
}

Test(RootedTree, TopElementDepthIs0)
{
  uint64_t depth = 0xff;
  bool ret = rooted_tree_depth(t, 0, &depth);
  cr_assert(ret);
  cr_assert_eq(depth, 0);
}

Test(RootedTree, CalcNodeDepth)
{
  uint64_t depth = 0xff;
  bool ret = rooted_tree_depth(t, 2, &depth);
  cr_assert(ret);
  cr_assert_eq(depth, 1);
}

Test(RootedTree, CalcLeafDepth)
{
  uint64_t depth = 0xff;
  bool ret = rooted_tree_depth(t, 5, &depth);
  cr_assert(ret);
  cr_assert_eq(depth, 2);
}

Test(RootedTree, DepthIsErrorWhenIdNotExist)
{
  uint64_t depth = 0xff;
  bool ret = rooted_tree_depth(t, 6, &depth);
  cr_assert_not(ret);
}

Test(RootedTree, TopElementHasNoParent)
{
  rooted_tree_id_t parent;
  bool ret = rooted_tree_parent(t, 0, &parent);
  cr_assert(ret);
  cr_assert_eq(parent, ROOTED_TREE_ID_NULL);
}

Test(RootedTree, NodeHasParent)
{
  rooted_tree_id_t parent;
  bool ret = rooted_tree_parent(t, 1, &parent);
  cr_assert(ret);
  cr_assert_eq(parent, 0);
}

Test(RootedTree, LeafHasParent)
{
  rooted_tree_id_t parent;
  bool ret = rooted_tree_parent(t, 5, &parent);
  cr_assert(ret);
  cr_assert_eq(parent, 2);
}

Test(RootedTree, ParentIsErrorWhenIdNotExists)
{
  rooted_tree_id_t parent;
  bool ret = rooted_tree_parent(t, 6, &parent);
  cr_assert_not(ret);
}

Test(RootedTree, NodeHasChildren)
{
  const rooted_tree_id_t expect[] = {4, 5};
  rooted_tree_id_t children[10];
  size_t len = 0xff;
  bool ret = rooted_tree_children(t, 2, children, &len);

  cr_assert(ret);
  cr_assert_eq(len, 2, "len is %u", len);
  cr_assert_arr_eq(children, expect, sizeof(expect));
}

Test(RootedTree, LeafHasNoChildren)
{
  rooted_tree_id_t children[10];
  size_t len = 0xff;
  bool ret = rooted_tree_children(t, 1, children, &len);
  cr_assert(ret);
  cr_assert_eq(len, 0);
}

Test(RootedTree, ChildrenErrorWhenIdNotExists)
{
  rooted_tree_id_t children[10];
  size_t len = 0xff;
  bool ret = rooted_tree_children(t, 6, children, &len);
  cr_assert_not(ret);
}

Test(RootedTree, InterfaceNotRaiseException)
{
  size_t len;
  rooted_tree_id_t parent;
  rooted_tree_destroy(NULL);
  cr_assert_not(rooted_tree_insert(NULL, 0, NULL, 0));
  cr_assert_not(rooted_tree_insert(t, 0, NULL, 3));
  cr_assert_not(rooted_tree_depth(NULL, 0, &len));
  cr_assert_not(rooted_tree_parent(NULL, 0, &parent));
  cr_assert_not(rooted_tree_children(NULL, 0, NULL, &len));
}
