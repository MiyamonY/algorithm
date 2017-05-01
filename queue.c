/**
 * File:  queue.c
 * Author: ymiyamoto
 *
 * Created on Sat Apr 29 11:59:50 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "problems.h"

struct queue_tag {
  uint8_t *data;
  size_t size;
  size_t top;
  size_t buttom;
  size_t max_size;
};

queue_t *queue_create(const size_t len)
{
  queue_t *q = (queue_t *)malloc(sizeof(queue_t));
  if (q == NULL) goto err;

  q->data = (uint8_t *)malloc(len);
  if (q->data == NULL) goto err;

  q->size = 0;
  q->top = 0;
  q->buttom = 0;
  q->max_size = len;

  return q;

err:
  perror("memeory is full\n");
  exit(1);
}

void queue_destroy(queue_t *const q)
{
  if (q != NULL) {
    free(q->data);
  }
  free(q);

  return;
}

size_t queue_get_size(const queue_t *const q)
{
  if (q == NULL) {
    return 0;
  }

  return q->size;
}

static bool enqueue_check_params(queue_t *const q, size_t len)
{
  if (q == NULL) return false;

  if (q->max_size < len) return false;

  if (q->max_size < (q->size + len)) return false;

  return true;
}

bool queue_enqueue(queue_t *const q, void *data, size_t len)
{
  if (!enqueue_check_params(q, len)) {
    return false;
  }

  uint32_t i;
  for (i = 0; i < len; i++) {
    q->data[q->top++] = ((uint8_t *)data)[i];
    q->top %= q->max_size;
    q->size++;
  }

  return true;
}

static bool dequeue_check_params(queue_t *const q, size_t len)
{
  if (q == NULL) return false;

  if ((int32_t)((int32_t)q->size - len) < 0) return false;

  return true;
}

bool queue_dequeue(queue_t *const q, void *data, size_t len)
{
  if (!dequeue_check_params(q, len)) {
    return false;
  }

  uint32_t i;

  for (i = 0; i < len; i++) {
    ((uint8_t *)data)[i] = q->data[q->buttom++];
    q->buttom %= q->max_size;
    q->size--;
  }

  return true;
}

#if !defined(TEST)
typedef struct {
  char name[16];
  int32_t time;
} process_t;

int32_t main(void)
{
  int32_t num = 0;
  int32_t quantum = 0;
  scanf("%d %d", &num, &quantum);

  queue_t *q = queue_create(sizeof(process_t) * 256 * 1000);

  int32_t i;
  for (i = 0; i < num; i++) {
    process_t process;
    scanf("%s %d", process.name, &process.time);
    queue_enqueue(q, (void *)&process, sizeof(process));
  }

  int32_t elapsed = 0;
  while (queue_get_size(q)) {
    process_t process;
    queue_dequeue(q, (void *)&process, sizeof(process));
    if ((process.time - quantum) <= 0) {
      elapsed += process.time;
      printf("%s %d\n", process.name, elapsed);
    } else {
      process.time -= quantum;
      queue_enqueue(q, (void *)&process, sizeof(process));
      elapsed += quantum;
    }
  }
  queue_destroy(q);
  return 0;
}
#endif
