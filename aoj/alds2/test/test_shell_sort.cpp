///
// File:  test_shell_sort.cpp
// Author: ymiyamoto
//
// Created on Thu Jun 29 09:32:37 2017
//

#include <cstdint>
#include <stdexcept>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

static uint32_t cnt = 0;

static void callback(int32_t array[], uint32_t index, uint32_t index2)
{
  cnt++;
}

TestSuite(ShellSort);

Test(ShellSort, ArraySizeIs1)
{
  vector<int32_t> vec{1};

  shell_sort(&vec[0], vec.size(), nullptr);

  const vector<int32_t> expect{1};
  cr_assert_eq(vec, expect);
}

Test(ShellSort, ArraySizeIsN)
{
  vector<int32_t> vec{9, 2, 3, 5, 6, 7, 1, 1, 8, 9};

  shell_sort(&vec[0], vec.size(), callback);

  const vector<int32_t> expect{1, 1, 2, 3, 5, 6, 7, 8, 9, 9};
  cr_assert_eq(vec, expect);
}

Test(ShellSort, ArgumentError)
{
  vector<int32_t> vec{9, 2, 3, 5, 6, 7, 1, 1, 8, 9};

  cr_assert_throw(shell_sort(nullptr, 5, callback), exception);
  cr_assert_throw(shell_sort(&vec[0], 0, callback), exception);
}
