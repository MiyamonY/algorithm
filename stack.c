/**
 * File:  stack.c
 * Author: ymiyamoto
 *
 * Created on Fri Apr 28 12:36:58 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "problems.h"

struct stack_tag {
  int32_t *data;
  size_t max_len;
  size_t size;
};

static bool check_is_null(const void *const p)
{
  if (p == NULL) {
    return true;
  }

  return false;
}

stack_t *stack_create(const size_t len)
{
  int32_t *data = (int32_t *)malloc(sizeof(int32_t) * len);
  stack_t *stack = (stack_t *)malloc(sizeof(stack_t));

  if (check_is_null(data) || check_is_null(stack)) {
    perror("memory is full\n");
    exit(1);
  }

  stack->data = data;
  stack->size = 0;
  stack->max_len = len;
  return stack;
}

void stack_destroy(stack_t *const stack)
{
  if (stack != NULL) {
    free(stack->data);
    free(stack);
  }
}

size_t stack_get_size(const stack_t *const stack)
{
  if (check_is_null(stack)) {
    return 0;
  }

  return stack->size;
}

bool stack_push(stack_t *const stack, const int32_t data)
{
  if (check_is_null(stack)) {
    return false;
  }

  if (stack->max_len <= stack->size) {
    return false;
  }

  stack->data[stack->size] = data;
  stack->size++;
  return true;
}

bool stack_pop(stack_t *const stack, int32_t *const data)
{
  if (check_is_null(stack)) {
    return false;
  }

  if (stack->size < 1) {
    return false;
  }

  stack->size--;
  *data = stack->data[stack->size];

  return true;
}

#if !defined(TEST)
#define STACK_SIZE 256
#define BUF_SIZE 128

static int32_t stack_pop_with_check(stack_t *const stack)
{
  int32_t data;
  bool ret = stack_pop(stack, &data);
  if (!ret) {
    perror("stack is full");
    exit(1);
  }

  return data;
}

static int32_t stack_push_with_check(stack_t *const stack, int32_t data)
{
  bool ret = stack_push(stack, data);
  if (!ret) {
    perror("stack is full\n");
    exit(1);
  }

  return data;
}

int32_t main(void)
{
  char str[BUF_SIZE];

  stack_t *s = stack_create(STACK_SIZE);

  while (scanf("%s", str) != EOF) {
    if (str[0] == '-') {
      int32_t b = stack_pop_with_check(s);
      int32_t a = stack_pop_with_check(s);
      stack_push_with_check(s, a - b);
    } else if (str[0] == '+') {
      int32_t b = stack_pop_with_check(s);
      int32_t a = stack_pop_with_check(s);
      stack_push_with_check(s, a + b);
    } else if (str[0] == '*') {
      int32_t b = stack_pop_with_check(s);
      int32_t a = stack_pop_with_check(s);
      stack_push_with_check(s, a * b);
    } else {
      bool ret = stack_push(s, atoi(str));
      if (!ret) goto err;
    }
  }

  printf("%d\n", stack_pop_with_check(s));

  stack_destroy(s);

  return 0;

err:
  perror("stack is full\n");
  exit(1);
}
#endif
