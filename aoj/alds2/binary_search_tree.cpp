///
// File:  binary_search_tree.cpp
// Author: ymiyamoto
//
// Created on Tue Jul 11 19:30:47 2017
//

#include <cstdint>

using namespace std;

struct node_t {
  int64_t val;
  node_t *parent;
  node_t *left;
  node_t *right;
};

static node_t *root = nullptr;

static node_t *create_node(int64_t val, node_t *parent)
{
  node_t *node = new node_t;
  node->val = val;
  node->parent = parent;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}

static void insert_node(node_t *node, int64_t val)
{
  if (val < node->val) {
    node_t *left = node->left;
    if (left != nullptr) {
      insert_node(left, val);
    } else {
      node->left = create_node(val, node);
    }
  } else {
    node_t *right = node->right;
    if (right != nullptr) {
      insert_node(right, val);
    } else {
      node->right = create_node(val, node);
    }
  }
}

void binary_search_tree_insert(int64_t val)
{
  if (root == nullptr) {
    root = create_node(val, nullptr);
  } else {
    insert_node(root, val);
  }
}

static void walk(node_t *node, void (*preorder)(int64_t), void (*inorder)(int64_t), void (*postorder)(int64_t))
{
  if (node == nullptr) return;

  if (preorder != nullptr) preorder(node->val);

  walk(node->left, preorder, inorder, postorder);
  if (inorder != nullptr) inorder(node->val);

  walk(node->right, preorder, inorder, postorder);
  if (postorder != nullptr) postorder(node->val);
}

void binary_search_tree_walk(void (*preorder)(int64_t), void (*inorder)(int64_t), void (*postorder)(int64_t))
{
  walk(root, preorder, inorder, postorder);
}

static bool find(node_t *node, int64_t val)
{
  if (node == nullptr) return false;

  if (node->val == val) {
    return true;
  } else if (val < node->val) {
    return find(node->left, val);
  } else {
    return find(node->right, val);
  }
}

bool binary_search_tree_find(int64_t val)
{
  return find(root, val);
}

static node_t *next_node(node_t *node)
{
  node_t *min_node = node->right;
  while (min_node->left != nullptr) {
    min_node = min_node->left;
  }

  return min_node;
}

static void delete_node(node_t *node)
{
  if ((node->left == nullptr) && (node->right == nullptr)) {
    node_t *parent = node->parent;
    if (parent->left == node) {
      parent->left = nullptr;
    } else {
      parent->right = nullptr;
    }
    delete node;
  } else if (node->left == nullptr) {
    node_t *parent = node->parent;
    node->right->parent = parent;
    if (parent->left == node) {
      parent->left = node->right;
    } else {
      parent->right = node->right;
    }
    delete node;
  } else if (node->right == nullptr) {
    node_t *parent = node->parent;
    node->left->parent = parent;
    if (parent->left == node) {
      parent->left = node->left;
    } else {
      parent->right = node->left;
    }
    delete node;
  } else {
    node_t *node_next = next_node(node);
    node->val = node_next->val;
    delete_node(node_next);
  }
}

static void find_delete_node(node_t *node, int64_t val)
{
  if (node == nullptr) return;

  if (node->val == val) {
    delete_node(node);
  } else if (val < node->val) {
    find_delete_node(node->left, val);
  } else {
    find_delete_node(node->right, val);
  }
}

void binary_search_tree_delete(int64_t val)
{
  find_delete_node(root, val);
}

#if !defined(TEST)
#include <iostream>
#include <string>
#include <vector>

static vector<int64_t> pre;
static vector<int64_t> in;

static void print_vector(vector<int64_t> &vec)
{
  for (uint32_t i = 0; i < vec.size(); i++) {
    cout << " " << vec[i];
  }
  cout << endl;
}

static void preorder(int64_t val)
{
  pre.push_back(val);
}

static void inorder(int64_t val)
{
  in.push_back(val);
}

int32_t main()
{
  uint32_t num;
  cin >> num;

  for (uint32_t i = 0; i < num; i++) {
    string command;
    cin >> command;
    if (command[0] == 'i') {
      int64_t val;
      cin >> val;
      binary_search_tree_insert(val);
    } else if (command[0] == 'f') {
      int64_t val;
      cin >> val;
      if (binary_search_tree_find(val)) {
        cout << "yes";
      } else {
        cout << "no";
      }
      cout << endl;
    } else if (command[0] == 'd') {
      int64_t val;
      cin >> val;
      binary_search_tree_delete(val);
    } else if (command[0] == 'p') {
      pre.clear();
      in.clear();
      binary_search_tree_walk(preorder, inorder, nullptr);
      print_vector(in);
      print_vector(pre);
    }
  }

  return 0;
}
#endif
