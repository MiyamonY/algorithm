#ifndef _PROBLEMS_HPP_
#define _PROBLEMS_HPP_

#include <stdint.h>

extern void graph_connected_components_init();
extern void graph_connected_components_add(uint32_t vertex, uint32_t connect_to);
extern uint32_t *graph_connected_components_connected_vertexes(uint32_t vertex);
extern void graph_connected_components_colorize();
extern bool graph_connected_components_is_connected(uint32_t index1, uint32_t index2);

#endif
