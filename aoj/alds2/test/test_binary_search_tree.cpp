///
// File:  test_binary_search_tree.cpp
// Author: ymiyamoto
//
// Created on Tue Jul 11 19:26:29 2017
//

#include <cstdint>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

static vector<int64_t> pre;

using namespace std;

static void preorder(int64_t val)
{
  pre.push_back(val);
}

static void setup()
{
  binary_search_tree_insert(10);
  binary_search_tree_insert(3);
  binary_search_tree_insert(11);
  binary_search_tree_insert(12);
  binary_search_tree_insert(2);
  binary_search_tree_insert(4);
  binary_search_tree_insert(1);
  pre.clear();
}

TestSuite(BinarySearchTree, .init = setup);

Test(BinarySearchTree, DeleteLeaf)
{
  binary_search_tree_delete(4);
  binary_search_tree_walk(preorder, nullptr, nullptr);

  const vector<int64_t> expect{10, 3, 2, 1, 11, 12};
  cr_assert_eq(pre, expect);
}

#include <iostream>

Test(BinarySearchTree, DeleteNode)
{
  binary_search_tree_delete(2);
  binary_search_tree_walk(preorder, nullptr, nullptr);

  const vector<int64_t> expect{10, 3, 1, 4, 11, 12};
  cr_assert_eq(pre, expect);

  binary_search_tree_delete(1);
  pre.clear();
  binary_search_tree_walk(preorder, nullptr, nullptr);

  const vector<int64_t> expect2{10, 3, 4, 11, 12};
  cr_assert_eq(pre, expect2);
}

Test(BinarySearchTree, DeleteNode2)
{
  binary_search_tree_delete(11);
  binary_search_tree_walk(preorder, nullptr, nullptr);

  const vector<int64_t> expect{10, 3, 2, 1, 4, 12};
  cr_assert_eq(pre, expect);
}

Test(BinarySearchTree, DeleteNode3)
{
  binary_search_tree_delete(3);
  binary_search_tree_walk(preorder, nullptr, nullptr);

  const vector<int64_t> expect{10, 4, 2, 1, 11, 12};
  cr_assert_eq(pre, expect);
}
