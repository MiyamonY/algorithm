/**
 * File:  test_stable.c
 * Author: ymiyamoto
 *
 * Created on Wed Apr 26 09:17:34 2017
 */

#include <criterion/criterion.h>
#include <stdint.h>

#include "problems.h"
#include "util.h"

/* TODO
 * - ソート
 *   バッファがNULLでも落ちない.出力は0. ok
 *   サイズが0の場合は,ソートされず出力は0. ok
 *   ソートされている場合はそのままで出力は0 ok
 *   一つだけひっくりかえっている場合はソートされ，出力は0
 *   全部ひっくりかえっている場合はソートされ，出力はバブル15, selection 3(len(buf)==3)
 * - 安定かどうか
 *   いずれかのバッファがNULLの場合はfalse
 *   サイズが異なる場合はNULL
 *   同じ配列はStable
 *   一つひっくりかえした配列はunstable
 */

static const char *testval1[] = {"A1", "B2", "C3", "D4", "E5", "F6"};

static char **expected;
static size_t expected_size;

static void set_expected(const char **buf, const size_t size)
{
  expected = (char **)buf;
  expected_size = size;
}

static int32_t comp_data(char **a, char **b)
{
  if ((a[0] == b[0]) && (a[1] == b[1])) {
    return 0;
  }
  return 1;
}

static void assert_bubble_sorted(char **buf, size_t size, size_t count)
{
  uint32_t cnt = stable_bubble_sort(buf, size);
  cr_assert_arr_eq_cmp(buf, expected, expected_size, comp_data);
  cr_assert_eq(cnt, count);
}

static void assert_selection_sorted(char **buf, size_t size, size_t count)
{
  uint32_t cnt = stable_selection_sort(buf, size);
  cr_assert_arr_eq(buf, expected, expected_size);
  cr_assert_eq(cnt, count);
}

void setup(void)
{
  set_expected(testval1, sizeof(testval1));
}

Test(stable_sort, sort_array_is_null)
{
  uint32_t count1 = stable_bubble_sort(NULL, 1);
  cr_assert_eq(count1, 0);

  uint32_t count2 = stable_selection_sort(NULL, 1);
  cr_assert_eq(count2, 0);
}

Test(stable_sort, sort_size_is_0)
{
  char *buf[] = {"A1", "B2", "C3", "D4", "E5", "F6"};
  assert_bubble_sorted(buf, 0, 0);
  assert_selection_sorted(buf, 0, 0);
}

Test(stable_sort, sort_exchanged1)
{
  char *test1[] = {"B2", "A1", "C3", "D4", "E5", "F6"};
  assert_bubble_sorted(test1, UTIL_ARRAY_SIZE(test1), 1);

  char *test2[] = {"B2", "A1", "C3", "D4", "E5", "F6"};
  assert_selection_sorted(test2, UTIL_ARRAY_SIZE(test2), 1);
}

Test(stable_sort, descendant)
{
  char *test1[] = {"F6", "E5", "D4", "C3", "B2", "A1"};
  assert_bubble_sorted(test1, UTIL_ARRAY_SIZE(test1), 15);

  char *test2[] = {"F6", "E5", "D4", "C3", "B2", "A1"};
  assert_selection_sorted(test2, UTIL_ARRAY_SIZE(test2), 3);
}
