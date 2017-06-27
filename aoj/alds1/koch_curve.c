/**
 * File:  koch_curve.c
 * Author: ymiyamoto
 *
 * Created on Thu May 11 13:48:40 2017
 */

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "problems.h"

#define PI 3.14159265

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

static void koch_curve_aux(point_t a, point_t b, point_t data[])
{
  point_t s = calc_internally_dividing(a, b, 2, 1);
  point_t t = calc_internally_dividing(a, b, 1, 2);
  point_t u = add_vector(rotate_vector(sub_vector(t, s), PI / 3), s);

  data[0] = a;
  data[1] = s;
  data[2] = u;
  data[3] = t;
  data[4] = b;
}

size_t koch_curve(uint32_t n, point_t a, point_t b, point_t data[])
{
  size_t len = ((int)pow(4, n)) + 1;

  if (n == 0) {
    data[0] = a;
    data[1] = b;
  } else {
    int32_t data_size = koch_curve(n - 1, a, b, data);
    point_t *tmpbuf = (point_t *)malloc(sizeof(point_t) * len);
    int32_t i;
    for (i = 0; i < (data_size - 1); i++) {
      point_t buf[5];
      koch_curve_aux(data[i], data[i + 1], buf);
      tmpbuf[4 * i] = buf[0];
      tmpbuf[4 * i + 1] = buf[1];
      tmpbuf[4 * i + 2] = buf[2];
      tmpbuf[4 * i + 3] = buf[3];
      tmpbuf[4 * i + 4] = buf[4];
    }
    memcpy(data, tmpbuf, sizeof(point_t) * len);
    free(tmpbuf);
  }

  return len;
}

#if !defined(TEST)
static point_t buf[4096];

static void print_point(point_t a)
{
  printf("%.8f %.8f\n", a.x, a.y);
}

int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);
  const point_t a = {.x = 0.0, .y = 0.0};
  const point_t b = {.x = 100.0, .y = 0.0};

  size_t len = koch_curve(num, a, b, buf);
  uint32_t i;
  for (i = 0; i < len; i++) {
    print_point(buf[i]);
  }

  return 0;
}

#endif
