/**
 * File:  test_queue.c
 * Author: ymiyamoto
 *
 * Created on Sat Apr 29 11:55:23 2017
 */

#include <criterion/criterion.h>
#include <stdint.h>

#include "problems.h"

/* emptyの時にpopしたらerror
   enuqueしてdequeしたら,pushしたものが出てくる
   最大の大きさの時にpushしたらerror
   空の時にdequeしたらエラー
 */

static queue_t *q;

void setup(void)
{
  q = queue_create(10);
}

void teardown(void)
{
  queue_destroy(q);
}

Test(queue, QueueSizeIsZeroWhenCreated, .init = setup, .fini = teardown)
{
  cr_assert_eq(queue_get_size(q), 0);
}

Test(queue, QueueSizeIsIncrementedWhenEnqueued, .init = setup, .fini = teardown)
{
  int32_t data[2] = {1, 2};
  queue_enqueue(q, data[2]);
  cr_assert_eq();
}
