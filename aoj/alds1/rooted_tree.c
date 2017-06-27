/**
 * File:  rooted_tree.c
 * Author: ymiyamoto
 *
 * Created on Sun May 21 23:34:09 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "problems.h"

typedef struct {
  rooted_tree_id_t parent;
  rooted_tree_id_t left_child;
  rooted_tree_id_t right_sibling;
  bool exist;
} node_t;

struct rooted_tree_t {
  size_t len;
  node_t *trees;
};

static bool check_element_exits(rooted_tree_t t, rooted_tree_id_t id)
{
  return t->trees[id].exist;
}

static bool check_parent_exists(rooted_tree_t t, rooted_tree_id_t id)
{
  return t->trees[id].parent != ROOTED_TREE_ID_NULL;
}

static rooted_tree_id_t get_parent_from(rooted_tree_t t, rooted_tree_id_t id)
{
  return t->trees[id].parent;
}

static void set_parent_to(rooted_tree_t t, rooted_tree_id_t id, rooted_tree_id_t parent)
{
  t->trees[id].parent = parent;
}

static void set_left_child_to(rooted_tree_t t, rooted_tree_id_t id, rooted_tree_id_t child)
{
  t->trees[id].left_child = child;
}

static rooted_tree_id_t get_left_child_from(rooted_tree_t t, rooted_tree_id_t id)
{
  return t->trees[id].left_child;
}

static void set_right_sibling_to(rooted_tree_t t, rooted_tree_id_t id, rooted_tree_id_t sibling)
{
  t->trees[id].right_sibling = sibling;
}

static rooted_tree_id_t get_right_sibling_from(rooted_tree_t t, rooted_tree_id_t id)
{
  return t->trees[id].right_sibling;
}

static void set_id(rooted_tree_t t, rooted_tree_id_t id)
{
  t->trees[id].exist = true;
}

static void clear_id(rooted_tree_t t, rooted_tree_id_t id)
{
  t->trees[id].exist = false;
}

rooted_tree_t rooted_tree_create(size_t size)
{
  rooted_tree_t t = malloc(sizeof(rooted_tree_t));
  if (t == NULL) goto err;

  t->len = size;
  t->trees = (node_t *)calloc(sizeof(node_t), size);

  if (t->trees == NULL) goto err;

  uint32_t i;
  for (i = 0; i < t->len; i++) {
    set_parent_to(t, i, ROOTED_TREE_ID_NULL);
    set_left_child_to(t, i, ROOTED_TREE_ID_NULL);
    set_right_sibling_to(t, i, ROOTED_TREE_ID_NULL);
    clear_id(t, i);
  }

  return t;

err:
  perror("malloc error");
  free(t);
  exit(1);
}

void rooted_tree_destroy(rooted_tree_t t)
{
  if (t) {
    free(t->trees);
  }
  free(t);
}

bool rooted_tree_insert(rooted_tree_t t, rooted_tree_id_t id, rooted_tree_id_t children[], size_t size)
{
  if ((t == NULL) || check_element_exits(t, id)) return false;

  if (size > 0) {
    set_left_child_to(t, id, children[0]);
  }

  uint32_t i;
  for (i = 0; i < size; i++) {
    rooted_tree_id_t child_id = children[i];

    if (i < (size - 1)) {
      rooted_tree_id_t righ_sibling = children[i + 1];
      set_right_sibling_to(t, child_id, righ_sibling);
    }
    set_parent_to(t, child_id, id);
  }

  set_id(t, id);

  return true;
}

bool rooted_tree_depth(rooted_tree_t t, rooted_tree_id_t id, size_t *depth)
{
  if ((t == NULL) || !check_element_exits(t, id)) return false;

  size_t count = 0;

  rooted_tree_id_t index = id;
  while (check_parent_exists(t, index)) {
    index = get_parent_from(t, index);
    count++;
  }

  *depth = count;
  return true;
}

bool rooted_tree_parent(rooted_tree_t t, rooted_tree_id_t id, rooted_tree_id_t *parent)
{
  if ((t == NULL) || !check_element_exits(t, id)) return false;

  *parent = get_parent_from(t, id);

  return true;
}

bool rooted_tree_children(rooted_tree_t t, rooted_tree_id_t id, rooted_tree_id_t *children, size_t *len)
{
  if ((t == NULL) || !check_element_exits(t, id)) return false;

  size_t count = 0;

  rooted_tree_id_t left_child = get_left_child_from(t, id);
  if (left_child != ROOTED_TREE_ID_NULL) {
    children[count] = left_child;
    count++;
    rooted_tree_id_t sibling = get_right_sibling_from(t, left_child);
    while (sibling != ROOTED_TREE_ID_NULL) {
      children[count] = sibling;
      count++;
      sibling = get_right_sibling_from(t, sibling);
    }
  }

  *len = count;
  return true;
}

#if !defined(TEST)
int32_t main(void)
{
  rooted_tree_t t = rooted_tree_create(100000);

  uint32_t num;
  scanf("%u", &num);

  uint32_t i;
  for (i = 0; i < num; i++) {
    rooted_tree_id_t id;
    scanf("%u", &id);

    uint32_t len;
    scanf("%u", &len);

    rooted_tree_id_t children[100000];

    uint32_t j;
    for (j = 0; j < len; j++) {
      scanf("%u", &children[j]);
    }
    rooted_tree_insert(t, id, children, len);
  }

  for (i = 0; i < num; i++) {
    rooted_tree_id_t parent;
    size_t depth;
    rooted_tree_parent(t, i, &parent);
    rooted_tree_depth(t, i, &depth);
    rooted_tree_id_t children[300];
    size_t len;
    rooted_tree_children(t, i, children, &len);
    printf("node %d: parent = %d, depth = %lu, ", i, parent == ROOTED_TREE_ID_NULL ? -1 : (int32_t)parent, depth);

    if (parent == ROOTED_TREE_ID_NULL) {
      printf("root, ");
    } else if (len == 0) {
      printf("leaf, ");
    } else {
      printf("internal node, ");
    }

    if (len == 0) {
      printf("[]\n");
    } else {
      printf("[");
      uint32_t j;

      for (j = 0; j < len; j++) {
        if (j != 0) printf(", ");
        printf("%d", children[j]);
      }
      printf("]\n");
    }
  }
  rooted_tree_destroy(t);

  return 0;
}
#endif
