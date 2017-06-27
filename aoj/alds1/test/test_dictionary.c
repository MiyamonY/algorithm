/**
 * File:  test_dictionary.c
 * Author: ymiyamoto
 *
 * Created on Mon May  8 01:20:03 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

static dictionary_t dict = NULL;

static void insert_data(uint64_t data[], size_t size)
{
  for (int32_t i = 0; i < size; i++) {
    cr_assert(dictionary_insert(dict, data[i]));
  }

  return;
}

static void setup(void)
{
  dict = dictionary_create(3);
}

TestSuite(Dictionary, .init = setup);

Test(Dictionary, DictionaryCreate)
{
  cr_assert_not_null(dict);
}

Test(Dictionary, DictionaryDestory)
{
  dictionary_destroy(dict);
}

Test(Dictionary, DictionaryInsertWhenDictIsEmpty)
{
  cr_assert(dictionary_insert(dict, 3));
}

Test(Dictionary, DictionarySearchNotFoundWhenDictIsEmpty)
{
  cr_assert_not(dictionary_search(dict, 3));
}

Test(Dictionary, DictionaryInsertErrorWhenDictIsFull)
{
  uint64_t data[] = {3, 4, 5};
  insert_data(data, UTIL_ARRAY_SIZE(data));
  cr_assert_not(dictionary_insert(dict, 6));
}

Test(Dictionary, DictionarySearchNotFoundWhenDictIsFull)
{
  uint64_t data[] = {3, 4, 5};
  insert_data(data, UTIL_ARRAY_SIZE(data));
  cr_assert_not(dictionary_search(dict, 6));
}

Test(Dictionary, DictionarySearchFound)
{
  uint64_t data[] = {30, 42, 41};

  insert_data(data, UTIL_ARRAY_SIZE(data));
  cr_assert(dictionary_search(dict, 41));
  cr_assert(dictionary_search(dict, 30));
  cr_assert(dictionary_search(dict, 42));
}

static void setup2(void)
{
  dict = dictionary_create(11);
}

static void teardown(void)
{
  dict = dictionary_create(11);
}

TestSuite(Dictionary2, .init = setup2, .fini = teardown);

Test(Dictionary2, DictionarySearchRandomTest)
{
  uint64_t data[] = {3, 20, 9};

  insert_data(data, UTIL_ARRAY_SIZE(data));
  cr_assert(dictionary_search(dict, 20));
  cr_assert_not(dictionary_search(dict, 8));
  cr_assert(dictionary_insert(dict, 8));
  cr_assert(dictionary_search(dict, 8));
  cr_assert(dictionary_search(dict, 9));
  cr_assert(dictionary_search(dict, 20));
  cr_assert(dictionary_search(dict, 3));
}

Test(Dictionary2, DictionarySearchRandomTest2)
{
  uint64_t data[] = {11, 132, 242, 352, 462};

  insert_data(data, UTIL_ARRAY_SIZE(data));
  cr_assert(dictionary_search(dict, 11));
  cr_assert(dictionary_search(dict, 132));
  cr_assert(dictionary_search(dict, 242));
  cr_assert(dictionary_search(dict, 352));
  cr_assert(dictionary_search(dict, 462));
}
