///
// File:  alds1_7_d.cpp
// Author: ymiyamoto
//
// Created on Sat Oct 14 19:07:05 2017
//

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
#define SIZE 100

struct tree_t {
  uint32_t left;
  uint32_t right;
};

static vector<uint32_t> pre;
static vector<uint32_t> in;
static vector<uint32_t> post;
static uint32_t pos;

void reconstruct(uint32_t l, uint32_t r)
{
  if (l >= r) {
    return;
  }

  uint32_t top = pre[pos];
  pos++;
  uint32_t mid = 0;
  for (uint32_t i = 0; i < in.size(); i++) {
    if (in[i] == top) {
      mid = i;
    }
  }

  reconstruct(l, mid);
  reconstruct(mid + 1, r);

  post.push_back(top);
}

int32_t main()
{
  uint32_t n;
  cin >> n;

  for (uint32_t i = 0; i < n; i++) {
    uint32_t n;
    cin >> n;
    pre.push_back(n);
  }

  for (uint32_t i = 0; i < n; i++) {
    uint32_t n;
    cin >> n;
    in.push_back(n);
  }

  reconstruct(0, pre.size());

  for (uint32_t i = 0; i < post.size(); i++) {
    if (i != 0) cout << " ";
    cout << post[i];
  }

  cout << endl;

  return 0;
}
