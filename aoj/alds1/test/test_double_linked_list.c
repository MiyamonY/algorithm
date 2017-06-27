/**
 * File:  test_double_linked_list.c
 * Author: ymiyamoto
 *
 * Created on Tue May  2 01:53:10 2017
 */

#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

static double_linked_list_t *l;

static void setup(void)
{
  l = double_linked_list_create();
}

static void teardown(void)
{
  double_linked_list_destroy(l);
}

static void assert_insert_data(int32_t buf[], size_t size)
{
  for (int32_t i = 0; i < size; i++) {
    cr_assert(double_linked_list_insert(l, buf[i]));
  }
}

static void assert_list_to_array(size_t len, int32_t expect[], size_t buf_size)
{
  int32_t buf[128] = {
      0,
  };

  size_t size = double_linked_list_to_array(l, buf, UTIL_ARRAY_SIZE(buf));
  cr_assert_eq(size, len);

  cr_assert_arr_eq(buf, expect, sizeof(int32_t) * buf_size);
}

/* static void insert_data_to_list(int32_t buf[], size_t size) */
/* { */
/*   for (int32_t i = 0; i < size; i++) { */
/*     cr_assert(double_linked_list_insert(l, buf[i])); */
/*   } */
/* } */

TestSuite(DoubleLinkedList, .init = setup, .fini = teardown);

/* - linklistが生成できる ok
   - linklistが削除できる ok
   - insertできる． ok
   - insertした後に取得するとinsertした値が取得できる(toArray) ok
     - toArrayで配列サイズが0 ok
     - toArrayで配列に値が取得できる ok
     - toArrayにサイズが小さいバッファを渡す ok
     - バッファがNULLを渡す ok
   - 空の時にdeleteしても削除できない ok
   - insertした後にその要素に対しdeleteできるサイズは-1．その後取得していたら削除されている ok
   - delete xしてもxがlistにない場合は成功しない(return false) ok
   - insertしてdeleteFirstで先頭の要素が削除できる ok
   - 空のlistにしてdeleteFirstは失敗する ok
   - insertしてdeleteFirstは成功し，取得したら空 ok

   - insert*3してdeleteFirstは成功し，取得したら先頭の要素が削除されている
   - insertしてdeleteLastは成功し，取得したら空
   - 空のlistにしてdeleteLastは失敗する
   - insert*3してdeleteLastは成功し，取得したら最後の要素が削除されている
   - NULLが渡されたたときもクラッシュしない
 */

Test(DoubleLinkedList, InsertDoubleLinkedList)
{
  int32_t data[] = {3, 4};
  assert_insert_data(data, UTIL_ARRAY_SIZE(data));
}

Test(DoubleLinkedList, ConvertListToArrayWhoseSizeIs0)
{
  bool ret = double_linked_list_insert(l, 5);
  cr_assert(ret);

  int32_t buf[10];
  size_t size = double_linked_list_to_array(l, buf, 0);
  cr_assert_eq(size, 0);
}

Test(DoubleLinkedList, ConvertListToArrayWhenListIsEmpty)
{
  int32_t buf[10];
  size_t size = double_linked_list_to_array(l, buf, UTIL_ARRAY_SIZE(buf));
  cr_assert_eq(size, 0);
}

Test(DoubleLinkedList, ConvertListToArray)
{
  int32_t data[] = {5, 6, 7, 8, 9};
  assert_insert_data(data, UTIL_ARRAY_SIZE(data));

  int32_t expect[10] = {
      9, 8, 7, 6, 5, 0,
  };

  assert_list_to_array(UTIL_ARRAY_SIZE(data), expect, UTIL_ARRAY_SIZE(expect));
}

Test(DoubleLinkedList, ConvertListToArrayBufferSizeIsSmall)
{
  int32_t data[] = {1, 2, 3};
  assert_insert_data(data, UTIL_ARRAY_SIZE(data));

  int32_t buf[2] = {
      0,
  };

  size_t size = double_linked_list_to_array(l, buf, UTIL_ARRAY_SIZE(buf));
  cr_assert_eq(size, 2);

  int32_t expect[2] = {3, 2};
  cr_assert_arr_eq(buf, expect, sizeof(expect));
}

