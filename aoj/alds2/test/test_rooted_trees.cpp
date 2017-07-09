///
// File:  test_rooted_trees.cpp
// Author: ymiyamoto
//
// Created on Sun Jul  9 08:19:59 2017
//

#include <cstdint>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

static void setup()
{
  rooted_tree_init();

  vector<int32_t> children{1, 2, 3};
  vector<int32_t> null;

  rooted_tree_add(0, children);
  rooted_tree_add(1, null);
  rooted_tree_add(2, null);
  rooted_tree_add(3, null);
}

TestSuite(RootedTrees, .init = setup);

Test(RootedTrees, TraverseIndex)
{
  int32_t parent;
  vector<int32_t> children0, children1;
  size_t depth;

  rooted_tree_info(0, parent, children0, depth);

  const vector<int32_t> expect{1, 2, 3};
  cr_assert_eq(parent, -1);
  cr_assert_eq(children0.size(), expect.size(), "%d isn't %d", children0.size(), expect.size());
  cr_assert_eq(depth, 0);
  cr_assert_eq(children0, expect);

  rooted_tree_info(1, parent, children1, depth);
  cr_assert_eq(parent, 0);
  cr_assert_eq(children1.size(), 0);
  cr_assert_eq(depth, 1);
}
