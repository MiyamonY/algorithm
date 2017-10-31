///
// File:  cgl_2_a.cpp
// Author: ymiyamoto
//
// Created on Sun Oct 22 18:40:44 2017
//

#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

struct point_t {
  double x;
  double y;
};

struct vector_t {
  double x;
  double y;

  vector_t(point_t a) : x(a.x), y(a.y)
  {
  }

  vector_t(point_t a, point_t b) : x(a.x - b.x), y(a.y - b.y)
  {
  }

  double dot(const vector_t &b)
  {
    return x * b.x + y * b.y;
  }

  double cross(const vector_t &b)
  {
    return x * b.y - y * b.x;
  }
};

struct line_t {
  point_t a;
  point_t b;

  line_t(point_t a, point_t b) : a(a), b(b)
  {
  }

  vector_t vector()
  {
    return vector_t(a, b);
  }

  double dot(line_t &l)
  {
    return vector().dot(l.vector());
  }

  double cross(line_t &l)
  {
    return vector().cross(l.vector());
  }
};

#define EPS (1e-10)
#define equals(x, y) (fabs(x - y) < EPS)

int32_t main()
{
  uint32_t q;
  cin >> q;

  for (uint32_t i = 0; i < q; i++) {
    double x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    line_t l1 = line_t(point_t({x0, y0}), point_t({x1, y1}));
    cin >> x0 >> y0 >> x1 >> y1;
    line_t l2 = line_t(point_t({x0, y0}), point_t({x1, y1}));
    if (equals(l1.dot(l2), 0.0)) {
      cout << 1 << endl;
    } else if (equals(l1.cross(l2), 0.0)) {
      cout << 2 << endl;
    } else {
      cout << 0 << endl;
    }
  }

  return 0;
}
