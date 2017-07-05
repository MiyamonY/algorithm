///
// File:  test_partition.cpp
// Author: ymiyamoto
//
// Created on Tue Jul  4 23:56:47 2017
//

#include <cstdint>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

TestSuite(Partition);

Test(Partition, Part)
{
  vector<uint32_t> vec{
      4, 5, 67, 1, 3, 532, 234, 45, 2, 32,
  };

  vector<uint32_t> expect{
      1, 2, 3, 4, 5, 32, 45, 67, 234, 532,
  };
  cr_assert_eq(partition(&vec[0], 0, vec.size() - 1), 5);
  cr_assert_eq(vec, expect);
}
