/**
 * File:  longest_common_subsequence.c
 * Author: ymiyamoto
 *
 * Created on Mon Jun 19 11:03:04 2017
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "util.h"

#define MAX_LENGTH 1000
size_t longest_common_subsequence(char arr1[], size_t n1, char arr2[], size_t n2)
{
  size_t lcs[MAX_LENGTH + 1][MAX_LENGTH + 1];
  uint32_t i;
  for (i = 0; i <= n1; i++) {
    lcs[i][0] = 0;
  }
  for (i = 0; i <= n2; i++) {
    lcs[0][i] = 0;
  }

  uint32_t n, m;
  for (n = 1; n <= n1; n++) {
    for (m = 1; m <= n2; m++) {
      if (arr1[n - 1] == arr2[m - 1]) {
        lcs[n][m] = lcs[n - 1][m - 1] + 1;
      } else if (lcs[n - 1][m] >= lcs[n][m - 1]) {
        lcs[n][m] = lcs[n - 1][m];
      } else {
        lcs[n][m] = lcs[n][m - 1];
      }
    }
  }
  return lcs[n1][n2];
}

#if !defined(TEST)
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);
  uint32_t i;
  for (i = 0; i < num; i++) {
    char buf1[BUF_SIZE];
    char buf2[BUF_SIZE];

    scanf("%s", buf1);
    scanf("%s", buf2);
    printf("%lu\n", longest_common_subsequence(buf1, strlen(buf1), buf2, strlen(buf2)));
  }
  return 0;
}
#endif
