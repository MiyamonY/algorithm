/**
 * File:  util.h
 * Author: ymiyamoto
 *
 * Created on Sat Apr 22 05:01:59 2017
 */

#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UTIL_ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#define UTIL_SWAP(x, y)                                                                                                                    \
  do {                                                                                                                                     \
    typeof(x) _a = x;                                                                                                                      \
    x = y;                                                                                                                                 \
    y = _a;                                                                                                                                \
  } while (0)

#define UTIL_PRINT_ARRAY(arr, size)                                                                                                        \
  do {                                                                                                                                     \
    uint16_t i;                                                                                                                            \
    for (i = 0; i < size; i++) {                                                                                                           \
      if (i != 0) printf(" ");                                                                                                             \
      printf("%d", arr[i]);                                                                                                                \
    }                                                                                                                                      \
    printf("\n");                                                                                                                          \
  } while (0)

#ifdef __cplusplus
}
#endif

#endif /* _UTIL_H_ */
