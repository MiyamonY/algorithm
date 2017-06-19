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
extern bool quick_sort_is_stable(card_t cards[], size_t len);

typedef struct counting_sort_t *counting_sort_t;
extern counting_sort_t counting_sort_create(size_t n);
extern void counting_sort_destroy(counting_sort_t c);
extern void counting_sort(counting_sort_t c, uint64_t data[], size_t len);

typedef struct rooted_tree_t *rooted_tree_t;
typedef uint32_t rooted_tree_id_t;
#define ROOTED_TREE_ID_NULL ((rooted_tree_id_t)0xFFFFFFFF)
extern rooted_tree_t rooted_tree_create(size_t size);
extern void rooted_tree_destroy(rooted_tree_t t);
extern bool rooted_tree_insert(rooted_tree_t t, rooted_tree_id_t id, rooted_tree_id_t children[], size_t size);
extern bool rooted_tree_depth(rooted_tree_t t, rooted_tree_id_t id, size_t *depth);
extern bool rooted_tree_parent(rooted_tree_t t, rooted_tree_id_t id, rooted_tree_id_t *parent);
extern bool rooted_tree_children(rooted_tree_t t, rooted_tree_id_t id, rooted_tree_id_t *children, size_t *len);

typedef struct binary_tree_t *binary_tree_t;
typedef uint32_t binary_tree_id_t;
#define BINARY_TREE_ID_NULL ((binary_tree_id_t)0xFFFFFFFF)
extern binary_tree_t binary_tree_create(size_t size);
extern void binary_tree_destroy(binary_tree_t t);
extern bool binary_tree_insert(binary_tree_t t, binary_tree_id_t id, binary_tree_id_t right, binary_tree_id_t left);
extern bool binary_tree_sibling(binary_tree_t t, binary_tree_id_t id, binary_tree_id_t *sibling);
extern bool binary_tree_degree(binary_tree_t t, binary_tree_id_t id, size_t *degree);
extern bool binary_tree_depth(binary_tree_t t, binary_tree_id_t id, size_t *depth);
extern bool binary_tree_height(binary_tree_t t, binary_tree_id_t id, size_t *height);
typedef void (*binary_tree_callback_t)(binary_tree_id_t);
extern size_t binary_tree_preorder(binary_tree_t t, binary_tree_callback_t callback);
extern size_t binary_tree_inorder(binary_tree_t t, binary_tree_callback_t callback);
extern size_t binary_tree_postorder(binary_tree_t t, binary_tree_callback_t callback);

typedef struct binary_search_tree_t *binary_search_tree_t;
typedef void (*binary_search_tree_callback_t)(int64_t);
extern binary_search_tree_t binary_search_tree_create(void);
extern void binary_search_tree_destroy(binary_search_tree_t t);
extern void binary_search_tree_insert(binary_search_tree_t t, int64_t data);
extern size_t binary_search_tree_preorder(binary_search_tree_t t, binary_search_tree_callback_t callback);
extern size_t binary_search_tree_inorder(binary_search_tree_t t, binary_search_tree_callback_t callback);
extern bool binary_search_tree_find(binary_search_tree_t t, int64_t data);
extern bool binary_search_tree_delete(binary_search_tree_t t, int64_t data);

typedef struct complete_binary_tree_t *complete_binary_tree_t;
typedef int64_t complete_binary_tree_key;
#define COMPLETE_BINARY_TREE_KEY_NONE -1
extern complete_binary_tree_t complete_binary_tree_create(size_t n);
extern void complete_binary_tree_destroy(complete_binary_tree_t t);
extern bool complete_binary_tree_insert(complete_binary_tree_t t, int32_t data);
extern complete_binary_tree_key complete_binary_tree_parent(complete_binary_tree_t t, complete_binary_tree_key key);
extern complete_binary_tree_key complete_binary_tree_left_key(complete_binary_tree_t t, complete_binary_tree_key key);
extern complete_binary_tree_key complete_binary_tree_right_key(complete_binary_tree_t t, complete_binary_tree_key key);

extern void maximum_heap_build(int64_t arr[], size_t len);

extern int64_t fibonacchi_number(int64_t num);

extern int64_t gcd(const int64_t a, const int64_t b);

#ifdef __cplusplus
}
#endif

#endif /* _PROBLEMS_H_ */
