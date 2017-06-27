/**
 * File:  test_depth_first_search.c
 * Author: ymiyamoto
 *
 * Created on Wed Jun 21 10:08:36 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"

static uint32_t called;

static void callback(uint32_t val)
{
  called++;
}

static void setup(void)
{
  called = 0x00;
}

TestSuite(DepthFirstSearch, .init = setup);

Test(DepthFirstSearch, ShouldNotCallCallbackFunc)
{
  graph_depth_first_search(NULL, callback);
  cr_assert_eq(called, 0);
}
