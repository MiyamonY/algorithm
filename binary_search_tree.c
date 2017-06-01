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
  node_t parent;
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

static node_t get_parent_from(node_t node)
{
  return node->parent;
}

static void set_node_to_left(node_t to, node_t node)
{
  to->left = node;
}

static void set_node_to_right(node_t to, node_t node)
{
  to->right = node;
}

static void set_node_parent(node_t node, node_t parent)
{
  node->parent = parent;
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
    if (is_node_exists(t->top)) {
      free_nodes(t->top);
    }
    free(t);
  }

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

static void insert_node(node_t parent, node_t node)
{
  if (get_key_form(parent) > get_key_from(node)) {
    if (is_node_exists(get_left_node(parent))) {
      insert_node(get_left_node(parent), node);
    } else {
      set_node_to_left(parent, node);
      set_node_parent(node, parent);
    }
  } else {
    if (is_node_exists(get_right_node(parent))) {
      insert_node(get_right_node(parent), node);
    } else {
      set_node_to_right(parent, node);
      set_node_parent(node, parent);
    }
  }
}

void binary_search_tree_insert(binary_search_tree_t t, int64_t key)
{
  node_t node;

  if (t == NULL) return;

  if (!create_new_node(key, &node)) goto err;

  if (!is_node_exists(t->top)) {
    t->top = node;
    set_node_parent(node, NULL);
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
  if ((t != NULL) && is_top_exists(t)) {
    return order(PREORDER, t->top, callback);
  }

  return 0;
}

size_t binary_search_tree_inorder(binary_search_tree_t t, binary_search_tree_callback_t callback)
{
  if ((t != NULL) && is_top_exists(t)) {
    return order(INORDER, t->top, callback);
  }

  return 0;
}

static node_t find_node_by_key(node_t node, int64_t key)
{
  if (!is_node_exists(node)) return NULL;

  int64_t node_key = get_key_from(node);
  if (node_key == key) {
    return node;
  } else if (key < node_key) {
    return find_node_by_key(get_left_node(node), key);
  } else {
    return find_node_by_key(get_right_node(node), key);
  }
}

bool binary_search_tree_find(binary_search_tree_t t, int64_t key)
{
  if ((t != NULL) && is_top_exists(t)) {
    node_t found = find_node_by_key(t->top, key);
    return found != NULL;
  }
  return false;
}

static void delete_leaf(binary_search_tree_t t, node_t leaf)
{
  node_t parent = get_parent_from(leaf);
  if (!is_node_exists(parent)) {
    t->top = NULL;
  } else {
    if (get_left_node(parent) == leaf) {
      set_node_to_left(parent, NULL);
    } else {
      set_node_to_right(parent, NULL);
    }
  }
  free(leaf);
}

static node_t get_minimum_node(node_t node)
{
  node_t left_child = get_left_node(node);

  if (is_node_exists(left_child)) {
    return get_minimum_node(left_child);
  }
  return node;
}

static node_t get_successor(node_t node)
{
  node_t right_child = get_right_node(node);
  if (is_node_exists(right_child)) {
    return get_minimum_node(right_child);
  }
  return node;
}

static bool tree_delete(binary_search_tree_t t, node_t top_node, int64_t key)
{
  node_t delete_node = find_node_by_key(top_node, key);

  if (delete_node == NULL) return false;

  node_t parent = get_parent_from(delete_node);
  node_t right_child = get_right_node(delete_node);
  node_t left_child = get_left_node(delete_node);
  if (is_node_exists(left_child) && is_node_exists(right_child)) {
    node_t successor = get_successor(delete_node);
    set_key_to(delete_node, successor->key);
    tree_delete(t, successor, successor->key);
  } else if (is_node_exists(left_child)) {
    if (get_left_node(parent) == delete_node) {
      set_node_to_left(parent, left_child);
    } else {
      set_node_to_right(parent, left_child);
    }
    set_node_parent(left_child, parent);
    free(delete_node);
  } else if (is_node_exists(right_child)) {
    if (get_left_node(parent) == delete_node) {
      set_node_to_left(parent, right_child);
    } else {
      set_node_to_right(parent, right_child);
    }
    set_node_parent(right_child, parent);
    free(delete_node);
  } else {
    delete_leaf(t, delete_node);
  }

  return true;
}

bool binary_search_tree_delete(binary_search_tree_t t, int64_t key)
{
  if (is_top_exists(t)) {
    return tree_delete(t, t->top, key);
  }
  return false;
}

#if !defined(TEST)
static void print_callback(int64_t data)
{
  printf(" %ld", data);
}

int32_t main(void)
{
  binary_search_tree_t t = binary_search_tree_create();

  uint32_t num;
  scanf("%u", &num);
  uint32_t i;

  for (i = 0; i < num; i++) {
    char command[10];

    scanf("%s", command);
    if (command[0] == 'i') {
      int64_t data;
      scanf("%ld", &data);
      binary_search_tree_insert(t, data);
    } else if (command[0] == 'f') {
      int64_t data;
      scanf("%ld", &data);
      bool ret = binary_search_tree_find(t, data);
      if (ret) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    } else if (command[0] == 'd') {
      int64_t data;
      scanf("%ld", &data);
      binary_search_tree_delete(t, data);
    } else {
      binary_search_tree_inorder(t, print_callback);
      printf("\n");
      binary_search_tree_preorder(t, print_callback);
      printf("\n");
    }
  }

  binary_search_tree_destroy(t);

  return 0;
}
#endif
