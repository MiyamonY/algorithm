///
// File:  problems.hpp
// Author: ymiyamoto
//
// Created on Wed Jun 28 01:53:47 2017
//
#pragma once

#include <cstdint>
#include <string>
#include <vector>

using namespace std;

extern int maximum_profit(vector<int32_t> &vec);
extern void insersion_sort(int32_t array[], size_t size, void (*callback)(int32_t arrary[], size_t size));
extern void bubble_sort(int32_t array[], size_t size, void (*callback)(int32_t arrary[], size_t size));
extern void selection_sort(int32_t array[], size_t size, void (*callback)(int32_t arrary[], size_t size));
extern void stable_sort_bubble_sort(pair<int32_t, uint8_t> array[], size_t size);
extern void stable_sort_selection_sort(pair<int32_t, uint8_t> array[], size_t size);
extern void shell_sort(int32_t array[], size_t size, void (*callback)(int32_t array[], uint32_t index, uint32_t index2));
extern void stack_push(int32_t data);
extern bool stack_pop(int32_t &data);

struct process_t {
  string name;
  uint32_t time;
  bool operator==(const process_t &p1) const
  {
    return (p1.name == this->name) && (p1.time == this->time);
  }
};
extern bool queue_dequeue(process_t &process);
extern void queue_enqueue(process_t process);
extern bool queue_empty();

struct double_linked_list_t;
extern double_linked_list_t *double_linked_list_create();
extern void double_linked_list_destroy(double_linked_list_t *list);
extern void double_linked_list_insert(double_linked_list_t *list, uint32_t val);
extern void double_linked_list_delete(double_linked_list_t *list, uint32_t val);
extern void double_linked_list_iter(double_linked_list_t *list, void (*callback)(uint32_t));
extern void double_linked_list_delete_first(double_linked_list_t *list);
extern void double_linked_list_delete_last(double_linked_list_t *list);
extern void areas_on_cross_section_diagram_init();
extern void areas_on_cross_section_diagram_add(char c);
extern size_t areas_on_cross_section_diagram_total();
extern void areas_on_cross_section_diagram_areas(void (*callback)(size_t));
extern size_t linear_search(uint32_t s[], size_t size_s, uint32_t t[], size_t size_t);
extern size_t binary_search(uint32_t array[], size_t size, uint32_t v);
extern void dictionary_init();
extern void dictionary_insert(char str[]);
extern bool dictionary_find(char str[]);
extern size_t allocation_load_capcity(vector<uint32_t> baggages, int64_t capacity, uint32_t tracks);
extern size_t allocation_max_load_capcity(vector<uint32_t> baggages, uint32_t tracks);
extern bool exausitve_search_search(vector<uint32_t> vec, int32_t val);
extern void koch_curve(vector<pair<double, double>> &vec, uint32_t num);
extern void merge_sort_merge(uint32_t array[], size_t size);
extern size_t partition(uint32_t array[], size_t start, size_t end);
extern void quick_sort_sort(uint32_t array[], size_t start, size_t end);
extern void quick_sort_merge_sort(uint32_t vec[], size_t start, size_t end);
extern void counting_sort_sort(uint32_t vec[], size_t size, uint32_t result[]);
extern uint64_t number_of_inversion(uint32_t vec[], size_t size);
extern void rooted_tree_init();
extern void rooted_tree_add(int32_t index, vector<int32_t> children);
extern void rooted_tree_info(int32_t index, int32_t &parent, vector<int32_t> &children, size_t &depth);
extern void binary_tree_init();
extern void binary_tree_add(int32_t index, int32_t left, int32_t right);
extern void binary_tree_info(int32_t index, int32_t &parent, int32_t &sibling, size_t &degree, size_t &depth, size_t &height);

extern void binary_search_tree_insert(int64_t val);
extern void binary_search_tree_walk(void (*preorder)(int64_t), void (*inorder)(int64_t), void (*postorder)(int64_t));
extern void binary_search_tree_delete(int64_t val);
