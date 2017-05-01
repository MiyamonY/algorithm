/**
 * File:  test_queue.c
 * Author: ymiyamoto
 *
 * Created on Sat Apr 29 11:55:23 2017
 */

#include <criterion/criterion.h>
#include <stdint.h>

#include "problems.h"

#define QUEUE_SIZE 10

typedef struct {
  uint32_t a;
  uint8_t b;
} test_t;

static queue_t *q;

static void check_enqueue_is_success(void *data, size_t size)
{
  bool req = queue_enqueue(q, data, size);
  cr_assert(req);
  cr_assert_eq(queue_get_size(q), size);
}

static void setup(void)
{
  q = queue_create(QUEUE_SIZE);
}

static void teardown(void)
{
  queue_destroy(q);
}

TestSuite(queue, .init = setup, .fini = teardown);

Test(queue, QueueDataIsInitalzied)
{
  cr_assert_not_null(q);
}

Test(queue, QueueSizeIsZeroWhenCreated)
{
  cr_assert_eq(queue_get_size(q), 0);
}

Test(queue, QueueSizeIsIncrementedWhenEnqueued)
{
  int32_t data[2] = {1, 2};
  check_enqueue_is_success((void *)data, sizeof(data));
}

Test(queue, QueueSizeIsMax)
{
  uint8_t data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  check_enqueue_is_success((void *)data, sizeof(data));

  data[0] = 10;
  bool ret = queue_enqueue(q, data, sizeof(data));
  cr_assert_not(ret);
  cr_assert_eq(queue_get_size(q), QUEUE_SIZE);
}

Test(queue, EnqueueSizeIsOverQueueSize)
{
  uint8_t data[11] = {
      1,
  };
  bool ret = queue_enqueue(q, (void *)data, sizeof(data));
  cr_assert_not(ret);
}

Test(queue, EnqueWhenQueueIsEmpty)
{
  uint8_t data[1];
  bool ret = queue_dequeue(q, (void *)data, sizeof(data));
  cr_assert_not(ret);
}

Test(queue, EnqueueAndDequeue)
{
  int32_t data = 1;
  check_enqueue_is_success((void *)&data, sizeof(data));

  int32_t dequeued;
  bool req = queue_dequeue(q, (void *)&dequeued, sizeof(dequeued));
  cr_assert(req);
  cr_assert_eq(queue_get_size(q), 0);
  cr_assert_eq(dequeued, data, "dequeud(%d) is not data(%d)\n", dequeued, data);
}

Test(queue, EnqueAndDequeueStruct)
{
  test_t data = {.a = 3, .b = 4};
  check_enqueue_is_success((void *)&data, sizeof(test_t));

  test_t dequeued;
  bool ret = queue_dequeue(q, (void *)&dequeued, sizeof(data));
  cr_assert(ret);
  cr_assert_eq(dequeued.a, data.a);
  cr_assert_eq(dequeued.b, data.b);
  cr_assert_eq(queue_get_size(q), 0);
}

Test(queue, NotCrashWhenArgumentIsNull)
{
  queue_destroy(NULL);

  bool ret = queue_get_size(NULL);
  cr_assert_not(ret);

  uint8_t data = 1;
  ret = queue_enqueue(NULL, (void *)&data, sizeof(data));
  cr_assert_not(ret);

  ret = queue_dequeue(NULL, (void *)&data, sizeof(data));
  cr_assert_not(ret);
}
