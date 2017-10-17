///
// File:  alds1_7_b.cpp
// Author: ymiyamoto
//
// Created on Sat Oct 14 16:06:54 2017
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define NIL -1
#define SIZE 100

struct tree_t {
  int32_t right;
  int32_t left;
  int32_t parent;

  tree_t()
  {
    parent = NIL;
  }
};

static tree_t tree[SIZE];

int32_t sibling(int32_t index)
{
  if (tree[index].parent == NIL) {
    return NIL;
  }

  int32_t parent = tree[index].parent;
  if (tree[parent].left != index) {
    return tree[parent].left;
  } else {
    return tree[parent].right;
  }
}

int32_t degree(int32_t index)
{
  return (tree[index].left != NIL) + (tree[index].right != NIL);
}

int32_t depth(int32_t index)
{
  int32_t parent = tree[index].parent;
  int32_t count = 0;
  while (parent != NIL) {
    count++;
    parent = tree[parent].parent;
  }

  return count;
}

int32_t height(int32_t index)
{
  if (index == NIL || (tree[index].left == NIL && tree[index].right == NIL)) {
    return 0;
  } else {
    return 1 + max(height(tree[index].left), height(tree[index].right));
  }
}

string name(int32_t index)
{
  if (tree[index].parent == NIL) {
    return "root";
  } else if (tree[index].left != NIL || tree[index].right != NIL) {
    return "internal node";
  } else {
    return "leaf";
  }
}

int32_t main()
{
  int32_t n;
  cin >> n;

  for (int32_t i = 0; i < n; i++) {
    int32_t id, left, right;
    cin >> id >> left >> right;
    tree[id].left = left;
    tree[id].right = right;
    tree[left].parent = id;
    tree[right].parent = id;
  }

  for (int32_t i = 0; i < n; i++) {
    cout << "node " << i << ": parent = " << tree[i].parent << ", ";
    cout << "sibling = " << sibling(i) << ", degree = " << degree(i) << ", ";
    cout << "depth = " << depth(i) << ", height = " << height(i) << ", ";
    cout << name(i) << endl;
  }

  return 0;
}
