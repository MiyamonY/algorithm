///
// File:  binary_tree.cpp
// Author: ymiyamoto
//
// Created on Mon Jul 10 00:40:04 2017
//

#include <algorithm>
#include <cstdint>

using namespace std;

struct node_t {
  int32_t parent;
  int32_t left;
  int32_t right;
};

#define TREE_SIZE 10000

node_t trees[TREE_SIZE];

void binary_tree_init()
{
  for (uint32_t i = 0; i < TREE_SIZE; i++) {
    trees[i].parent = -1;
    trees[i].left = -1;
    trees[i].right = -1;
  }
}

void binary_tree_add(int32_t index, int32_t left, int32_t right)
{
  trees[index].left = left;
  trees[index].right = right;
  trees[left].parent = index;
  trees[right].parent = index;
}

static size_t node_depth(int32_t index)
{
  int32_t parent = trees[index].parent;
  size_t depth = 0;
  while (parent != -1) {
    depth++;
    parent = trees[parent].parent;
  }

  return depth;
}

static size_t node_height(int32_t index)
{
  int32_t left = trees[index].left;
  int32_t right = trees[index].right;

  size_t lheight = 0, rheight = 0;
  if (left != -1) {
    lheight = node_height(left) + 1;
  }

  if (right != -1) {
    rheight = node_height(right) + 1;
  }

  return max(lheight, rheight);
}

void binary_tree_info(int32_t index, int32_t &parent, int32_t &sibling, size_t &degree, size_t &depth, size_t &height)
{
  parent = trees[index].parent;

  sibling = -1;
  if (parent != -1) {
    int32_t left = trees[parent].left;
    int32_t right = trees[parent].right;
    if (index == left) {
      sibling = right;
    } else {
      sibling = left;
    }
  }

  degree = 0;
  if (trees[index].left != -1) degree++;
  if (trees[index].right != -1) degree++;

  depth = node_depth(index);

  height = node_height(index);
}

void binary_tree_walk(int32_t index, void (*preorder)(int32_t), void (*inorder)(int32_t), void (*postorder)(int32_t))
{
  if (index == -1) return;

  if (preorder != nullptr) {
    preorder(index);
  }

  binary_tree_walk(trees[index].left, preorder, inorder, postorder);

  if (inorder != nullptr) {
    inorder(index);
  }

  binary_tree_walk(trees[index].right, preorder, inorder, postorder);

  if (postorder != nullptr) {
    postorder(index);
  }
}

#if !defined(TEST)
#include <iostream>
#include <vector>

static vector<int32_t> pre;
static vector<int32_t> in;
static vector<int32_t> post;

static void preorder(int32_t index)
{
  pre.push_back(index);
}

static void inorder(int32_t index)
{
  in.push_back(index);
}

static void postorder(int32_t index)
{
  post.push_back(index);
}

int32_t main()
{
  binary_tree_init();

  uint32_t num;
  cin >> num;

  for (uint32_t i = 0; i < num; i++) {
    int32_t index, left, right;
    cin >> index >> left >> right;
    binary_tree_add(index, left, right);
  }

#if 0
  for (uint32_t i = 0; i < num; i++) {
    int32_t parent, sibling;
    size_t degree, depth, height;
    binary_tree_info(i, parent, sibling, degree, depth, height);

    cout << "node " << i << ": parent = " << parent << ", sibling = " << sibling << ", degree = " << degree << ", depth = " << depth
         << ", height = " << height;
    if (parent == -1) {
      cout << ", root";
    } else if (degree == 0) {
      cout << ", leaf";
    } else {
      cout << ", internal node";
    }

    cout << endl;
  }
#endif

  int32_t root = 0;
  for (uint32_t i = 0; i < num; i++) {
    if (trees[i].parent == -1) {
      root = i;
      break;
    }
  }

  binary_tree_walk(root, preorder, inorder, postorder);

  cout << "Preorder" << endl;
  for (uint32_t i = 0; i < pre.size(); i++) {
    cout << " " << pre[i];
  }
  cout << endl;

  cout << "Inorder" << endl;
  for (uint32_t i = 0; i < in.size(); i++) {
    cout << " " << in[i];
  }
  cout << endl;

  cout << "Postorder" << endl;
  for (uint32_t i = 0; i < post.size(); i++) {
    cout << " " << post[i];
  }
  cout << endl;

  return 0;
}
#endif
