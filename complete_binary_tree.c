/**
 * File:  complete_binary_tree.c
 * Author: ymiyamoto
 *
 * Created on Wed Jun  7 02:35:15 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "problems.h"

complete_binary_tree_t complete_binary_tree_create(size_t n)
{
  complete_binary_tree_t t;
  return t;
}

void complete_binary_tree_destroy(complete_binary_tree_t t)
{
}

bool complete_binary_tree_insert(complete_binary_tree_t t, int32_t data)
{
  return true;
}

complete_binary_tree_key complete_binary_tree_parent(complete_binary_tree_t t, complete_binary_tree_key key)
{
  return COMPLETE_BINARY_TREE_KEY_NONE;
}

complete_binary_tree_key complete_binary_tree_left_key(complete_binary_tree_t t, complete_binary_tree_key key)
{
  return 2;
}

complete_binary_tree_key complete_binary_tree_right_key(complete_binary_tree_t t, complete_binary_tree_key key)
{
  return 3;
}

#if !defined(TEST)
#include <stdio.h>

int64_t data[2 ^ 250];

int32_t main(void)
{
  int64_t num;
  scanf("%ld", &num);

  uint32_t i;
  for (i = 0; i < num; i++) {
    scanf("%ld", &data[i]);
  }

  for (i = 0; i < num; i++) {
    printf("node %u: key = %ld, ", i + 1, data[i]);
    if (0 < ((i + 1) / 2)) {
      printf("parent key = %ld, ", data[((i + 1) / 2) - 1]);
    }

    if (2 * (i + 1) < (num + 1)) {
      printf("left key = %ld, ", data[2 * (i + 1) - 1]);
    }

    if ((2 * (i + 1) + 1) < (num + 1)) {
      printf("right key = %ld, ", data[2 * (i + 1) + 1 - 1]);
    }
    printf("\n");
  }

  return 0;
}
#endif
