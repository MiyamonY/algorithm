/**
 * File:  problems.h
 * Author: ymiyamoto
 *
 * Created on Sat Apr 22 05:14:19 2017
 */

#ifndef _PROBLEMS_H_
#define _PROBLEMS_H_

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

extern int64_t gcd(const int64_t a, const int64_t b);
#ifdef __cplusplus
}
#endif

#endif /* _PROBLEMS_H_ */
