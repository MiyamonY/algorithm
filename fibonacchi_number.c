/**
 * File:  fibonacchi_number.c
 * Author: ymiyamoto
 *
 * Created on Mon Jun 19 09:53:05 2017
 */

#include <stdbool.h>
#include <stdint.h>

#include "problems.h"

#define MEM_SIZE 500
static int64_t fib_mem[MEM_SIZE];

int64_t fibonacchi_number(int64_t n)
{
  static bool initialized = false;
  if (!initialized) {
    uint32_t i;
    for (i = 0; i < MEM_SIZE; i++) {
      fib_mem[i] = -1;
    }
    initialized = true;
  }

  if (n == 0)
    return fib_mem[n] = 1;
  else if (n == 1)
    return fib_mem[n] = 1;
  else {
    if (fib_mem[n] != -1)
      return fib_mem[n];
    else
      return fib_mem[n] = fibonacchi_number(n - 1) + fibonacchi_number(n - 2);
  }
}

#if !defined(TEST)
#include <stdio.h>
int32_t main(void)
{
  int32_t n;
  scanf("%d", &n);
  printf("%ld\n", fibonacchi_number(n));
  return 0;
}
#endif
