/**
 * File:  double_linked_list.c
 * Author: ymiyamoto
 *
 * Created on Tue May  2 02:09:52 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "problems.h"
#include "util.h"

struct double_linked_list_tag {
  double_linked_list_t *prev;
  double_linked_list_t *next;
  int32_t data;
};

double_linked_list_t *double_linked_list_create(void)
{
  double_linked_list_t *l = (double_linked_list_t *)malloc(sizeof(double_linked_list_t));

  if (l == NULL) {
    perror("memory is full\n");
    exit(1);
  }

  l->prev = l;
  l->next = l;

  return l;
}

void double_linked_list_destroy(double_linked_list_t *const l)
{
  if (l == NULL) return;

  double_linked_list_t *list = l->next;

  while (l != list) {
    double_linked_list_t *next = list->next;
    free(list);
    list = next;
  }

  free(l);

  return;
}

bool double_linked_list_insert(double_linked_list_t *const l, int32_t data)
{
  if (l == NULL) return false;

  double_linked_list_t *new = (double_linked_list_t *)malloc(sizeof(double_linked_list_t));

  if (new == NULL) {
    perror("memory is full\n");
    exit(1);
  }

  l->next->prev = new;
  new->next = l->next;
  l->next = new;
  new->prev = l;
  new->data = data;

  return true;
}

static bool check_arguments(double_linked_list_t *const l, int32_t buf[], const size_t size)
{
  if (l == NULL) return false;

  if (size < 1) return false;

  if (buf == NULL) return false;

  return true;
}

size_t double_linked_list_to_array(double_linked_list_t *const l, int32_t buf[], const size_t size)
{
  if (!check_arguments(l, buf, size)) {
    return 0;
  }

  size_t count = 0;

  double_linked_list_t *list = l->next;
  while (list != l) {
    buf[count] = list->data;
    count++;
    if (size <= count) break;
    list = list->next;
  }

  return count;
}

bool double_linked_list_delete(double_linked_list_t *const l, int32_t data)
{
  if (l == NULL) return false;

  double_linked_list_t *list = l->next;

  while (list != l) {
    if (list->data == data) {
      double_linked_list_t *next = list->next;
      double_linked_list_t *prev = list->prev;
      next->prev = list->prev;
      prev->next = list->next;
      free(list);
      return true;
    }
    list = list->next;
  }

  return false;
}

bool double_linked_list_delete_first(double_linked_list_t *const l)
{
  if (l == NULL) return false;

  if (l == l->next) return false;

  double_linked_list_t *head = l->next;
  double_linked_list_t *new_head = head->next;

  l->next = new_head;
  new_head->prev = l;

  free(head);

  return true;
}

bool double_linked_list_delete_last(double_linked_list_t *const l)
{
  if (l == NULL) return false;

  if (l == l->prev) return false;

  double_linked_list_t *last = l->prev;
  double_linked_list_t *new_last = last->prev;

  new_last->next = l;
  l->prev = new_last;

  return true;
}

#if !defined(TEST)
#include <stdio.h>
#include <string.h>

#include "util.h"

int32_t main(void)
{
  double_linked_list_t *l = double_linked_list_create();

  int32_t num = 0;
  scanf("%d", &num);

  int32_t i;
  for (i = 0; i < num; i++) {
    char buf[128];
    int32_t val;
    int32_t ret = scanf("%s %d", buf, &val);
    if (ret == 2) {
      switch (buf[0]) {
      case 'i':
        double_linked_list_insert(l, val);
        break;
      case 'd':
        double_linked_list_delete(l, val);
        break;
      }
    } else {
      if (!strcmp(buf, "deleteFirst")) {
        double_linked_list_delete_first(l);
      } else {
        double_linked_list_delete_last(l);
      }
    }
  }

  int32_t result[1024 * 1024];
  size_t size = double_linked_list_to_array(l, result, UTIL_ARRAY_SIZE(result));
  UTIL_PRINT_ARRAY(result, size);

  double_linked_list_destroy(l);

  return 0;
}
#endif
