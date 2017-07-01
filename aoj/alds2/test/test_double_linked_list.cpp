///
// File:  test_double_linked_list.cpp
// Author: ymiyamoto
//
// Created on Fri Jun 30 08:18:51 2017
//

#include <cstdint>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

vector<uint32_t> vals;

static void callback(uint32_t val)
{
  vals.push_back(val);
}

static double_linked_list_t *list;

static void setup()
{
  vals.clear();
  list = double_linked_list_create();
}

static void teardown()
{
  double_linked_list_destroy(list);
}

TestSuite(DoubleLinkedList, .init = setup, .fini = teardown);

Test(DoubleLinkedList, Insert)
{
  const vector<uint32_t> expect{1, 3, 2};

  for (int32_t i = expect.size() - 1; i >= 0; i--) {
    double_linked_list_insert(list, expect[i]);
  }
  double_linked_list_iter(list, callback);

  cr_assert_eq(vals, expect);
}

Test(DoubleLinkedList, Delete)
{
  double_linked_list_insert(list, 2);
  double_linked_list_insert(list, 3);
  double_linked_list_insert(list, 1);
  double_linked_list_delete(list, 3);
  double_linked_list_delete(list, 1);
  double_linked_list_delete(list, 2);

  double_linked_list_iter(list, callback);

  cr_assert_eq(vals.size(), 0);
}

Test(DoubleLinkedList, DeleteFirst)
{
  const vector<uint32_t> expect{1, 5};

  double_linked_list_insert(list, 2);
  double_linked_list_insert(list, 3);
  double_linked_list_delete_first(list);
  double_linked_list_delete_first(list);
  double_linked_list_insert(list, 5);
  double_linked_list_insert(list, 1);

  double_linked_list_iter(list, callback);

  cr_assert_eq(vals, expect);
}

Test(DoubleLinkedList, DeleteFirstWhenListIsEmpty)
{
  double_linked_list_delete_first(list);
  double_linked_list_iter(list, callback);

  cr_assert_eq(vals.size(), 0);
}

Test(DoubleLinkedList, DeleteLast)
{
  const vector<uint32_t> expect{1, 5};
  double_linked_list_insert(list, 2);
  double_linked_list_insert(list, 3);
  double_linked_list_delete_last(list);
  double_linked_list_delete_last(list);
  double_linked_list_insert(list, 5);
  double_linked_list_insert(list, 1);

  double_linked_list_iter(list, callback);

  cr_assert_eq(vals, expect);
}

Test(DoubleLinkedList, DeleteLastWhenListIsEmpty)
{
  double_linked_list_delete_last(list);
  double_linked_list_iter(list, callback);

  cr_assert_eq(vals.size(), 0);
}
