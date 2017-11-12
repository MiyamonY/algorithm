///
// File:  cgl_7_d.cpp
// Author: ymiyamoto
//
// Created on Mon Oct 23 00:28:22 2017
//
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
#define EPS 1e-10
#define equals(x, y) (fabs(x - y) < EPS)

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

  double norm()
  {
    return sqrt(norm2());
  }

  double dot(vector_t a)
  {
    return x * a.x + y * a.y;
  }

  double cross(vector_t a)
  {
    return x * a.y - y * a.x;
  }

  vector_t operator*(double a)
  {
    return vector_t(a * x, a * y);
  }

  vector_t operator/(double a)
  {
    return vector_t(x / a, y / a);
  }

  double arg()
  {
    return atan2(y, x);
  }
};

struct point_t {
  double x;
  double y;

  point_t operator+(const point_t a)
  {
    return point_t({x + a.x, y + a.y});
  }

  void println()
  {
    cout << fixed << setprecision(10) << x << " " << y << endl;
  }

  void print()
  {
    cout << fixed << setprecision(10) << x << " " << y;
  }

  point_t operator+(const vector_t vec)
  {
    return point_t({x + vec.x, y + vec.y});
  }

  point_t operator-(const vector_t vec)
  {
    return point_t({x - vec.x, y - vec.y});
  }

  vector_t operator-(const point_t p)
  {
    return vector_t({x - p.x, y - p.y});
  }

  bool operator<(const point_t p)
  {
    return x == p.x ? y < p.y : x < p.x;
  }

  point_t project(point_t p1, point_t p2)
  {
    vector_t vec1(x - p1.x, y - p1.y);
    vector_t vec2(p2.x - x, p2.y - y);
    return point_t({x, y}) + vec1 * (vec1.dot(vec2) / vec1.norm2());
  }

  point_t reflect(point_t p1, point_t p2)
  {
    point_t proj = project(p1, p2);
    return p2 + (proj - p2) * 2.0;
  }
};

enum pos_t {
  CCLOCKWISE = -1,
  CLOCKWISE = 1,
  ONLINE_BACK = 2,
  ONLINE_FRONT = -2,
  ON_SEGMENT = 0,
};

pos_t ccw(point_t p0, point_t p1, point_t p2)
{
  if ((p1 - p0).cross(p2 - p0) > EPS) {
    return CCLOCKWISE;
  } else if ((p1 - p0).cross(p2 - p0) < -EPS) {
    return CLOCKWISE;
  } else if ((p1 - p0).dot(p2 - p0) < -EPS) {
    return ONLINE_BACK;
  } else {
    if ((p1 - p0).norm2() < (p2 - p0).norm2()) {
      return ONLINE_FRONT;
    } else {
      return ON_SEGMENT;
    }
  }
}

bool intersection(point_t p0, point_t p1, point_t p2, point_t p3)
{
  return (ccw(p0, p1, p2) * ccw(p0, p1, p3) <= 0) && (ccw(p2, p3, p0) * ccw(p2, p3, p1) <= 0);
}

struct segment_t {
  point_t a;
  point_t b;

  double distance(point_t p0)
  {
    if ((b - a).dot(p0 - a) < 0.0) {
      return (p0 - a).norm();
    } else if ((a - b).dot(p0 - b) < 0.0) {
      return (p0 - b).norm();
    } else {
      return fabs((b - a).cross(p0 - a) / (b - a).norm());
    }
  }
};

struct circle_t {
  point_t p;
  double r;

  vector<point_t> cross_points(point_t p0, point_t p1)
  {
    vector_t v = p1 - p0;
    vector_t e = v / v.norm();
    point_t pproject = p0.project(p1, p);
    double ratio = sqrt(r * r - (pproject - p).norm2());
    return {pproject + e * ratio, pproject - e * ratio};
  }
};

vector_t polar(double a, double r)
{
  return vector_t(a * cos(r), a * sin(r));
}

int32_t main()
{
  double cx, cy, r;
  cin >> cx >> cy >> r;
  circle_t c1({{cx, cy}, r});
  cin >> cx >> cy >> r;
  circle_t c2({{cx, cy}, r});

  double d = (c1.p - c2.p).norm();
  double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
  double t = (c2.p - c1.p).arg();
  vector<point_t> points({c1.p + polar(c1.r, t + a), c1.p + polar(c1.r, t - a)});

  sort(points.begin(), points.end());
  points[0].print();
  cout << " ";
  points[1].println();

  return 0;
}