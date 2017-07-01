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
