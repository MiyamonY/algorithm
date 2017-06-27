/**
 * File:  test_koch_curve.c
 * Author: ymiyamoto
 *
 * Created on Thu May 11 11:48:03 2017
 */

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#include <criterion/criterion.h>

#include "problems.h"

#define PI 3.14159265

static void assert_point(point_t actual, point_t expect)
{
  cr_assert_float_eq(actual.x, expect.x, 0.0001, "expcet %.8f, actual %.8f", actual.x, expect.x);
  cr_assert_float_eq(actual.y, expect.y, 0.0001);
}

static point_t calc_internally_dividing(point_t a, point_t b, int32_t n, int32_t m)
{
  point_t ret = {.x = (n * a.x + m * b.x) / (n + m), .y = (n * a.y + m * b.y) / (n + m)};
  return ret;
}

static point_t add_vector(point_t vec1, point_t vec2)
{
  point_t ret = {.x = vec1.x + vec2.x, .y = vec1.y + vec2.y};
  return ret;
}

static point_t sub_vector(point_t vec1, point_t vec2)
{
  point_t ret = {.x = vec1.x - vec2.x, .y = vec1.y - vec2.y};
  return ret;
}

static point_t rotate_vector(point_t vec, double rad)
{
  point_t ret = {.x = vec.x * cos(rad) - vec.y * sin(rad), .y = vec.x * sin(rad) + vec.y * cos(rad)};
  return ret;
}

const point_t a = {.x = 0.0, .y = 0.0};
const point_t b = {.x = 0.0, .y = 100.0};

Test(KochCurve, Divide0)
{
  point_t buf[2];
  size_t ret = koch_curve(0, a, b, buf);
  cr_assert_eq(ret, 2);
  assert_point(buf[0], a);
  assert_point(buf[1], b);
}

Test(KochCurve, Divide1)
{
  point_t buf[5];
  size_t ret = koch_curve(1, a, b, buf);

  point_t s = calc_internally_dividing(a, b, 2, 1);
  point_t t = calc_internally_dividing(a, b, 1, 2);

  point_t u = add_vector(rotate_vector(sub_vector(t, s), PI / 3), s);

  cr_assert_eq(ret, 5);
  assert_point(buf[0], a);
  assert_point(buf[1], s);
  assert_point(buf[2], u);
  assert_point(buf[3], t);
  assert_point(buf[4], b);
}
