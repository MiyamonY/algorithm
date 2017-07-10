///
// File:  test_binary_tree.cpp
// Author: ymiyamoto
//
// Created on Mon Jul 10 00:26:27 2017
//

#include <cstdint>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

static void setup()
{
  binary_tree_init();
}

TestSuite(BinaryTree, .init = setup);

Test(BinaryTree, Add)
{
  vector<pair<int32_t, pair<int32_t, int32_t>>> vec{{0, {1, 4}}, {1, {2, 3}},   {2, {-1, -1}}, {3, {-1, -1}},
                                                    {4, {5, 8}}, {6, {-1, -1}}, {7, {-1, -1}}, {8, {-1, -1}}};

  for (uint32_t i = 0; i < vec.size(); i++) {
    binary_tree_add(vec[i].first, vec[i].second.first, vec[i].second.first);
  }
}

Test(BinaryTree, Info)
{
  vector<pair<int32_t, pair<int32_t, int32_t>>> vec{{0, {1, 4}}, {1, {2, 3}},   {2, {-1, -1}}, {3, {-1, -1}}, {4, {5, 8}},
                                                    {5, {6, 7}}, {6, {-1, -1}}, {7, {-1, -1}}, {8, {-1, -1}}};

  for (uint32_t i = 0; i < vec.size(); i++) {
    binary_tree_add(vec[i].first, vec[i].second.first, vec[i].second.second);
  }

  int32_t parent, sibling;
  size_t degree, depth, height;
  binary_tree_info(0, parent, sibling, degree, depth, height);

  cr_assert_eq(parent, -1);
  cr_assert_eq(sibling, -1);
  cr_assert_eq(degree, 2);
  cr_assert_eq(depth, 0);
  cr_assert_eq(height, 3);

  binary_tree_info(4, parent, sibling, degree, depth, height);
  cr_assert_eq(parent, 0);
  cr_assert_eq(sibling, 1);
  cr_assert_eq(degree, 2);
  cr_assert_eq(depth, 1);
  cr_assert_eq(height, 2);

  binary_tree_info(6, parent, sibling, degree, depth, height);
  cr_assert_eq(parent, 5);
  cr_assert_eq(sibling, 7);
  cr_assert_eq(degree, 0);
  cr_assert_eq(depth, 3);
  cr_assert_eq(height, 0);
}
