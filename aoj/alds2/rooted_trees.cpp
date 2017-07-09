///
// File:  rooted_trees.cpp
// Author: ymiyamoto
//
// Created on Sun Jul  9 08:23:58 2017
//

#include <cstdint>
#include <vector>

using namespace std;

#define TREE_SIZE 100000

struct node_t {
  int32_t parent;
  int32_t left_child;
  int32_t right_sibling;
};

static node_t trees[TREE_SIZE];

void rooted_tree_init()
{
  for (uint32_t i = 0; i < TREE_SIZE; i++) {
    trees[i].parent = -1;
    trees[i].left_child = -1;
    trees[i].right_sibling = -1;
  }
}

void rooted_tree_add(int32_t index, vector<int32_t> children)
{
  if (children.size() > 0) {
    trees[index].left_child = children[0];

    for (uint32_t i = 0; i < children.size(); i++) {
      trees[children[i]].parent = index;
      if (i + 1 < children.size()) {
        trees[children[i]].right_sibling = children[i + 1];
      }
    }
  }
}

void rooted_tree_info(int32_t index, int32_t &parent, vector<int32_t> &children, size_t &depth)
{
  parent = trees[index].parent;

  int32_t child = trees[index].left_child;
  if (child != -1) {
    children.push_back(child);
    int32_t sibling = trees[child].right_sibling;
    while (sibling != -1) {
      children.push_back(sibling);
      sibling = trees[sibling].right_sibling;
    }
  }

  depth = 0;
  int32_t p = parent;
  while (p != -1) {
    depth++;
    p = trees[p].parent;
  }
}

#if !defined(TEST)
#include <iostream>
int32_t main()
{
  rooted_tree_init();

  uint32_t num;
  cin >> num;

  for (uint32_t i = 0; i < num; i++) {
    int32_t index, size;
    cin >> index >> size;

    vector<int32_t> children;
    for (uint32_t j = 0; j < size; j++) {
      int32_t val;
      cin >> val;
      children.push_back(val);
    }
    rooted_tree_add(index, children);
  }

  for (uint32_t i = 0; i < num; i++) {
    int32_t parent;
    size_t depth;
    vector<int32_t> children;
    rooted_tree_info(i, parent, children, depth);
    cout << "node " << i << ": parent = " << parent << ", depth = " << depth << ", ";

    if (parent == -1) {
      cout << "root, [";
    } else if (children.size() == 0) {
      cout << "leaf, [";
    } else {
      cout << "internal node, [";
    }

    for (uint32_t j = 0; j < children.size(); j++) {
      if (j != 0) cout << ", ";
      cout << children[j];
    }
    cout << "]" << endl;
  }
  return 0;
}
#endif
