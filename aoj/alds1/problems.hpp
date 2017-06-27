#ifndef _PROBLEMS_HPP_
#define _PROBLEMS_HPP_

#include <array>
#include <stdbool.h>
#include <stdint.h>
#include <utility>
#include <vector>

using namespace std;

extern void graph_connected_components_init();
extern void graph_connected_components_add(uint32_t vertex, uint32_t connect_to);
extern uint32_t *graph_connected_components_connected_vertexes(uint32_t vertex);
extern void graph_connected_components_colorize();
extern bool graph_connected_components_is_connected(uint32_t index1, uint32_t index2);
typedef void (*single_source_shortest_path_callback_t)(int32_t index, int32_t weight);

#define GRAPH_MAX_SIZE 10000
extern bool single_source_shortest_path(vector<pair<int32_t, int32_t>> *graph, size_t size,
                                        single_source_shortest_path_callback_t callback);
#endif
