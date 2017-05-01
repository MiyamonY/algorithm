/**
 * File:  problems.h
 * Author: ymiyamoto
 *
 * Created on Sat Apr 22 05:14:19 2017
 */

#ifndef _PROBLEMS_H_
#define _PROBLEMS_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void insertion_sort(uint8_t buf[], size_t size);
extern uint32_t bubble_sort(int32_t buf[], size_t size);
extern uint32_t selection_sort(int32_t buf[], size_t size);
extern uint32_t stable_bubble_sort(char *const buf[], const size_t size);
extern uint32_t stable_selection_sort(char *const buf[], const size_t size);

struct stack_tag;
typedef struct stack_tag stack_t;
extern stack_t *stack_create(const size_t len);
extern void stack_destroy(stack_t *const stack);
extern size_t stack_get_size(const stack_t *const stack);
extern bool stack_push(stack_t *const stack, const int32_t data);
extern bool stack_pop(stack_t *const stack, int32_t *const data);

struct queue_tag;
typedef struct queue_tag queue_t;
extern queue_t *queue_create(const size_t len);
extern void queue_destroy(queue_t *const q);
extern size_t queue_get_size(const queue_t *const q);
extern bool queue_enqueue(queue_t *const q, void *data, size_t len);
extern bool queue_dequeue(queue_t *const q, void *data, size_t len);

extern int64_t gcd(const int64_t a, const int64_t b);

#ifdef __cplusplus
}
#endif

#endif /* _PROBLEMS_H_ */
