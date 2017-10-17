///
// File:  alds1_7_a.cpp
// Author: ymiyamoto
//
// Created on Fri Oct 13 00:56:58 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const int32_t null = -1;

struct tree_t {
  int32_t parent;
  int32_t left_child;
  int32_t right_sibling;

  tree_t()
  {
    parent = null;
    left_child = null;
    right_sibling = null;
  }
};

static vector<tree_t> tree;

string children(int32_t index)
{
  if (tree[index].left_child == null) {
    return "[]";
  } else {
    string ret = "[";
    int32_t right = tree[index].left_child;
    while (right != null) {
      if (right != tree[index].left_child) ret += ", ";
      ret += to_string(right);
      right = tree[right].right_sibling;
    }

    return ret + "]";
  }
}

string name(int32_t index)
{
  if (tree[index].parent == null) {
    return "root";
  } else if (tree[index].left_child == null) {
    return "leaf";
  } else {
    return "internal node";
  }
}

uint32_t depth(uint32_t index)
{
  uint32_t count = 0;
  int32_t parent = tree[index].parent;
  while (parent != null) {
    count += 1;
    parent = tree[parent].parent;
  }

  return count;
}

int32_t main()
{
  uint32_t n;
  cin >> n;

  tree.resize(n);

  for (uint32_t i = 0; i < tree.size(); i++) {
    int32_t id, k;
    cin >> id >> k;

    vector<int32_t> children;
    for (int32_t j = 0; j < k; j++) {
      int32_t c;
      cin >> c;
      children.push_back(c);
      tree[c].parent = id;

      if (j == 0) {
        tree[id].left_child = children[j];
      }
    }

    for (uint32_t j = 0; j + 1 < children.size(); j++) {
      tree[children[j]].right_sibling = children[j + 1];
    }
  }

  for (int32_t i = 0; i < (int32_t)tree.size(); i++) {
    cout << "node " << i << ": parent = " << tree[i].parent << ", ";
    cout << "depth = " << depth(i) << ", " << name(i) << ", ";
    cout << children(i) << endl;
  }

  return 0;
}
