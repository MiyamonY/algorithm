///
// File:  test_areas_on_cross_section_diagram.cpp
// Author: ymiyamoto
//
// Created on Sat Jul  1 09:03:23 2017
//

#include <cstdint>
#include <vector>

#include <criterion/criterion.h>

#include "problems.hpp"
using namespace std;

static uint32_t cnt;

static void callback(size_t size)
{
  cnt++;
}

static void setup(void)
{
  areas_on_cross_section_diagram_init();
  cnt = 0;
}

TestSuite(AreasOnCrossSectionDiagram, .init = setup);

static void add_chars(vector<char> &chars)
{
  for (uint32_t i = 0; i < chars.size(); i++) {
    areas_on_cross_section_diagram_add(chars[i]);
  }
}

Test(AreasOnCrossSectionDiagram, NoArea)
{
  vector<char> chars{'\\', '_', '_'};

  add_chars(chars);
  size_t total = areas_on_cross_section_diagram_total();
  areas_on_cross_section_diagram_areas(callback);

  cr_assert_eq(total, 0);
  cr_assert_eq(cnt, 0);
}

Test(AreasOnCrossSectionDiagram, SamallArea)
{
  vector<char> chars{'\\', '_', '/'};

  add_chars(chars);

  size_t total = areas_on_cross_section_diagram_total();
  areas_on_cross_section_diagram_areas(callback);

  cr_assert_eq(total, 2);
  cr_assert_eq(cnt, 1);
}

Test(AreasOnCrossSectionDiagram, SeparateAreas)
{
  vector<char> chars{'\\', '_', '/', '/', '\\', '/', '\\', '\\', '/', '\\', '/', '/'};

  add_chars(chars);

  size_t total = areas_on_cross_section_diagram_total();
  areas_on_cross_section_diagram_areas(callback);

  cr_assert_eq(total, 10);
  cr_assert_eq(cnt, 3);
}
