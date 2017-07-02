///
// File:  test_dictionary.cpp
// Author: ymiyamoto
//
// Created on Sun Jul  2 10:21:16 2017
//

#include <cstdint>
#include <string>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

static void setup()
{
  dictionary_init();
}

TestSuite(Dictionary, .init = setup);

Test(Dictionary, InsertFound)
{
  vector<string> vals{"AAAA", "GGGG", "CCCC", "AAAT"};

  for (uint32_t i = 0; i < vals.size(); i++) {
    dictionary_insert((char *)vals[i].c_str());
  }

  cr_assert(dictionary_find((char *)"AAAA"));
  cr_assert(dictionary_find((char *)"CCCC"));
  cr_assert(dictionary_find((char *)"AAAT"));
}

Test(Dictionary, InsertNotFound)
{
  vector<string> vals{"AAAA", "GGGG", "CCCC", "AAAT", "CGAAGCGGG", "CCGAAGCGGGG"};

  for (uint32_t i = 0; i < vals.size(); i++) {
    dictionary_insert((char *)vals[i].c_str());
  }

  cr_assert_not(dictionary_find((char *)"AAAC"));
  cr_assert_not(dictionary_find((char *)"GGGGG"));
  cr_assert_not(dictionary_find((char *)"GGG"));
  cr_assert_not(dictionary_find((char *)"CGAAGCGGGG"));
}
