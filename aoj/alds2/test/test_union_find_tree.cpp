///
// File:  test_union_find_tree.cpp
// Author: ymiyamoto
//
// Created on Tue Jul 18 23:43:28 2017
//

#include <cstdint>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

TestSuite(UnionFindTree);

Test(UnionFindTree, Unite)
{
  union_find_tree_init(10);
  union_find_tree_unite(1, 4);
  union_find_tree_unite(2, 3);
  union_find_tree_unite(4, 3);
  union_find_tree_unite(5, 7);
  union_find_tree_unite(7, 8);

  cr_assert(union_find_tree_same(1, 3));
  cr_assert_not(union_find_tree_same(3, 8));
}
