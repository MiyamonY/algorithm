///
// File:  cgl_1_b.cpp
// Author: ymiyamoto
//
// Created on Sun Oct 22 19:02:33 2017
//

#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace std;

struct vector_t {
  double x;
  double y;

  vector_t(double a, double b) : x(a), y(b)
  {
  }

  double norm2()
  {
    return x * x + y * y;
  }

  double cross(vector_t a)
  {
    return x * a.x + y * a.y;
  }

  vector_t operator*(double a)
  {
    return vector_t(a * x, a * y);
  }
};

struct point_t {
  double x;
  double y;

  point_t operator+(const point_t a)
  {
    return point_t({x + a.x, y + a.y});
  }

  void print()
  {
    cout << fixed << setprecision(10) << x << " " << y << endl;
  }

  point_t operator+(const vector_t vec)
  {
    return point_t({x + vec.x, y + vec.y});
  }

  vector_t operator-(const point_t p)
  {
    return vector_t({x - p.x, y - p.y});
  }

  point_t project(point_t p1, point_t p2)
  {
    vector_t vec1(x - p1.x, y - p1.y);
    vector_t vec2(p2.x - x, p2.y - y);
    return point_t({x, y}) + vec1 * (vec1.cross(vec2) / vec1.norm2());
  }

  point_t reflect(point_t p1, point_t p2)
  {
    point_t proj = project(p1, p2);
    return p2 + (proj - p2) * 2.0;
  }
};

int32_t main()
{
  double x, y;
  cin >> x >> y;
  point_t p = point_t({x, y});

  cin >> x >> y;
  point_t p1 = point_t({x, y});

  uint32_t q;
  cin >> q;
  for (uint32_t i = 0; i < q; i++) {
    double x, y;
    cin >> x >> y;
    point_t p2 = point_t({x, y});
    p.reflect(p1, p2).print();
  }
  return 0;
}
