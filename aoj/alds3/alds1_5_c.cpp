///
// File:  alds1_5_c.cpp
// Author: ymiyamoto
//
// Created on Mon Oct  9 10:11:20 2017
//

#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

#define PI 3.14159265

struct point_t {
  double x;
  double y;
};

vector<point_t> calc_koch(point_t a, point_t b)
{
  vector<point_t> points;
  point_t s, u, t;
  s.x = (2 * a.x + 1 * b.x) / 3;
  s.y = (2 * a.y + 1 * b.y) / 3;
  t.x = (1 * a.x + 2 * b.x) / 3;
  t.y = (1 * a.y + 2 * b.y) / 3;
  u.x = (t.x - s.x) * cos(PI / 3) - (t.y - s.y) * sin(PI / 3) + s.x;
  u.y = (t.x - s.x) * sin(PI / 3) + (t.y - s.y) * cos(PI / 3) + s.y;

  points.push_back(s);
  points.push_back(u);
  points.push_back(t);

  return points;
}

void rec(vector<point_t> &p, uint32_t n)
{
  for (uint32_t _ = 0; _ < n; _++) {
    vector<point_t> points;

    for (uint32_t i = 0; i < p.size() - 1; i++) {
      vector<point_t> new_points = calc_koch(p[i], p[i + 1]);

      points.push_back(p[i]);
      for (uint32_t i = 0; i < new_points.size(); i++) {
        points.push_back(new_points[i]);
      }
    }
    points.push_back(p.back());
    p.clear();
    for (uint32_t i = 0; i < points.size(); i++) {
      p.push_back(points[i]);
    }
  }
}

int32_t main()
{
  uint32_t n;
  cin >> n;

  vector<point_t> points;
  points.push_back({0.0, 0.0});
  points.push_back({100.0, 0.0});

  rec(points, n);

  for (uint32_t i = 0; i < points.size(); i++) {
    cout << fixed;
    cout << setprecision(8) << points[i].x << " " << points[i].y << endl;
  }

  return 0;
}
