///
// File:  test_linear_search.cpp
// Author: ymiyamoto
//
// Created on Sat Jul  1 21:26:45 2017
//

#include <cstdint>
#include <stdexcept>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

TestSuite(LinearSearch);

Test(LinearSeach, SearchFound)
{
  vector<uint32_t> s{1, 5, 9, 13};
  vector<uint32_t> t{1, 9};

  cr_assert_eq(linear_search(&s[0], s.size(), &t[0], t.size()), 2);
}

Test(LinearSeach, WhenArraySizeIs0)
{
  vector<uint32_t> s{1};
  vector<uint32_t> t{1};

  cr_assert_eq(linear_search(&s[0], s.size(), &t[0], 0), 0);
  cr_assert_eq(linear_search(&s[0], 0, &t[0], t.size()), 0);
}

Test(LinearSeach, CheckArgument)
{
  vector<uint32_t> s{1};
  vector<uint32_t> t{1};

  cr_assert_throw(linear_search(nullptr, s.size(), &t[0], t.size()), exception);
  cr_assert_throw(linear_search(&s[0], s.size(), nullptr, t.size()), exception);
}
