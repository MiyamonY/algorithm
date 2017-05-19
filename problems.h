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

struct dobule_linked_list_tag;
typedef struct double_linked_list_tag double_linked_list_t;
extern double_linked_list_t *double_linked_list_create(void);
extern void double_linked_list_destroy(double_linked_list_t *const l);
extern bool double_linked_list_insert(double_linked_list_t *const l, int32_t data);
extern size_t double_linked_list_to_array(double_linked_list_t *const l, int32_t buf[], const size_t size);
extern bool double_linked_list_delete(double_linked_list_t *const l, int32_t data);
extern bool double_linked_list_delete_first(double_linked_list_t *const l);
extern bool double_linked_list_delete_last(double_linked_list_t *const l);

extern size_t linear_search_find(int32_t data[], size_t data_size, int32_t find[], size_t find_size);
extern size_t binary_search_find(int32_t data[], size_t data_size, int32_t find[], size_t find_size);

typedef struct dictionary_t *dictionary_t;
extern dictionary_t dictionary_create(size_t size);
extern void dictionary_destroy(dictionary_t dict);
extern bool dictionary_insert(dictionary_t dict, uint64_t data);
extern bool dictionary_search(dictionary_t dict, uint64_t data);

extern bool exhaustive_search_search(int32_t data[], size_t size, int32_t find);

typedef struct {
  double x;
  double y;
} point_t;

extern size_t koch_curve(uint32_t n, point_t a, point_t b, point_t data[]);

extern size_t merge_sort(int64_t data[], size_t len);
extern size_t partition(int32_t data[], size_t len);

typedef struct {
  int64_t num;
  char design;
} card_t;

extern void quick_sort(card_t data[], size_t len);

extern int64_t gcd(const int64_t a, const int64_t b);

#ifdef __cplusplus
}
#endif

#endif /* _PROBLEMS_H_ */
