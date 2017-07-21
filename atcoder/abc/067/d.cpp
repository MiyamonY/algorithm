///
// File:  d.cpp
// Author: ymiyamoto
//
// Created on Wed Jul 19 22:24:27 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

#define GRAPH_SIZE 100001

enum status_t {
  WHITE,
  BLACK,
};

static vector<uint32_t> tree[GRAPH_SIZE];
static uint32_t distance_from1[GRAPH_SIZE];
static uint32_t distance_fromN[GRAPH_SIZE];
static status_t status[GRAPH_SIZE];

static void dist(uint32_t index, uint32_t d, void (*callback)(uint32_t i, uint32_t dist))
{
  status[index] = BLACK;
  callback(index, d);
  for (uint32_t i = 0; i < tree[index].size(); i++) {
    int32_t to = tree[index][i];
    if (status[to] != BLACK) {
      dist(to, d + 1, callback);
    }
  }
}

static void callback1(uint32_t i, uint32_t dist)
{
  distance_from1[i] = dist;
}

static void callbackN(uint32_t i, uint32_t dist)
{
  distance_fromN[i] = dist;
}

int32_t main()
{
  uint32_t num;
  cin >> num;

  for (uint32_t i = 1; i < num; i++) {
    uint32_t a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  for (uint32_t i = 1; i <= num; i++) {
    status[i] = WHITE;
    distance_from1[i] = 0;
  }
  dist(1, 0, callback1);

  for (uint32_t i = 1; i <= num; i++) {
    status[i] = WHITE;
    distance_fromN[i] = 0;
  }
  dist(num, 0, callbackN);

  uint32_t black = 0, white = 0;
  for (uint32_t i = 1; i <= num; i++) {
    if (distance_from1[i] <= distance_fromN[i]) {
      black++;
    } else {
      white++;
    }
  }

  if (white < black) {
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
  }

  return 0;
}
