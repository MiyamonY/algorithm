///
// File:  test_queue.cpp
// Author: ymiyamoto
//
// Created on Fri Jun 30 07:02:22 2017
//

#include <cstdint>

#include <criterion/criterion.h>

#include "problems.hpp"

using namespace std;

TestSuite(Queue);

Test(Queue, EnqueueDequeue)
{
  process_t process;
  cr_assert_not(queue_dequeue(process));
  process_t p1 = {.name = "p1", .time = 100};
  process_t p2 = {.name = "p2", .time = 300};
  queue_enqueue(p1);
  queue_enqueue(p2);
  cr_assert(queue_dequeue(process));
  cr_assert_eq(p1, process);
  cr_assert(queue_dequeue(process));
  cr_assert_eq(p2, process);
}

Test(Queue, QueueIsEmpty)
{
  cr_assert(queue_empty());
  process_t p1 = {.name = "p1", .time = 100};
  queue_enqueue(p1);
  cr_assert_not(queue_empty());
  process_t p;
  queue_dequeue(p);
  cr_assert(queue_empty());
}
