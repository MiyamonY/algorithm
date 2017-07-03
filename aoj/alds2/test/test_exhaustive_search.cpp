///
// File:  test_exhaustive_search.cpp
// Author: ymiyamoto
//
// Created on Mon Jul  3 22:54:45 2017
//

#include <cstdint>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

TestSuite(ExaustiveSearch);

Test(ExaustiveSearch, SearchFound)
{
  vector<uint32_t> vec{1, 3, 4, 5, 6, 2};

  cr_assert(exausitve_search_search(vec, 2));
  cr_assert(exausitve_search_search(vec, 10));
  cr_assert(exausitve_search_search(vec, 21));
}

Test(ExaustiveSearch, SearchNotFound)
{
  vector<uint32_t> vec{1, 3, 4, 5, 6, 2};

  cr_assert_not(exausitve_search_search(vec, 22));
  cr_assert_not(exausitve_search_search(vec, 23));
}
