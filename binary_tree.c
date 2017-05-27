/**
 * File:  binary_tree.c
 * Author: ymiyamoto
 *
 * Created on Wed May 24 11:23:59 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "problems.h"
#include "util.h"

typedef struct {
  binary_tree_id_t parent;
  binary_tree_id_t left;
  binary_tree_id_t right;
  bool exists;
} node_t;

struct binary_tree_t {
  node_t *tree;
  size_t size;
};

static bool check_id_exists(binary_tree_t t, binary_tree_id_t id)
{
  return t->tree[id].exists;
}

static bool check_node_exists(binary_tree_id_t id)
{
  return id != BINARY_TREE_ID_NULL;
}

static binary_tree_id_t get_parent_from(binary_tree_t t, binary_tree_id_t id)
{
  return t->tree[id].parent;
}

static binary_tree_id_t get_right_child_from(binary_tree_t t, binary_tree_id_t id)
{
  return t->tree[id].right;
}

static binary_tree_id_t get_left_child_from(binary_tree_t t, binary_tree_id_t id)
{
  return t->tree[id].left;
}

static bool check_top(binary_tree_t t, binary_tree_id_t id)
{
  return check_id_exists(t, id) && !check_node_exists(t->tree[id].parent);
}

static bool find_top_element(binary_tree_t t, binary_tree_id_t *id)
{
  bool top_found = false;
  uint32_t i;
  for (i = 0; i < t->size; i++) {
    if (check_top(t, i)) {
      top_found = true;
      *id = i;
      break;
    }
  }

  return top_found;
}

binary_tree_t binary_tree_create(size_t size)
{
  binary_tree_t t = (binary_tree_t)malloc(sizeof(struct binary_tree_t));
  if (t == NULL) goto err;

  t->tree = (node_t *)malloc(sizeof(node_t) * size);
  if (t->tree == NULL) goto err;

  t->size = size;

  uint32_t i;
  for (i = 0; i < size; i++) {
    t->tree[i].parent = BINARY_TREE_ID_NULL;
    t->tree[i].exists = false;
  }
  return t;

err:
  free(t);
  perror("malloc error");
  exit(1);
}

void binary_tree_destroy(binary_tree_t t)
{
  if (t) {
    free(t->tree);
  }
  free(t);
}

bool binary_tree_insert(binary_tree_t t, binary_tree_id_t id, binary_tree_id_t left, binary_tree_id_t right)
{
  if ((t == NULL) || check_id_exists(t, id)) return false;

  if (check_node_exists(left)) {
    t->tree[left].parent = id;
  }

  if (check_node_exists(right)) {
    t->tree[right].parent = id;
  }

  t->tree[id].left = left;
  t->tree[id].right = right;
  t->tree[id].exists = true;
  return true;
}

bool binary_tree_sibling(binary_tree_t t, binary_tree_id_t id, binary_tree_id_t *sibling)
{
  if ((t == NULL) || !check_id_exists(t, id)) return false;

  binary_tree_id_t parent_id = get_parent_from(t, id);
  if (parent_id == BINARY_TREE_ID_NULL) {
    return false;
  } else {
    if (get_left_child_from(t, parent_id) == id) {
      *sibling = get_right_child_from(t, parent_id);
    } else {
      *sibling = get_left_child_from(t, parent_id);
    }
  }

  return true;
}

bool binary_tree_degree(binary_tree_t t, binary_tree_id_t id, size_t *degree)
{
  if ((t == NULL) || !check_id_exists(t, id)) return false;

  size_t count = 0;
  if (check_node_exists(get_right_child_from(t, id))) {
    count++;
  }

  if (check_node_exists(get_left_child_from(t, id))) {
    count++;
  }

  *degree = count;
  return true;
}

bool binary_tree_depth(binary_tree_t t, binary_tree_id_t id, size_t *depth)
{
  if ((t == NULL) || !check_id_exists(t, id)) return false;

  size_t count = 0;
  binary_tree_id_t parent_id = get_parent_from(t, id);
  while (parent_id != BINARY_TREE_ID_NULL) {
    count++;
    parent_id = get_parent_from(t, parent_id);
  }
  *depth = count;
  return true;
}

bool binary_tree_height(binary_tree_t t, binary_tree_id_t id, size_t *height)
{
  if ((t == NULL) || !check_id_exists(t, id)) return false;

  size_t left_height = 0;
  binary_tree_id_t left_id = get_left_child_from(t, id);
  if (check_node_exists(left_id)) {
    binary_tree_height(t, left_id, &left_height);
    left_height++;
  }

  size_t right_height = 0;
  binary_tree_id_t right_id = get_right_child_from(t, id);
  if (check_node_exists(right_id)) {
    binary_tree_height(t, right_id, &right_height);
    right_height++;
  }

  *height = UTIL_MAX(left_height, right_height);
  return true;
}

static size_t preorder(binary_tree_t t, binary_tree_id_t id, binary_tree_callback_t callback)
{
  size_t count = 0;
  callback(id);
  count++;

  binary_tree_id_t left_id = get_left_child_from(t, id);
  if (check_node_exists(left_id)) {
    count += preorder(t, left_id, callback);
  }

  binary_tree_id_t right_id = get_right_child_from(t, id);
  if (check_node_exists(right_id)) {
    count += preorder(t, right_id, callback);
  }

  return count;
}

size_t binary_tree_preorder(binary_tree_t t, binary_tree_callback_t callback)
{
  binary_tree_id_t top;

  if (!find_top_element(t, &top)) return 0;

  return preorder(t, top, callback);
}

static size_t inorder(binary_tree_t t, binary_tree_id_t id, binary_tree_callback_t callback)
{
  size_t count = 0;

  binary_tree_id_t left_id = get_left_child_from(t, id);
  if (check_node_exists(left_id)) {
    count += inorder(t, left_id, callback);
  }

  callback(id);
  count++;

  binary_tree_id_t right_id = get_right_child_from(t, id);
  if (check_node_exists(right_id)) {
    count += inorder(t, right_id, callback);
  }

  return count;
}

size_t binary_tree_inorder(binary_tree_t t, binary_tree_callback_t callback)
{
  binary_tree_id_t top;

  if (!find_top_element(t, &top)) return 0;

  return inorder(t, top, callback);
}

static size_t postorder(binary_tree_t t, binary_tree_id_t id, binary_tree_callback_t callback)
{
  size_t count = 0;

  binary_tree_id_t left_id = get_left_child_from(t, id);
  if (check_node_exists(left_id)) {
    count += postorder(t, left_id, callback);
  }

  binary_tree_id_t right_id = get_right_child_from(t, id);
  if (check_node_exists(right_id)) {
    count += postorder(t, right_id, callback);
  }

  callback(id);
  count++;

  return count;
}

size_t binary_tree_postorder(binary_tree_t t, binary_tree_callback_t callback)
{
  binary_tree_id_t top;

  if (!find_top_element(t, &top)) return 0;

  return postorder(t, top, callback);
}

#if !defined(TEST)

#define id_to_format(id) ((id) == BINARY_TREE_ID_NULL ? -1 : (int32_t)(id))

static size_t insert_nodes(binary_tree_t t)
{
  uint32_t num;
  scanf("%u", &num);

  uint32_t i;
  for (i = 0; i < num; i++) {
    binary_tree_id_t id;
    scanf("%u", &id);
    int32_t left;
    scanf("%d", &left);

    int32_t right;
    scanf("%d", &right);
    binary_tree_insert(t, id, left == -1 ? BINARY_TREE_ID_NULL : (binary_tree_id_t)left,
                       right == -1 ? BINARY_TREE_ID_NULL : (binary_tree_id_t)right);
  }

  return num;
}

static void print_tree(binary_tree_t t, size_t num)
{
  uint32_t i;
  for (i = 0; i < num; i++) {
    binary_tree_id_t parent = get_parent_from(t, i);
    binary_tree_id_t sibling;
    bool ret = binary_tree_sibling(t, i, &sibling);
    size_t degree;
    binary_tree_degree(t, i, &degree);
    size_t height;
    binary_tree_height(t, i, &height);
    size_t depth;
    binary_tree_depth(t, i, &depth);

    printf("node %u: parent = %d, sibling = %d, degree = %lu, depth = %lu, height = %lu, ", i, id_to_format(parent),
           ret ? id_to_format(sibling) : -1, degree, depth, height);
    if (parent == BINARY_TREE_ID_NULL) {
      printf("root");
    } else if (degree == 0) {
      printf("leaf");
    } else {
      printf("internal node");
    }
    printf("\n");
  }
}

static void print_id(binary_tree_id_t id)
{
  printf(" %d", id);
}

static void print_tree_walk(binary_tree_t t)
{
  printf("Preorder\n");
  binary_tree_preorder(t, print_id);
  printf("\n");

  printf("Inorder\n");
  binary_tree_inorder(t, print_id);
  printf("\n");

  printf("Postorder\n");
  binary_tree_postorder(t, print_id);
  printf("\n");
}

int32_t main(void)
{
  binary_tree_t t = binary_tree_create(25);

  size_t num = insert_nodes(t);
  // print_tree(t, num);
  print_tree_walk(t);

  binary_tree_destroy(t);

  return 0;
}
#endif
