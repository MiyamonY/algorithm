/**
 * File:  queue.c
 * Author: ymiyamoto
 *
 * Created on Sat Apr 29 11:59:50 2017
 */

#include <stdint.h>
#include <stdlib.h>

#include "problems.h"

struct queue_tag {
};

queue_t *queue_create(const size_t len)
{
  queue_t *q;

  return q;
}

size_t queue_get_size(const queue_t *const q)
{
  return 0;
}

void queue_destroy(const queue_t *q)
{
  q = NULL;
  return;
}

#if !defined(TEST)
int32_t main(void)
{
  return 0;
}
#endif
