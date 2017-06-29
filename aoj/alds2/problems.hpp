///
// File:  problems.hpp
// Author: ymiyamoto
//
// Created on Wed Jun 28 01:53:47 2017
//
#pragma once

#include <cstdint>
#include <vector>

using namespace std;

extern int maximum_profit(vector<int32_t> &vec);
extern void insersion_sort(int32_t array[], size_t size, void (*callback)(int32_t arrary[], size_t size));
extern void bubble_sort(int32_t array[], size_t size, void (*callback)(int32_t arrary[], size_t size));
extern void selection_sort(int32_t array[], size_t size, void (*callback)(int32_t arrary[], size_t size));
extern void stable_sort_bubble_sort(pair<int32_t, uint8_t> array[], size_t size);
extern void stable_sort_selection_sort(pair<int32_t, uint8_t> array[], size_t size);
extern void shell_sort(int32_t array[], size_t size, void (*callback)(int32_t array[], uint32_t index, uint32_t index2));
