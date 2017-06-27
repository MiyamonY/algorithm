/**
 * File:  test_tree_walk.c
 * Author: ymiyamoto
 *
 * Created on Sat May 27 02:44:31 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

static binary_tree_id_t buffer[10];
static size_t count = 0;

static void callback(binary_tree_id_t id)
{
  buffer[count] = id;
  count++;
}

binary_tree_t t;
void setup_tree_walk_none(void)
{
  t = binary_tree_create(10);
}

void teardown_tree_walk_none(void)
{
  binary_tree_destroy(t);
}

TestSuite(TreeWalkNone, .init = setup_tree_walk_none, .fini = teardown_tree_walk_none);

Test(TreeWalkNone, Preorder)
{
  size_t len = binary_tree_preorder(t, callback);
  cr_assert_eq(len, 0);
}

Test(TreeWalkNone, Inorder)
{
  binary_tree_id_t data[10];

  size_t len = binary_tree_inorder(t, callback);
  cr_assert_eq(len, 0);
}

Test(TreeWalkNone, Postoder)
{
  size_t len = binary_tree_postorder(t, callback);
  cr_assert_eq(len, 0);
}

void setup_tree_walk_only_top(void)
{
  t = binary_tree_create(10);
  binary_tree_insert(t, 0, BINARY_TREE_ID_NULL, BINARY_TREE_ID_NULL);
}

void teardown_tree_walk_only_top(void)
{
  binary_tree_destroy(t);
}

TestSuite(TreeWalkOnlyTop, .init = setup_tree_walk_only_top, .fini = teardown_tree_walk_only_top);

Test(TreeWalkOnlyTop, Preorder)
{
  const binary_tree_id_t expect[] = {0};

  size_t len = binary_tree_preorder(t, callback);
  cr_assert_eq(len, UTIL_ARRAY_SIZE(expect));
  cr_assert_arr_eq(buffer, expect, sizeof(binary_tree_id_t) * len);
}

Test(TreeWalkOnlyTop, Inorder)
{
  const binary_tree_id_t expect[] = {0};

  size_t len = binary_tree_inorder(t, callback);
  cr_assert_eq(len, 1);
  cr_assert_arr_eq(buffer, expect, sizeof(binary_tree_id_t) * len);
}

Test(TreeWalkOnlyTop, Postorder)
{
  const binary_tree_id_t expect[] = {0};

  size_t len = binary_tree_postorder(t, callback);
  cr_assert_eq(len, 1);
  cr_assert_arr_eq(buffer, expect, sizeof(binary_tree_id_t) * len);
}

void setup_tree_walk_has_many_nodes(void)
{
  t = binary_tree_create(10);

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

void teardown_tree_walk_has_many_nodes(void)
{
  binary_tree_destroy(t);
}

TestSuite(TreeWalkHasManyNodes, .init = setup_tree_walk_has_many_nodes, .fini = teardown_tree_walk_has_many_nodes);

Test(TreeWalkHasManyNodes, Preorder)
{
  const binary_tree_id_t expect[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

  size_t len = binary_tree_preorder(t, callback);
  cr_assert_eq(len, 9);
  cr_assert_arr_eq(buffer, expect, sizeof(binary_tree_id_t) * len);
}

Test(TreeWalkHasManyNodes, Inorder)
{
  const binary_tree_id_t expect[] = {2, 1, 3, 0, 6, 5, 7, 4, 8};

  size_t len = binary_tree_inorder(t, callback);
  cr_assert_eq(len, UTIL_ARRAY_SIZE(expect));
  cr_assert_arr_eq(buffer, expect, sizeof(binary_tree_id_t) * len);
}

Test(TreeWalkHasManyNodes, Postorder)
{
  const binary_tree_id_t expect[] = {2, 3, 1, 6, 7, 5, 8, 4, 0};

  size_t len = binary_tree_postorder(t, callback);
  cr_assert_eq(len, UTIL_ARRAY_SIZE(expect));
  cr_assert_arr_eq(buffer, expect, sizeof(binary_tree_id_t) * len);
}
