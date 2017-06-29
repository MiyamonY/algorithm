/**
 * File:  test_stable_sort.c
 * Author: ymiyamoto
 *
 * Created on Thu Jun 29 08:20:43 2017
 */

#include <cstdint>
#include <stdexcept>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

TestSuite(StableSort);

Test(StableSort, BubbleSort)
{
  vector<pair<int32_t, uint8_t>> vec{{3, 'D'}, {2, 'C'}, {2, 'D'}, {1, 'A'}};
  stable_sort_bubble_sort(&vec[0], vec.size());

  const vector<pair<int32_t, uint8_t>> expect{{1, 'A'}, {2, 'C'}, {2, 'D'}, {3, 'D'}};
  cr_assert(vec == expect);
}

Test(StableSort, BubbleSortArgumentError)
{
  vector<pair<int32_t, uint8_t>> vec{{3, 'D'}};

  cr_assert_throw(stable_sort_bubble_sort(nullptr, 5), exception);
  cr_assert_throw(stable_sort_bubble_sort(&vec[0], 0), exception);
}

Test(StableSort, SelectionSort)
{
  vector<pair<int32_t, uint8_t>> vec{{3, 'D'}, {2, 'C'}, {2, 'D'}, {1, 'A'}};
  stable_sort_selection_sort(&vec[0], vec.size());

  const vector<pair<int32_t, uint8_t>> expect{{1, 'A'}, {2, 'C'}, {2, 'D'}, {3, 'D'}};
  cr_assert(vec == expect);
}

Test(StableSort, SelectionSortArgumentError)
{
  vector<pair<int32_t, uint8_t>> vec{{3, 'D'}};

  cr_assert_throw(stable_sort_selection_sort(nullptr, 5), exception);
  cr_assert_throw(stable_sort_selection_sort(&vec[0], 0), exception);
}

Test(StableSort, IsStable)
{
  vector<pair<int32_t, uint8_t>> vec{{4, 'H'}, {9, 'C'}, {4, 'S'}, {2, 'D'}, {3, 'C'}};
  vector<pair<int32_t, uint8_t>> vec2{{4, 'H'}, {9, 'C'}, {4, 'S'}, {2, 'D'}, {3, 'C'}};

  stable_sort_bubble_sort(&vec[0], vec.size());
  stable_sort_selection_sort(&vec2[0], vec.size());

  cr_assert(vec != vec2);
}
