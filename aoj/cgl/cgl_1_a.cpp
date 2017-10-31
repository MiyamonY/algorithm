///
// File:  cgl_1_a.cpp
// Author: ymiyamoto
//
// Created on Sun Oct 22 19:02:33 2017
//

#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace std;

struct vector_t;

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
};

struct vector_t {
  double x;
  double y;

  vector_t(double a, double b) : x(a), y(b)
  {
  }
  vector_t(point_t a, point_t b) : x(a.x - b.x), y(a.y - b.y)
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

  point_t operator+(point_t p)
  {
    return point_t({x + p.x, y + p.y});
  }
};

int32_t main()
{
  double x, y;
  cin >> x >> y;
  point_t p1 = point_t({x, y});

  cin >> x >> y;
  point_t p2 = point_t({x, y});

  vector_t vec(p1, p2);

  uint32_t q;
  cin >> q;
  for (uint32_t i = 0; i < q; i++) {
    double x, y;
    cin >> x >> y;
    vector_t v(point_t({x, y}), p1);
    (vec * (vec.cross(v) / vec.norm2()) + p1).print();
  }
  return 0;
}
