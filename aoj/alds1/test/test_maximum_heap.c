/**
 * File:  test_maximum_heap.c
 * Author: ymiyamoto
 *
 * Created on Thu Jun  8 03:15:14 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"
#include "util.h"

#define ASSERT_MAXIMUM_HEAP_BUILD(expect, heap)                                                                                            \
  maximum_heap_build(heap, UTIL_ARRAY_SIZE(heap));                                                                                         \
  cr_assert_arr_eq(heap, expect, UTIL_ARRAY_SIZE(expect));

TestSuite(MximumHeap);

Test(MaximumHeap, HeapIsSameWhenHeapSizeIs0)
{
  const int64_t expect[] = {1, 2, 3};
  int64_t heap[] = {1, 2, 3};

  maximum_heap_build(heap, 0);
  cr_assert_arr_eq(heap, expect, UTIL_ARRAY_SIZE(expect));
}

Test(MaximumHeap, HeapIsSameWhenHeapIsMaximized)
{
  const int64_t expect[] = {6, 5, 3, 2};
  int64_t heap[] = {6, 5, 3, 2};

  ASSERT_MAXIMUM_HEAP_BUILD(expect, heap);
}

Test(MaximumHeap, HeapIsMaximizedWhenHeapSizeIs2)
{
  const int64_t expect[] = {6, 3};
  int64_t heap[] = {3, 6};

  ASSERT_MAXIMUM_HEAP_BUILD(expect, heap);
}

Test(MaximumHeap, HeapIsMaximizedWhenAnyHeapSize)
{
  const int64_t expect[] = {6, 5, 3, 2};
  int64_t heap[] = {3, 2, 6, 5};

  ASSERT_MAXIMUM_HEAP_BUILD(expect, heap);
}