Test(DoubleLinkedList, ConvertListToArrayBufferIsNULL)
{
  int32_t data[] = {1, 2, 3};
  assert_insert_data(data, UTIL_ARRAY_SIZE(data));

  size_t size = double_linked_list_to_array(l, NULL, 3);
  cr_assert_eq(size, 0);
}

Test(DoubleLinkedList, DeleteListWhenListIsEmpty)
{
  cr_assert_not(double_linked_list_delete(l, 1));
}

Test(DoubleLinkedList, DeleteListWhenNotFound)
{
  int32_t data[] = {1, 2, 3};
  assert_insert_data(data, UTIL_ARRAY_SIZE(data));

  cr_assert_not(double_linked_list_delete(l, 5));
}

Test(DoubleLinkedList, DeleteLists)
{
  int32_t data[] = {1, 2, 3};
  assert_insert_data(data, UTIL_ARRAY_SIZE(data));

  cr_assert(double_linked_list_delete(l, 2));

  int32_t expect[] = {3, 1};
  assert_list_to_array(UTIL_ARRAY_SIZE(expect), expect, UTIL_ARRAY_SIZE(expect));
}

Test(DoubleLinkedList, DeleteFirstFailWhenListIsEmpty)
{
  cr_assert_not(double_linked_list_delete_first(l));
}

Test(DoubleLinkedList, DeleteFirstSuccessWhenListHasOneElement)
{
  int32_t data[] = {1};
  assert_insert_data(data, UTIL_ARRAY_SIZE(data));
  cr_assert(double_linked_list_delete_first(l));

  int32_t expect[10];
  cr_assert_not(double_linked_list_to_array(l, expect, UTIL_ARRAY_SIZE(expect)));
}

Test(DoubleLinkedList, DeleteFirstSuccessWhenListHasManyElements)
{
  int32_t data[] = {1, 2, 3};
  assert_insert_data(data, UTIL_ARRAY_SIZE(data));
  cr_assert(double_linked_list_delete_first(l));

  int32_t expect[] = {2, 1};
  assert_list_to_array(UTIL_ARRAY_SIZE(expect), expect, UTIL_ARRAY_SIZE(expect));
}

Test(DoubleLinkedList, DeleteLastWhenListIsEmpty)
{
  cr_assert_not(double_linked_list_delete_last(l));
}

Test(DoubleLinkedList, DeleteLastSuccessWhenListHasManyElement)
{
  int32_t data[] = {1};
  assert_insert_data(data, UTIL_ARRAY_SIZE(data));
  cr_assert(double_linked_list_delete_last(l));

  int32_t expect[10];
  cr_assert_not(double_linked_list_to_array(l, expect, UTIL_ARRAY_SIZE(expect)));
}

Test(DoubleLinkedList, DeleteLastSuccessWhenListHasManyElements)
{
  int32_t data[] = {1, 2, 3};
  assert_insert_data(data, UTIL_ARRAY_SIZE(data));
  cr_assert(double_linked_list_delete_last(l));

  int32_t expect[] = {3, 2};
  assert_list_to_array(UTIL_ARRAY_SIZE(expect), expect, UTIL_ARRAY_SIZE(expect));
}

Test(DoubleLinkedList, DoubleLinkedListFunctionDontCrash)
{
  double_linked_list_destroy(NULL);
  cr_assert_not(double_linked_list_insert(NULL, 3));
  int32_t buf[10];
  cr_assert_eq(double_linked_list_to_array(NULL, buf, UTIL_ARRAY_SIZE(buf)), 0);
  cr_assert_not(double_linked_list_delete(NULL, 3));
  cr_assert_not(double_linked_list_delete_first(NULL));
  cr_assert_not(double_linked_list_delete_last(NULL));
}
