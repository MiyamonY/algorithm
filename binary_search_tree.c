/**
 * File:  binary_search_tree.c
 * Author: ymiyamoto
 *
 * Created on Sat May 27 15:13:13 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "problems.h"

typedef struct node_t *node_t;

struct node_t {
  int64_t key;
  node_t left;
  node_t right;
};

struct binary_search_tree_t {
  node_t top;
};

static int64_t get_key_from(node_t node)
{
  return node->key;
}

static bool is_top_exists(binary_search_tree_t t)
{
  return t->top != NULL;
}

static bool is_node_exists(node_t node)
{
  return node != NULL;
}

static void set_key_to(node_t node, int64_t key)
{
  node->key = key;
}

static int64_t get_key_form(node_t node)
{
  return node->key;
}

static node_t get_left_node(node_t node)
{
  return node->left;
}

static node_t get_right_node(node_t node)
{
  return node->right;
}

static void set_node_to_left(node_t to, node_t node)
{
  to->left = node;
}

static void set_node_to_right(node_t to, node_t node)
{
  to->right = node;
}

binary_search_tree_t binary_search_tree_create(void)
{
  binary_search_tree_t t = (binary_search_tree_t)malloc(sizeof(struct binary_search_tree_t));

  if (t == NULL) goto err;

  return t;

err:
  perror("malloc error");
  exit(1);
}

static void free_nodes(node_t node)
{
  if (is_node_exists(get_left_node(node))) {
    free_nodes(get_left_node(node));
  }

  if (is_node_exists(get_right_node(node))) {
    free_nodes(get_right_node(node));
  }

  free(node);
}

void binary_search_tree_destroy(binary_search_tree_t t)
{
  if (t != NULL) {
    if (t->top != NULL) {
      free_nodes(t->top);
    }
  }

  free(t);

  return;
}

static bool create_new_node(int64_t key, node_t *node)
{
  node_t new_node = (node_t)malloc(sizeof(struct node_t));

  if (new_node == NULL) return false;

  set_key_to(new_node, key);
  set_node_to_left(new_node, NULL);
  set_node_to_right(new_node, NULL);

  *node = new_node;

  return true;
}

static void insert_node(node_t to, node_t node)
{
  if (get_key_form(to) > get_key_from(node)) {
    if (is_node_exists(get_left_node(to))) {
      insert_node(get_left_node(to), node);
    } else {
      set_node_to_left(to, node);
    }
  } else {
    if (is_node_exists(get_right_node(to))) {
      insert_node(get_right_node(to), node);
    } else {
      set_node_to_right(to, node);
    }
  }
}

void binary_search_tree_insert(binary_search_tree_t t, int64_t key)
{
  node_t node;

  if (!create_new_node(key, &node)) goto err;

  if (t->top == NULL) {
    t->top = node;
  } else {
    insert_node(t->top, node);
  }

  return;

err:
  perror("malloc error\n");
  binary_search_tree_destroy(t);
  exit(1);
}

typedef enum {
  PREORDER,
  INORDER,
} order_type_t;

static size_t order(order_type_t type, node_t node, binary_search_tree_callback_t callback)
{
  size_t count = 0;
  if (type == PREORDER) {
    callback(get_key_from(node));
    count++;
  }

  if (is_node_exists(get_left_node(node))) {
    count += order(type, node->left, callback);
  }

  if (type == INORDER) {
    callback(get_key_from(node));
    count++;
  }

  if (is_node_exists(get_right_node(node))) {
    count += order(type, node->right, callback);
  }

  return count;
}

size_t binary_search_tree_preorder(binary_search_tree_t t, binary_search_tree_callback_t callback)
{
  if (is_top_exists(t)) {
    return order(PREORDER, t->top, callback);
  }

  return 0;
}

size_t binary_search_tree_inorder(binary_search_tree_t t, binary_search_tree_callback_t callback)
{
  if (is_top_exists(t)) {
    return order(INORDER, t->top, callback);
  }

  return 0;
}
