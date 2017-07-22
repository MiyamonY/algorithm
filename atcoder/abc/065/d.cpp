///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Sat Jul 22 03:37:16 2017
//

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define TREE_SIZE 100000

struct data_t {
  uint64_t index;
  int64_t point;

  data_t(uint64_t index, int64_t point)
  {
    this->index = index;
    this->point = point;
  }

  bool operator<(const data_t &right) const
  {
    return point < right.point;
  }
};

struct vertex_t {
  uint64_t to;
  int64_t weight;

  vertex_t(uint64_t to, int64_t weight)
  {
    this->to = to;
    this->weight = weight;
  }
};

enum status_t { WHITE, GRAY, BLACK };

static vector<data_t> xs;
static vector<data_t> ys;
static vector<vertex_t> tree[TREE_SIZE];

static status_t status[TREE_SIZE];
static int64_t dist[TREE_SIZE];

static uint64_t min_dist(uint32_t num)
{
  for (uint32_t i = 0; i < num; i++) {
    status[i] = WHITE;
    dist[i] = UINT32_MAX;
  }

  uint64_t weights = 0;
  priority_queue<pair<int64_t, uint32_t>> queue;

  queue.push(make_pair(0, 0));

  while (!queue.empty()) {
    uint32_t index = queue.top().second;
    int64_t weight = -queue.top().first;
    queue.pop();

    if (status[index] != BLACK) {
      weights += weight;
      status[index] = BLACK;
      for (uint32_t i = 0; i < tree[index].size(); i++) {
        uint32_t to = tree[index][i].to;
        int64_t weight = tree[index][i].weight;
        if (status[to] != BLACK) {
          queue.push(make_pair(-weight, to));
          status[to] = GRAY;
        }
      }
    }
  }

  return weights;
}

int32_t main()
{
  uint32_t num;
  scanf("%u", &num);

  for (uint32_t i = 0; i < num; i++) {
    uint64_t x, y;
    scanf("%lu %lu", &x, &y);
    xs.push_back(data_t(i, x));
    ys.push_back(data_t(i, y));
  }

  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());

  for (uint32_t i = 0; i < num - 1; i++) {
    tree[xs[i].index].push_back(vertex_t(xs[i + 1].index, abs(xs[i].point - xs[i + 1].point)));
    tree[xs[i + 1].index].push_back(vertex_t(xs[i].index, abs(xs[i].point - xs[i + 1].point)));

    tree[ys[i].index].push_back(vertex_t(ys[i + 1].index, abs(ys[i].point - ys[i + 1].point)));
    tree[ys[i + 1].index].push_back(vertex_t(ys[i].index, abs(ys[i].point - ys[i + 1].point)));
  }

  printf("%ld\n", min_dist(num));

  return 0;
}
