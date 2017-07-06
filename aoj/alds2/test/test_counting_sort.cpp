///
// File:  test_counting_sort.cpp
// Author: ymiyamoto
//
// Created on Thu Jul  6 22:38:55 2017
//

#include <cstdint>
#include <vector>

#include "problems.hpp"

#include <criterion/criterion.h>

using namespace std;

TestSuite(CountingSort);

Test(CountingSort, Sort)
{
  vector<uint32_t> vec{
      0, 2, 324, 122, 34, 32, 234, 234, 2, 34, 5, 32, 3,
  };

  vector<uint32_t> result{
      0, 2, 324, 122, 34, 32, 234, 234, 2, 34, 5, 32, 3,
  };
  counting_sort_sort(&vec[0], vec.size(), &result[0]);

  const vector<uint32_t> expect{
      0, 2, 2, 3, 5, 32, 32, 34, 34, 122, 234, 234, 324,
  };
  cr_assert_eq(result, expect);
}
